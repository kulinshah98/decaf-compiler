#include "ast.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


ast_method_decl::ast_method_decl(string id, Datatype returnType, vector<ast_type_identifier *> * arguments, ast_block_statement * block)
{
    this->id = id;
    this->returnType = returnType;
    this->arguments = arguments;
    this->block = block;
}

string ast_method_decl::get_id()
{
    return this->id;
}

Datatype ast_method_decl::getReturnType()
{
    return this->returnType;
}

vector<ast_type_identifier *> * ast_method_decl::get_arguments()
{
    return this->arguments;
}

ast_block_statement * ast_method_decl::get_block()
{
    return this->block;
}



ast_normal_method::ast_normal_method(string id, vector<ast_expression *> * arguments)
{
    this->id = id;
    this->arguments = arguments;
}

string ast_normal_method::get_id()
{
    return this->id;
}

vector<ast_expression *> * ast_normal_method::get_arguments()
{
    return this->arguments;
}

ast_callout_method::ast_callout_method(string method_name, vector<ast_callout_arg *> * arguments)
{
    this->method_name = method_name;
    this->arguments = arguments;
}

string ast_callout_method::get_method_name()
{
    return this->method_name;
}

vector<ast_callout_arg *> * ast_callout_method::get_arguments()
{
    return this->arguments;
}
