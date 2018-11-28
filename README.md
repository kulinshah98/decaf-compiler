### Decaf Compiler

## Structure of folder

- scanner.l - It contains scanner of decaf compiler which will recognize tokens using regular expressions.  
- parser.y - It contains parser of decaf compiler. It checks macro-syntax of language.  
- ast.h - It contains declarations of all classes used in construction of AST.
- ast.cpp - It contains all funtions of classes except statements, methods related classes required for AST.
- methods.cpp - It contains all functions of classes for method classes. 
- statements.cpp - It contains all functions of different type of statement classes. 
- main.cpp - It initiates process of parsing of a program.
- codegen_visitor.h - It contains code generator visitor functions related to all classes except classes related expression and statements.
- expressiongen_visitor.h - It contains code generator visitor functions of expression classes.
- statementgen_visitor.h - It contains code generator visitor functions of statement classes.

## Compile and run

- To compile the code, use 'make' command.
- To run decaf compiler on `input.dcf` file,  use command `./parser input.dcf`
- redirect output of above file in an output file. 
- Run output file using `lli`.
- Example: 
    - `make`
    - `./parser input.dcf > output`
    - `lli output`


## Project description

# Scanner 

- `flex` scanner for scanning tokens.
- Detects tokens using regular expressions.

# Parser

- `bison` parser for generating AST
- Implented using context free grammers

# AST

- Generates AST

# Code generation

- Implemented using `Visitor design pattern`


