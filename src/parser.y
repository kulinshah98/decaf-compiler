%{
#include "ast.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" void yyerror(char *s);
extern "C" int yywrap(void){return 1;}

extern union node yylval;
extern class ast_node * start;
%}

/*
*/




%token PLUS MINUS MULT DIV MOD EQL MEQL PEQL
%token AND OR EQLEQL NEQL LT GT LEQ GEQ
%token OCUR CCUR OPAR CPAR OSQU CSQU
%token INT BOOLEAN VOID
%token CLASS PROGRAM IF ELSE FOR BREAK CONTINUE RETURN CALLOUT
%token TRUE FALSE
%token NOT SCOLON COMMA


%left PLUS MINUS MULT DIV MOD
%right EQL
%left OR AND
%left LT GT LEQ GEQ
%left EQLEQL NEQL
%right NOT
%precedence UMINUS


%token <cval> CHAR
%token <ival> INT_VAL
%token <sval> ID
%token <sval> STR
%type <assign_op> assign_op
%type <block> block
%type <callout_arg> callout_arg
%type <callout_arg_list> callout_arg_list
%type <expr> expr
%type <expr_list> expr_list
%type <field_decl> field_decl
%type <field_decl_list> field_decl_list
%type <identifier_list> identifier_list
%type <literal> literal
%type <location> location
%type <method_call> method_call
%type <method_decl> method_decl
%type <method_decl_list> method_decl_list
%type <program> program
%type <statement> statement
%type <statement_list> statement_list
%type <type> type
%type <type_identifier> type_identifier
%type <type_identifier_list> type_identifier_list
%type <var_decl> var_decl
%type <var_decl_list> var_decl_list
%type <var_or_array_identifier> var_or_array_identifier
%type <var_or_array_identifier_list> var_or_array_identifier_list


%%

program : CLASS ID OCUR field_decl_list method_decl_list CCUR {
            $$ = new ast_program(std::string($2), $4, $5); start = $$;
            //printf("program -> CLASS ID OCUR field_decl_list method_decl_list CCUR\n");
          }
        | CLASS ID OCUR field_decl_list CCUR {
            $$ = new ast_program(std::string($2), $4, NULL); start = $$;
            //printf("program -> CLASS ID OCUR field_decl_list CCUR\n");
          }
        | CLASS ID OCUR method_decl_list CCUR {
            $$ = new ast_program(std::string($2), NULL, $4); start = $$;
            //printf("program -> CLASS ID OCUR method_decl_list CCUR\n");
          }
        | CLASS ID OCUR CCUR {
            $$ = new ast_program(std::string($2), NULL, NULL); start = $$;
            //printf("program -> CLASS ID OCUR CCUR\n");
          };

field_decl_list : field_decl {
                    $$ = new std::vector<ast_field_decl *>(); $$->push_back($1);
                    //printf("field_decl_list -> field_decl\n");
                  }
                | field_decl_list field_decl {
                    $1->push_back($2); $$ = $1;
                    //printf("field_decl_list -> field_decl_list field_decl\n");
                  };

field_decl : type var_or_array_identifier_list SCOLON {
                $$ = new ast_field_decl($2, $1);
                //printf("field_decl -> type var_or_array_identifier_list SCOLON\n");
              };

var_or_array_identifier_list : var_or_array_identifier {
                                  $$ = new std::vector<ast_id *>(); $$->push_back($1);
                                  //printf("var_or_array_identifier_list -> var_or_array_identifier\n");
                                }
                             | var_or_array_identifier_list COMMA var_or_array_identifier {
                              $1->push_back($3); $$ = $1;
                              //printf("var_or_array_identifier_list -> var_or_array_identifier_list COMMA var_or_array_identifier\n");
                             };

var_or_array_identifier : ID {
                            $$ = new ast_id(std::string($1));
                            //printf("var_or_array_identifier -> ID\n");
                          }
                        | ID OSQU INT_VAL CSQU {
                            $$ = new ast_id(std::string($1), $3);
                            //printf("var_or_array_identifier -> ID OSQU INT_VAL CSQU\n");
                          }

identifier_list : ID {
                      $$ = new std::vector<ast_id *>(); $$->push_back(new ast_id(std::string($1)));
                      //printf("identifier_list -> ID\n");
                    }
                | identifier_list COMMA ID {
                    $1->push_back(new ast_id(std::string($3))); $$ = $1;
                    //printf("identifier_list -> identifier_list COMMA ID\n");
                  };

method_decl_list : method_decl {
                    $$ = new std::vector<ast_method_decl *>(); $$->push_back($1);
                    //printf("method_decl_list -> method_decl\n");
                  }
                 | method_decl_list method_decl {
                    $1->push_back($2); $$ = $1;
                    //printf("method_decl_list -> method_decl_list method_decl\n");
                  };

method_decl : type ID OPAR type_identifier_list CPAR block {
                $$ = new ast_method_decl(std::string($2), $1, $4, $6);
                //printf("method_decl -> type ID OPAR type_identifier_list CPAR block\n");
              }
            | type ID OPAR CPAR block
              {
                $$ = new ast_method_decl(std::string($2), $1, NULL, $5);
                //printf("method_decl -> type ID OPAR CPAR block\n");
              }
            | VOID ID OPAR type_identifier_list CPAR block
              {
                $$ = new ast_method_decl(std::string($2), Datatype::void_type, $4, $6);
                //printf("method_decl -> VOID ID OPAR type_identifier_list CPAR block\n");
              }
            | VOID ID OPAR CPAR block
              {
                $$ = new ast_method_decl(std::string($2), Datatype::void_type, NULL, $5);
                //printf("method_decl -> VOID ID OPAR CPAR block\n");
              };

type_identifier_list : type_identifier {
                          $$ = new std::vector<ast_type_identifier *>(); $$->push_back($1);
                          //printf("type_identifier_list -> type_identifier \n");
                        }
                     | type_identifier_list COMMA type_identifier
                        {
                          $1->push_back($3); $$ = $1;
                          //printf("type_identifier_list -> type_identifier_list COMMA type_identifier\n");
                        };

type_identifier : type ID
                  {
                    $$ = new ast_type_identifier(std::string($2), $1);
                    //printf("type_identifier -> type ID\n");
                  };

block : OCUR var_decl_list statement_list CCUR
        {
          $$ = new ast_block_statement($3, $2);
          //printf("block -> OCUR var_decl_list statement_list CCUR\n");
        }
      | OCUR var_decl_list CCUR
        {
          $$ = new ast_block_statement(NULL, $2);
          //printf("block -> OCUR var_decl_list CCUR\n");
        }
      | OCUR statement_list CCUR
        {
          $$ = new ast_block_statement($2, NULL);
          //printf("block -> OCUR statement_list CCUR\n");
        }
      | OCUR CCUR
        {
          $$ = new ast_block_statement(NULL, NULL);
          //printf("block -> OCUR CCUR\n");
        };

statement_list : statement {
                  $$ = new std::vector<ast_statement *>(); $$->push_back($1);
                  //printf("statement_list -> statement\n");
                }
               | statement_list statement {
                  $1->push_back($2); $$ = $1;
                  //printf("statement_list -> statement_list statement\n");
                };

var_decl_list : var_decl {
                  $$ = new std::vector<ast_var_decl *>(); $$->push_back($1);
                  //printf("var_decl_list -> var_decl\n");
                }
              | var_decl_list var_decl {
                  $1->push_back($2); $$ = $1;
                  //printf("var_decl_list -> var_decl_list var_decl \n");
                };

var_decl : type identifier_list SCOLON {
            $$ = new ast_var_decl($2, $1);
            //printf("var_decl -> type identifier_list SCOLON\n");
          };

type : INT {
        $$ = Datatype::int_type;
        //printf("type -> INT\n");
      }
     | BOOLEAN {
        $$ = Datatype::bool_type;
        //printf("type -> BOOLEAN\n");
      };

statement : SCOLON { $$ = NULL; }
          | location assign_op expr SCOLON {
              $$ = new ast_assignment_statement($2, $1, $3);
              //printf("statement -> location assign_op expr SCOLON\n");
            }
          | method_call SCOLON {
              $$ = $1;
              //printf("statement -> method_call SCOLON\n");
            }
          | IF OPAR expr CPAR block ELSE block {
              $$ = new ast_if_statement($3, $5, $7);
              //printf("statement -> IF OPAR expr CPAR block ELSE block\n");
            }
          | IF OPAR expr CPAR block {
              $$ = new ast_if_statement($3, $5, NULL);
              //printf("statement -> IF OPAR expr CPAR block \n");
            }
          | FOR ID EQL expr COMMA expr block {
              $$ = new ast_for_statement($4, $6, $7, std::string($2));
              //printf("statement -> FOR ID EQL expr COMMA expr block\n");
            }
          | RETURN expr SCOLON {
              $$ = new ast_return_statement($2);
              //printf("statement -> RETURN expr SCOLON\n");
            }
          | RETURN SCOLON {
              $$ = new ast_return_statement(NULL);
              //printf("statement -> RETURN SCOLON\n");
            }
          | BREAK SCOLON {
              $$ = new ast_break_statement();
              //printf("statement -> BREAK SCOLON\n");
            }
          | CONTINUE SCOLON {
              $$ = new ast_continue_statement();
              //printf("statement -> CONTINUE SCOLON\n");
            }
          | block {
              $$ = $1;
              //printf("statement -> block\n");
           };

assign_op : EQL {
            $$ = AssignOp::equal;
            //printf("assign_op -> EQL\n");
            }
          | PEQL {
          $$ = AssignOp::plus_equal;
          //printf("assign_op -> PEQL\n");
          }
          | MEQL {
          $$ = AssignOp::minus_equal;
          //printf("assign_op -> MEQL\n");
          };

method_call : ID OPAR expr_list CPAR {
              $$ = new ast_normal_method(std::string($1), $3);
              //printf("method_call -> ID OPAR expr_list CPAR\n");
            }
            | ID OPAR CPAR {
            $$ = new ast_normal_method(std::string($1), NULL);
            //printf("method_call -> ID OPAR CPAR\n");
            }
            | CALLOUT OPAR STR COMMA callout_arg_list CPAR
              {
                $$ = new ast_callout_method(std::string($3), $5);
                //printf("method_call -> CALLOUT OPAR STR COMMA callout_arg_list CPAR\n");
              }
            | CALLOUT OPAR STR CPAR {
            $$ = new ast_callout_method(std::string($3), NULL);
            //printf("method_call -> CALLOUT OPAR STR CPAR\n");
            }
            ;

expr_list : expr {
                $$ = new std::vector<ast_expression *>(); $$->push_back($1);
                //printf("expr_list -> expr\n");
            }
          | expr_list COMMA expr {
                $1->push_back($3); $$ = $1;
                //printf("expr_list -> expr_list COMMA expr\n");
            };

callout_arg_list : callout_arg {
                    $$ = new std::vector<ast_callout_arg *>(); $$->push_back($1);
                    //printf("callout_arg_list -> callout_arg\n");
                   }
                 | callout_arg_list COMMA callout_arg {
                    $1->push_back($3); $$ = $1;
                    //printf("callout_arg_list -> callout_arg_list COMMA callout_arg\n");
                   };

location : ID {
              $$ = new ast_var_location(std::string($1));
              //printf("location -> ID\n");
           }
         | ID OSQU expr CSQU {
              $$ = new ast_array_location(std::string($1), $3);
              //printf("location -> ID OSQU expr CSQU\n");
            };

expr : location {
          $$ = $1;
          //printf("expr -> location\n");
      }
     | method_call {
          $$ = $1;
          //printf("expr -> method_call\n");
      }
     | literal {
          $$ = $1;
          //printf("expr -> literal\n");
      }
     | expr OR expr {
          $$ = new ast_binary_operation_expression($1, $3, bin_op::or_op);
          //printf("expr -> expr OR expr\n");
        }
     | expr AND expr {
          $$ = new ast_binary_operation_expression($1, $3, bin_op::and_op);
          //printf("expr -> expr AND expr\n");
        }
     | expr EQLEQL expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::equalequal_op);
            //printf("expr -> expr EQLEQL expr\n");
        }
     | expr NEQL expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::notequal_op);
            //printf("expr -> expr NEQL expr\n");
        }
     | expr LT expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::lessthan_op);
            //printf("expr -> expr LT expr\n");
        }
     | expr LEQ expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::lessequal_op);
            //printf("expr -> expr LEQ expr\n");
        }
     | expr GEQ expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::greaterequal_op);
            //printf("expr -> expr GEQ expr\n");
        }
     | expr GT expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::greaterthan_op);
            //printf("expr ->expr GT expr  \n");
        }
     | expr PLUS expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::plus_op);
            //printf("expr ->expr PLUS expr \n");
        }
     | expr MINUS expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::minus_op);
            //printf("expr ->expr MINUS expr \n");
        }
     | expr MULT expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::multiply_op);
            //printf("expr ->expr MULT expr \n");
        }
     | expr DIV expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::divide_op);
            //printf("expr ->expr DIV expr \n");
        }
     | expr MOD expr {
            $$ = new ast_binary_operation_expression($1, $3, bin_op::modulo_op);
            //printf("expr ->expr MOD expr \n");
        }
     | NOT expr {
              $$ = new ast_unary_operation_expression($2, un_op::not_op);
              //printf("expr -> NOT expr\n");
        }
     | MINUS expr %prec UMINUS {
            $$ = new ast_unary_operation_expression($2, un_op::minus_op);
        }
     | OPAR expr CPAR {
            $$ = $2;
            //printf("expr -> OPAR expr CPAR\n");
        };

callout_arg : expr  {
                $$ = new ast_expression_callout_arg($1);
                //printf("callout_arg -> expr\n");
              }
            | STR {
                $$ = new ast_string_callout_arg(std::string($1));
                //printf("callout_arg -> STR\n");
              };

literal : INT_VAL {
            $$ = new ast_integer_literal_expression($1);
            //printf("literal -> INT_VAL\n");
          }
        | CHAR {
            $$ = new ast_char_literal_expression($1);
            //printf("literal -> CHAR\n");
          }
        | TRUE {
            $$ = new ast_true_literal_expression();
            //printf("literal -> TRUE\n");
          }
        | FALSE {
            $$ = new ast_false_literal_expression();
            //printf("literal -> FALSE\n");
          };

%%


void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
