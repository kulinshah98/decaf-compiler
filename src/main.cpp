#include <cstdio>
#include <iostream>

#include "ast.h"
#include "codegen_visitor.h"
#include "visitor.h"

extern "C" FILE *yyin;
extern "C" int yyparse();

ast_program * start;

int main (const int argc, const char ** argv) {
    if (argc < 2) {
        yyin = NULL;
        std::cerr <<"fatal error: no input files" << std::endl;
        return -1;
    } else {
        FILE * infile = fopen(argv[1], "r");
        if (!infile) {
            std::cerr <<"Error reading file " << argv[1] << std::endl;
            return -1;
        }
        yyin = infile;
    }

    if (!yyparse()) {
        codegen_visitor * visitor = new codegen_visitor(start);
        visitor->code_gen();
    }
    return 0;
}
