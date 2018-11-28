#include "ast.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

ast_block_statement::ast_block_statement(vector<ast_statement *> * stmtlist, vector<ast_var_decl *> * id_list)
{
    this->stmtlist = stmtlist;
    this->id_list = id_list;
}

vector<ast_var_decl *> * ast_block_statement::get_id_list() {
    return this->id_list;
}

vector<ast_statement *> * ast_block_statement::getStmtlist() {
    return this->stmtlist;
}

ast_assignment_statement::ast_assignment_statement(AssignOp op, ast_location * location, ast_expression * expr)
{
   this->op = op;
   this->location = location;
   this->expr = expr;
}

AssignOp ast_assignment_statement::get_op() {
    return this->op;
}

ast_location * ast_assignment_statement::getLocation()
{
    return this->location;
}

ast_expression * ast_assignment_statement::get_expr()
{
    return this->expr;
}



ast_if_statement::ast_if_statement(ast_expression * condition, ast_block_statement * if_block, ast_block_statement * else_block)
{
    this->condition = condition;
    this->if_block = if_block;
    this->else_block = else_block;
}
ast_expression * ast_if_statement::get_condition()
{
    return this->condition;
}

ast_block_statement * ast_if_statement::getIf_block()
{
    return this->if_block;
}
ast_block_statement * ast_if_statement::getElse_block()
{
    return this->else_block;
}






ast_for_statement::ast_for_statement(ast_expression * init_condition, ast_expression * end_condition, ast_block_statement * block, string id)
{
    this->init_condition = init_condition;
    this->end_condition = end_condition;
    this->block = block;
    this->id = id;
}
string ast_for_statement::get_id()
{
    return this->id;
}
ast_expression * ast_for_statement::getInit_condition()
{
    return this->init_condition;
}
ast_expression * ast_for_statement::getEnd_condition()
{
    return this->end_condition;
}
ast_block_statement * ast_for_statement::get_block()
{
    return this->block;
}



ast_return_statement::ast_return_statement(ast_expression * expr)
{
    this->expr = expr;
}
ast_expression * ast_return_statement::get_expr()
{
    return this->expr;
}
