#include "ast.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

ast_program::ast_program(string id, vector<ast_field_decl *> * fdl, vector<ast_method_decl *> * mdl){
    this->id = id;
    this->mdl = mdl;
    this->fdl = fdl;
}

string ast_program::get_id()
{
    return this->id;
}

vector<ast_method_decl *> * ast_program::getMdl()
{
    return this->mdl;
}

vector<ast_field_decl *> * ast_program::getFdl()
{
   return this->fdl;
}


ast_field_decl::ast_field_decl(vector<ast_id *> * id_list, Datatype type)
{
  this->type = type;
  this->id_list = id_list;
}

vector<ast_id *> * ast_field_decl::get_id_list()
{
    return this->id_list;
}

Datatype ast_field_decl::getType()
{
    return this->type;
}

ast_var_decl::ast_var_decl(vector<ast_id *> * id_list, Datatype type)
{
    this->type = type;
    this->id_list = id_list;
}

Datatype ast_var_decl::getType()
{
    return this->type;
}

vector<ast_id *> * ast_var_decl::get_id_list()
{
  return this->id_list;
}


ast_id::ast_id(string id, int size)
{
    if (size <= 0) {
        cerr << "Invalid Size" << endl;
        exit(-1);
    }

    this->id = id;
    this->size = size;
}

ast_id::ast_id(string id)
{
    this->id = id;
    this->size = 0;
}

string ast_id::get_id()
{
    return this->id;
}

int ast_id::getSize()
{
    return this->size;
}



ast_type_identifier::ast_type_identifier(string id, Datatype type)
{
    this->id = id;
    this->type = type;
}

string ast_type_identifier::get_id()
{
    return this->id;
}

Datatype ast_type_identifier::getType()
{
    return this->type;
}



ast_string_callout_arg::ast_string_callout_arg(string argument)
{
    this->argument = argument;
}

string ast_string_callout_arg::get_argument()
{
    return this->argument;
}

ast_expression_callout_arg::ast_expression_callout_arg(ast_expression * argument)
{
    this->argument = argument;
}
ast_expression * ast_expression_callout_arg::get_argument()
{
    return this->argument;
}


ast_var_location::ast_var_location(string id)
{
    this->id = id;
}
string ast_var_location::get_id()
{
    return this->id;
}


ast_array_location::ast_array_location(string id, ast_expression * index)
{
    this->id = id;
    this->index = index;
}
string ast_array_location::get_id()
{
    return this->id;
}
ast_expression * ast_array_location::get_index()
{
    return this->index;
}

ast_integer_literal_expression::ast_integer_literal_expression(int value)
{
    this->value = value;
}
int ast_integer_literal_expression::get_value()
{
    return this->value;
}


ast_char_literal_expression::ast_char_literal_expression(char value)
{
    this->value = value;
}
char ast_char_literal_expression::get_value()
{
    return this->value;
}

ast_binary_operation_expression::ast_binary_operation_expression(ast_expression * left, ast_expression * right, bin_op op)
{
    this->left = left;
    this->right = right;
    this->op = op;
}
ast_expression * ast_binary_operation_expression::get_left()
{
    return this->left;
}
ast_expression * ast_binary_operation_expression::get_right()
{
    return this->right;
}
bin_op ast_binary_operation_expression::get_op()
{
    return this->op;
}

ast_unary_operation_expression::ast_unary_operation_expression(ast_expression * expr, un_op op)
{
    this->expr = expr;
    this->op = op;
}
ast_expression * ast_unary_operation_expression::get_expr()
{
    return this->expr;
}
un_op ast_unary_operation_expression::get_op ()
{
    return this->op;
}
