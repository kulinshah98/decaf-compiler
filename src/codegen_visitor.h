#ifndef _codeGenVisitor_H
#define _codeGenVisitor_H

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Pass.h>
#include <llvm/Support/raw_ostream.h>

#include <cstdlib>
#include <iostream>

#include "ast.h"
#include "symbol_table.h"
#include "visitor.h"

static llvm::LLVMContext MyGlobalContext;

class codegen_visitor : public Visitor
{
private:
    llvm::Module * module;
    ast_program * start;
    llvm::Function * mainFunction;
    symbol_table symbol_table_obj;
public:
    codegen_visitor(ast_program * start)
    {
        module = new llvm::Module(start->get_id(), MyGlobalContext);
        this->start = start;
        llvm::FunctionType *ftype = llvm::FunctionType::get(llvm::Type::getVoidTy(MyGlobalContext), false);
        mainFunction = llvm::Function::Create(ftype, llvm::GlobalValue::ExternalLinkage, "main", module);
    }

    ~codegen_visitor() {}

    void code_gen()
    {
        llvm::BasicBlock *block = llvm::BasicBlock::Create(MyGlobalContext, "entry", mainFunction, 0);
        symbol_table_obj.push_block(block);
        this->visit(start);
        block = symbol_table_obj.top_block();
        symbol_table_obj.pop_block();
        llvm::ReturnInst::Create(MyGlobalContext, block);
        llvm::verifyModule(*module);
        llvm::legacy::PassManager PM;
        PM.add(llvm::createPrintModulePass(llvm::outs()));
        PM.run(*module);
    }

    llvm::Value * ErrorHandler(const char * error)
    {
        std::cerr << error <<std::endl;
            // return 0;
        exit(-1);
    }

    void * visit(ast_program * node)
    {
        if (node->getFdl())
        {
            for(auto it = (node->getFdl())->begin() ; it != (node->getFdl())->end(); it++)
            {
                this->visit(*it);
            }
        }
        llvm::Function * iterator = NULL;
        llvm::Function * userMain = NULL;
        if (node->getMdl()) {
            for(auto it = (node->getMdl())->begin() ; it != (node->getMdl())->end(); it++)
            {
                if(module->getFunction((*it)->get_id()) && (*it)->get_id() != "main")
                {
                    return ErrorHandler("Multiple Declaration of function");
                }
                if ((*it)->get_id() == "main" && userMain)
                {
                    return ErrorHandler("Multiple Declaration of main");
                }
                iterator = static_cast<llvm::Function *>(this->visit(*it));
                if ((*it)->get_id() == "main" && !userMain)
                {
                    userMain = iterator;
                }
                if ((*it)->get_id() == "main" && (*it)->get_arguments())
                {
                    return ErrorHandler("Main cannot have any arguments");
                }
            }
        }
        if (!userMain)
            return ErrorHandler("No main Found");
        else {
            llvm::CallInst::Create(userMain, "", symbol_table_obj.top_block());
        }
        return NULL;
    }

    void * visit(ast_field_decl * node) {
        if (node->get_id_list()) {
            for(auto it = (node->get_id_list())->begin() ; it != (node->get_id_list())->end(); it++) {
                this->visit(*it);
            }
        }
        return NULL;
    }

    void * visit(ast_var_decl * node) {
        if (node->get_id_list()) {
            for(auto it = (node->get_id_list())->begin() ; it != (node->get_id_list())->end(); it++) {
                this->visit(*it);
            }
        }
        return NULL;
    }

    void * visit(ast_id * node) {
        if (node->getSize() < 0) {
            return ErrorHandler("Invalid Array Size");
        }
        if (node->getSize() == 0) {
                if(symbol_table_obj.top_block() == symbol_table_obj.bottom_block()) { // Which means that it is a global variable.
                 llvm::GlobalVariable * globalInteger = new llvm::GlobalVariable(*module, llvm::Type::getInt64Ty(MyGlobalContext), false, llvm::GlobalValue::CommonLinkage, NULL, node->get_id());
                 globalInteger->setInitializer(llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true));
                 symbol_table_obj.declare_locals(node->get_id(), globalInteger);
                 return globalInteger;
             }
             else {
                 llvm::AllocaInst * allocaInst = new llvm::AllocaInst(llvm::Type::getInt64Ty(MyGlobalContext), 0, node->get_id(), symbol_table_obj.top_block());
                 new llvm::StoreInst(llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), allocaInst, false, symbol_table_obj.top_block());
                 symbol_table_obj.declare_locals(node->get_id(), allocaInst);
                 return allocaInst;
             }
         } else {
             llvm::GlobalVariable* variable = new llvm::GlobalVariable(*module, llvm::ArrayType::get(llvm::Type::getInt64Ty(MyGlobalContext), node->getSize()), false, llvm::GlobalValue::CommonLinkage, NULL, node->get_id());
             variable->setInitializer(llvm::ConstantAggregateZero::get(llvm::ArrayType::get(llvm::Type::getInt64Ty(MyGlobalContext), node->getSize())));
             symbol_table_obj.declare_locals(node->get_id(), variable);
             return variable;
         }
     }

     llvm::Type * parseType(Datatype type) {
        switch(type) {
            case Datatype::int_type:
            return llvm::Type::getInt64Ty(MyGlobalContext);
            case Datatype::void_type:
            return llvm::Type::getVoidTy(MyGlobalContext);
            case Datatype::bool_type:
            return llvm::Type::getInt64Ty(MyGlobalContext);
        }
        return NULL;
    }

    void * visit(ast_method_decl * node) {
        std::vector<llvm::Type*> argTypes;
        if (node->get_arguments()) {
            for (auto it = (node->get_arguments())->begin(); it != (node->get_arguments())->end(); it++) {
                argTypes.push_back(parseType((*it)->getType()));
            }
        }

        llvm::FunctionType *ftype = llvm::FunctionType::get(parseType(node->getReturnType()), llvm::makeArrayRef(argTypes), false);
        llvm::Function *function = llvm::Function::Create(ftype, llvm::GlobalValue::InternalLinkage, node->get_id(), module);
        llvm::BasicBlock *block = llvm::BasicBlock::Create(MyGlobalContext, "entry", function, 0);
        symbol_table_obj.push_block(block);
        if (node->get_arguments()) {
            llvm::Function::arg_iterator it2 = function->arg_begin();
            for (auto it = (node->get_arguments())->begin(); it != (node->get_arguments())->end(); it++, it2++) {
                llvm::Value * arg = &(*it2);
                arg->setName((*it)->get_id());
                llvm::AllocaInst * allocaInst = NULL;
                allocaInst = new llvm::AllocaInst(llvm::Type::getInt64Ty(MyGlobalContext), 0, (*it)->get_id(), symbol_table_obj.top_block());
                new llvm::StoreInst(arg, allocaInst, false, symbol_table_obj.top_block());
                symbol_table_obj.declare_locals((*it)->get_id(), allocaInst);
            }
        }
            // symbol_table_obj.push_block();
        this->visit(node->get_block());
        if(!symbol_table_obj.top_block()->getTerminator()) {
            if(node->getReturnType() == Datatype::void_type)
                llvm::ReturnInst::Create(MyGlobalContext, symbol_table_obj.top_block());
            else
                llvm::ReturnInst::Create(MyGlobalContext, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), symbol_table_obj.top_block());
        }

        symbol_table_obj.pop_block();
        return function;
    }

    void * visit(ast_type_identifier * node) {
        return NULL;
    }

    void * visit(ast_statement * node) {
        llvm::BasicBlock * block = symbol_table_obj.top_block();
        if (block->getTerminator()) {
                // terminate any and all instructions which end the current block when there are still instructions to do
            llvm::Instruction * terminator = block->getTerminator();
            terminator->eraseFromParent();
        }
        ast_assignment_statement * assignmentStatement = dynamic_cast<ast_assignment_statement *>(node);
        ast_block_statement * blockStatement = dynamic_cast<ast_block_statement *>(node);
        ast_method_call * methodCall = dynamic_cast<ast_method_call *>(node);
        ast_if_statement * ifStatement = dynamic_cast<ast_if_statement *>(node);
        ast_for_statement * forStatement = dynamic_cast<ast_for_statement *>(node);
        ast_return_statement * returnStatement = dynamic_cast<ast_return_statement *>(node);
        ast_continue_statement * continueStatement = dynamic_cast<ast_continue_statement *>(node);
        ast_break_statement * breakStatement = dynamic_cast<ast_break_statement *>(node);
        if (assignmentStatement) {
            return this->visit(assignmentStatement);
        }
        if (blockStatement) {
            symbol_table_obj.push_block(NULL);
            this->visit(blockStatement);
            symbol_table_obj.pop_block();
            return NULL;
        }
        if (methodCall) {
            return this->visit(methodCall);
        }
        if (ifStatement) {
            return this->visit(ifStatement);
        }
        if (forStatement) {
            return this->visit(forStatement);
        }
        if (returnStatement) {
            return this->visit(returnStatement);
        }
        if (continueStatement) {
            return this->visit(continueStatement);
        }
        if (breakStatement) {
            return this->visit(breakStatement);
        }
        return ErrorHandler("Should Never Be Called"); // Should never be called.
    }

    void * visit(ast_expression * node) {
        ast_binary_operation_expression * binaryOperationExpression = dynamic_cast<ast_binary_operation_expression *>(node);
        ast_literal_expression * literalExpression = dynamic_cast<ast_literal_expression *>(node);
        ast_method_call * methodCall = dynamic_cast<ast_method_call *>(node);
        ast_unary_operation_expression * unaryOperationExpression = dynamic_cast<ast_unary_operation_expression *>(node);
        ast_location * location = dynamic_cast<ast_location *>(node);
        ast_callout_arg * calloutArg = dynamic_cast<ast_callout_arg *>(node);
        if (binaryOperationExpression)
            return this->visit(binaryOperationExpression);
        else if (literalExpression)
            return this->visit(literalExpression);
        else if (methodCall)
            return this->visit(methodCall);
        else if (unaryOperationExpression)
            return this->visit(unaryOperationExpression);
        else if (location)
            return this->visit(location);
        else if (calloutArg)
            return this->visit(calloutArg);
        return ErrorHandler("Should Never Be Called"); // Should never be called.
    }

    void * visit(ast_block_statement * node) {
        if(node->get_id_list()){
            for(auto it = (node->get_id_list())->begin() ; it != (node->get_id_list())->end(); it++) {
                this->visit(*it);
            }
        }
        if(node->getStmtlist()){
            for(auto it = (node->getStmtlist())->begin() ; it != (node->getStmtlist())->end(); it++) {
                this->visit(*it);
                ast_return_statement * returnStatement = dynamic_cast<ast_return_statement *>(*it);
                ast_break_statement * breakStatement = dynamic_cast<ast_break_statement *>(*it);
                ast_continue_statement * continueStatement = dynamic_cast<ast_continue_statement *>(*it);
                if (returnStatement or breakStatement or continueStatement)
                    break;
            }
        }
        return NULL;
    }

    void * visit(ast_assignment_statement * node) {
        llvm::Value * location = NULL;
        llvm::Value * existingValue = NULL;
        ast_var_location * varLocation = dynamic_cast<ast_var_location *>(node->getLocation());
        ast_array_location * arrayLocation = dynamic_cast<ast_array_location *>(node->getLocation());
        if (arrayLocation) {
            if (!symbol_table_obj.lookup_global_vars(arrayLocation->get_id())) {
                return ErrorHandler("Variable Not Declared");
            }
            std::vector <llvm::Value *> index;
            index.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true));
            index.push_back(static_cast<llvm::Value *>(this->visit(arrayLocation->get_index())));
            llvm::Value * val = symbol_table_obj.return_locals(arrayLocation->get_id());
            location = llvm::GetElementPtrInst::CreateInBounds(val, index, "tmp", symbol_table_obj.top_block());
        }
        if (varLocation) {
            if (!symbol_table_obj.lookup_global_vars(varLocation->get_id())) {
                return ErrorHandler("Variable Not Declared");
            }
            location = symbol_table_obj.return_locals(varLocation->get_id());
        }
        llvm::Value * expr = static_cast<llvm::Value *>(this->visit(node->get_expr()));
        switch(node->get_op()) {
            case AssignOp::plus_equal:
            existingValue = new llvm::LoadInst(location, "load", symbol_table_obj.top_block());
            expr = llvm::BinaryOperator::Create(llvm::Instruction::Add, existingValue, expr, "tmp", symbol_table_obj.top_block());
            break;
            case AssignOp::minus_equal:
            existingValue = new llvm::LoadInst(location, "load", symbol_table_obj.top_block());
            expr = llvm::BinaryOperator::Create(llvm::Instruction::Sub, existingValue, expr, "tmp", symbol_table_obj.top_block());
            break;
            case AssignOp::equal:
            break;
        }
        if (!expr->getType()->isIntegerTy(64)) {
            return ErrorHandler("RHS of assignment statement is invalid");
        }
        if (!location->getType()->isPointerTy()) {
            return ErrorHandler("LHS of assignment statement is invalid");
        }
        return new llvm::StoreInst(expr, location, false, symbol_table_obj.top_block());
    }

    void * visit(ast_method_call * node) {
        ast_callout_method * calloutMethod = dynamic_cast<ast_callout_method *>(node);
        ast_normal_method * normalMethod = dynamic_cast<ast_normal_method *>(node);
        if (calloutMethod)
            return this->visit(calloutMethod);
        if (normalMethod)
            return this->visit(normalMethod);
        return ErrorHandler("Should Never Be Called"); // Should never be called.
    }

    void * visit(ast_normal_method * node) {
        if (node->get_id() == "main") {
            return ErrorHandler("You can't call main");
        }
        std::vector<llvm::Value *> args;
        llvm::Function * function = module->getFunction(node->get_id());
        if (!function) {
            return ErrorHandler("No Function Defined");
        }
        if (!function->isVarArg() && (node->get_arguments()) && (function->arg_size() != node->get_arguments()->size())) {
            return ErrorHandler("Invalid Number of Arguments");
        }
        if (node->get_arguments()) {
            for (auto it = (node->get_arguments())->begin(); it != (node->get_arguments())->end(); it++) {
           args.push_back(static_cast<llvm::Value *>(this->visit(*it)));
            }
        }
        if (function->getReturnType()->isVoidTy()) {
            return llvm::CallInst::Create(function, llvm::makeArrayRef(args), "", symbol_table_obj.top_block());
        }
        return llvm::CallInst::Create(function, llvm::makeArrayRef(args), node->get_id(), symbol_table_obj.top_block());
    }

    void * visit(ast_callout_method * node) {
        llvm::Function * function = module->getFunction(node->get_method_name());
        if (!function)
        {
            llvm::FunctionType *ftype = llvm::FunctionType::get(llvm::Type::getInt64Ty(MyGlobalContext), true);
            function = llvm::Function::Create(ftype, llvm::GlobalValue::ExternalLinkage, node->get_method_name(), module);
        }
        std::vector<llvm::Value *> args;
        if (node->get_arguments())
        {
            for (auto it = (node->get_arguments())->begin(); it != (node->get_arguments())->end(); it++) {
                args.push_back(static_cast<llvm::Value *>(this->visit(*it)));
            }
        }
        llvm::CallInst *call = llvm::CallInst::Create(function, llvm::makeArrayRef(args), node->get_method_name(), symbol_table_obj.top_block());
        return call;
    }

    void * visit(ast_callout_arg * node) {
        ast_string_callout_arg * stringCalloutArg= dynamic_cast<ast_string_callout_arg *>(node);
        ast_expression_callout_arg * expressionCalloutArg = dynamic_cast<ast_expression_callout_arg *>(node);
        if (stringCalloutArg)
            return this->visit(stringCalloutArg);
        if (expressionCalloutArg)
            return this->visit(expressionCalloutArg);
        return ErrorHandler("Should Never Be Called"); // Should never be called.
    }

    void * visit(ast_string_callout_arg * node)
    {
        std::string argument = node->get_argument();
        llvm::GlobalVariable* variable = new llvm::GlobalVariable(*module, llvm::ArrayType::get(llvm::IntegerType::get(MyGlobalContext, 8), argument.size() + 1), true, llvm::GlobalValue::InternalLinkage, NULL, "string");
        variable->setInitializer(llvm::ConstantDataArray::getString(MyGlobalContext, argument, true));
        return variable;
    }

    void * visit(ast_expression_callout_arg * node) {
        return this->visit(node->get_argument());
    }

    void * visit(ast_if_statement * node) {
        llvm::BasicBlock * entryBlock = symbol_table_obj.top_block();
        llvm::Value * condition = static_cast<llvm::Value *>(this->visit(node->get_condition()));
        llvm::ICmpInst * comparison = new llvm::ICmpInst(*entryBlock, llvm::ICmpInst::ICMP_NE, condition, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), "tmp");
        llvm::BasicBlock * ifBlock = llvm::BasicBlock::Create(MyGlobalContext, "ifBlock", entryBlock->getParent());
        llvm::BasicBlock * mergeBlock = llvm::BasicBlock::Create(MyGlobalContext, "mergeBlock", entryBlock->getParent());

        llvm::BasicBlock * returnedBlock = NULL;

        symbol_table_obj.push_block(ifBlock);
        this->visit(node->getIf_block());
        returnedBlock = symbol_table_obj.top_block();
        symbol_table_obj.pop_block();
        if (!returnedBlock->getTerminator()) {
            llvm::BranchInst::Create(mergeBlock, returnedBlock);
        }
        if (node->getElse_block()) {
            llvm::BasicBlock * elseBlock = llvm::BasicBlock::Create(MyGlobalContext, "elseBlock", entryBlock->getParent());

            symbol_table_obj.push_block(elseBlock);
            this->visit(node->getElse_block());
            returnedBlock = symbol_table_obj.top_block();
            symbol_table_obj.pop_block();
            if (!returnedBlock->getTerminator()) {
                llvm::BranchInst::Create(mergeBlock, returnedBlock);
            }
            llvm::BranchInst::Create(ifBlock, elseBlock, comparison, entryBlock);
        } else {
            llvm::BranchInst::Create(ifBlock, mergeBlock, comparison, entryBlock);
        }
        auto localVariables = symbol_table_obj.get_local_variables();
        symbol_table_obj.pop_block();
        symbol_table_obj.push_block(mergeBlock);
        symbol_table_obj.set_local_variables(localVariables);
        return NULL;
    }

    void * visit(ast_for_statement * node) {
        if (!symbol_table_obj.lookup_global_vars(node->get_id())) {
            return ErrorHandler("Variable Not Declared");
        }
        llvm::BasicBlock * entryBlock = symbol_table_obj.top_block();
        llvm::BasicBlock * headerBlock = llvm::BasicBlock::Create(MyGlobalContext, "loop_header", entryBlock->getParent(), 0);
        llvm::BasicBlock * bodyBlock = llvm::BasicBlock::Create(MyGlobalContext, "loop_body", entryBlock->getParent(), 0);
        llvm::BasicBlock * afterLoopBlock = llvm::BasicBlock::Create(MyGlobalContext, "after_loop", entryBlock->getParent(), 0);

        symbol_table_obj.push_break_continue_stack(afterLoopBlock, headerBlock);

        new llvm::StoreInst(static_cast<llvm::Value *>(this->visit(node->getInit_condition())), symbol_table_obj.return_locals(node->get_id()), false, entryBlock);
        llvm::Value * val = new llvm::LoadInst(symbol_table_obj.return_locals(node->get_id()), "load", headerBlock);
        llvm::ICmpInst * comparison = new llvm::ICmpInst(*headerBlock, llvm::ICmpInst::ICMP_NE, val, static_cast<llvm::Value *>(this->visit(node->getEnd_condition())), "tmp");
        llvm::BranchInst::Create(bodyBlock, afterLoopBlock, comparison, headerBlock);
        llvm::BranchInst::Create(headerBlock, entryBlock);
        symbol_table_obj.push_block(bodyBlock);
        this->visit(node->get_block());
        bodyBlock = symbol_table_obj.top_block();
        symbol_table_obj.pop_block();
        if (!bodyBlock->getTerminator()) {
            llvm::BranchInst::Create(headerBlock, bodyBlock);
        }

        auto localVariables = symbol_table_obj.get_local_variables();
        symbol_table_obj.pop_block();
        symbol_table_obj.push_block(afterLoopBlock);
        symbol_table_obj.set_local_variables(localVariables);

        symbol_table_obj.pop_break_continue_stack();
        return NULL;
    }

    void * visit(ast_return_statement * node) {
        llvm::Function * function = symbol_table_obj.top_block()->getParent(); // Doubt full
        llvm::Type * type = function->getReturnType();
        if (type->isVoidTy()) {
            if(node->get_expr()) {
                return ErrorHandler("Unknown Return for Void Type");
            } else {
                return llvm::ReturnInst::Create(MyGlobalContext,symbol_table_obj.top_block());
            }
        } else {
            if (node->get_expr()) {
                llvm::Value * expression = static_cast<llvm::Value *>(this->visit(node->get_expr()));
                return llvm::ReturnInst::Create(MyGlobalContext, expression, symbol_table_obj.top_block());
            } else {
                return ErrorHandler("Void type return for non void function");
            }
        }
    }

    void * visit(ast_continue_statement * node) {
        llvm::BasicBlock * block = symbol_table_obj.get_continue_stack();
        if (!block) {
            return ErrorHandler("Incorrect continue usage");
        }
        llvm::BasicBlock * curBlock = symbol_table_obj.top_block();
        return llvm::BranchInst::Create(block, curBlock);
    }

    void * visit(ast_break_statement * node) {
        llvm::BasicBlock * block = symbol_table_obj.get_break_stack();
        if (!block) {
            return ErrorHandler("Incorrect break usage");
        }
        llvm::BasicBlock * curBlock = symbol_table_obj.top_block();
        auto localVariables = symbol_table_obj.get_local_variables();
        symbol_table_obj.pop_block();
        symbol_table_obj.push_block(block);
        symbol_table_obj.set_local_variables(localVariables);
        return llvm::BranchInst::Create(block, curBlock);
    }

    void * visit(ast_location * node) {
        ast_array_location * arrayLocation = dynamic_cast<ast_array_location *>(node);
        ast_var_location * varLocation = dynamic_cast<ast_var_location *>(node);
        if (arrayLocation)
            return this->visit(arrayLocation);
        if (varLocation)
            return this->visit(varLocation);
        return ErrorHandler("Should Never Be Called"); // Should never be called.
    }

    void * visit(ast_var_location * node) {
        if (!symbol_table_obj.lookup_global_vars(node->get_id())) {
            return ErrorHandler("Variable Not Declared");
        }
        llvm::Value * val = symbol_table_obj.return_locals(node->get_id());
        if (val)
            return new llvm::LoadInst(val, "tmp", symbol_table_obj.top_block());
        return ErrorHandler("Variable Not Initilized");
    }

    void * visit(ast_array_location * node) {
        if (!symbol_table_obj.lookup_global_vars(node->get_id())) {
            return ErrorHandler("Variable Not Declared");
        }
        std::vector <llvm::Value *> index;
        index.push_back(llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true));
        index.push_back(static_cast<llvm::Value *>(this->visit(node->get_index())));
        llvm::Value * val = symbol_table_obj.return_locals(node->get_id());
        llvm::Value * offset = llvm::GetElementPtrInst::CreateInBounds(val, index, "tmp", symbol_table_obj.top_block());
        if (val) {
            llvm::LoadInst * load = new llvm::LoadInst(offset, "tmp", symbol_table_obj.top_block());
            return load;
        }
        return ErrorHandler("Variable Not Initilized");
    }

    void * visit(ast_literal_expression * node) {
        ast_integer_literal_expression * integerLiteralExpression = dynamic_cast<ast_integer_literal_expression *>(node);
        ast_char_literal_expression * charLiteralExpression = dynamic_cast<ast_char_literal_expression *>(node);
        ast_true_literal_expression * trueLiteralExpression = dynamic_cast<ast_true_literal_expression *>(node);
        ast_false_literal_expression * falseLiteralExpression = dynamic_cast<ast_false_literal_expression *>(node);
        if (integerLiteralExpression) {
            return this->visit(integerLiteralExpression);
        }
        if (charLiteralExpression) {
            return this->visit(charLiteralExpression);
        }
        if (trueLiteralExpression) {
            return this->visit(trueLiteralExpression);
        }
        if (falseLiteralExpression) {
            return this->visit(falseLiteralExpression);
        }
        return ErrorHandler("Should Never Be Called"); // Should never be called.
    }

    void * visit(ast_integer_literal_expression * node) {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
    }

    void * visit(ast_char_literal_expression * node) {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
    }

    void * visit(ast_true_literal_expression * node) {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
    }

    void * visit(ast_false_literal_expression * node) {
        return llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), node->get_value(), true);
    }

    void * visit(ast_binary_operation_expression * node) {
        switch(node->get_op()) {
            case bin_op::plus_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::Add, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
            case bin_op::minus_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::Sub, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
            case bin_op::multiply_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::Mul, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
            case bin_op::divide_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::SDiv, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
            case bin_op::modulo_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::SRem, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
            case bin_op::lessthan_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SLT, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
            case bin_op::greaterthan_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SGT, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
            case bin_op::lessequal_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SLE, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
            case bin_op::greaterequal_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_SGE, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
            case bin_op::notequal_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_NE, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
            case bin_op::equalequal_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_EQ, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
            case bin_op::and_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::And, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
            case bin_op::or_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::Or, static_cast<llvm::Value*>(this->visit(node->get_left())), static_cast<llvm::Value*>(this->visit(node->get_right())), "tmp", symbol_table_obj.top_block());
        }
        return ErrorHandler("No Known BinaryOperator");
    }

    void * visit(ast_unary_operation_expression * node) {
        switch(node->get_op()) {
            case un_op::minus_op:
            return llvm::BinaryOperator::Create(llvm::Instruction::Sub, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), static_cast<llvm::Value*>(this->visit(node->get_expr())), "tmp", symbol_table_obj.top_block());
            case un_op::not_op:
            return new llvm::ZExtInst(llvm::CmpInst::Create(llvm::Instruction::ICmp, llvm::ICmpInst::ICMP_EQ, llvm::ConstantInt::get(llvm::Type::getInt64Ty(MyGlobalContext), 0, true), static_cast<llvm::Value*>(this->visit(node->get_expr())),"tmp", symbol_table_obj.top_block()), llvm::Type::getInt64Ty(MyGlobalContext), "zext", symbol_table_obj.top_block());
        }
        return ErrorHandler("No Known UnaryOperator");
    }

};

#endif
