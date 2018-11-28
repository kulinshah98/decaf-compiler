#ifndef _symbolTable_H
#define _symbolTable_H

#include <llvm/IR/BasicBlock.h>

#include <iostream>
#include <list>
#include <map>
#include <stack>

class symbol_table_node
{
public:
    llvm::BasicBlock * block;
    std::map<std::string, llvm::Value *> localVariables;

    symbol_table_node(llvm::BasicBlock * block)
    {
        this->block = block;
    }

    ~symbol_table_node() {}
};

class symbol_table
{
private:
    std::list<symbol_table_node> table;
    std::stack<std::pair<llvm::BasicBlock *, llvm::BasicBlock *>> break_continue_stack;

public:
    symbol_table() {}
    ~symbol_table() {}
    std::map<std::string, llvm::Value *> get_local_variables()
    {
        return this->table.front().localVariables;
    }

    void set_local_variables(std::map<std::string, llvm::Value *> variables) {
        this->table.front().localVariables.insert(variables.begin(), variables.end());
    }

    bool look_up_locals(std::string name) {
        auto it = this->get_local_variables();
        return it.find(name) != it.end();
    }

    void declare_locals(std::string name, llvm::Value * value) {
        if (!this->look_up_locals(name)) {
            this->table.front().localVariables.insert(std::pair<std::string, llvm::Value *>(name, value));
        } else {
            std::cerr<<"Variable "<<name<<" already declared";
            exit(0);
        }
    }

    bool lookup_global_vars(std::string name)
    {
        return this->return_locals(name) != NULL;
    }

    llvm::Value * return_locals(std::string name)
    {
        for (auto it = this->table.begin(); it != this->table.end(); it++)
        {
            auto found_or_end = it->localVariables.find(name);
            if (found_or_end != it->localVariables.end())
            {
                return found_or_end->second;
            }
        }
        return NULL;
    }

    void push_block(llvm::BasicBlock * block) {
        this->table.push_front(symbol_table_node(block));
    }

    void pop_block() {
        this->table.pop_front();
    }

    llvm::BasicBlock * top_block() {
        for (auto it = this->table.begin(); it != this->table.end(); it++) {
            if (it->block) {
                return it->block;
            }
        }
        return this->table.front().block;
    }

    llvm::BasicBlock * bottom_block()
    {
        return this->table.back().block;
    }

    void print_table()
    {
        auto i = this->table.front().localVariables;
        for (auto it = i.begin() ; it != i.end() ; it++)
        {
            std::cout << it->first;
        }
    }

    void push_break_continue_stack(llvm::BasicBlock * breakSt, llvm::BasicBlock * returnSt)
    {
        this->break_continue_stack.push(std::make_pair(breakSt, returnSt));
    }

    void pop_break_continue_stack()
    {
        this->break_continue_stack.pop();
    }

    llvm::BasicBlock * get_break_stack() {
        if (!this->break_continue_stack.empty()) {
            return this->break_continue_stack.top().first;
        }
        return NULL;
    }

    llvm::BasicBlock * get_continue_stack() {
        if (!this->break_continue_stack.empty()) {
            return this->break_continue_stack.top().second;
        }
        return NULL;
    }

};

#endif
