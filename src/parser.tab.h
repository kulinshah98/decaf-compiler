/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PLUS = 258,
    MINUS = 259,
    MULT = 260,
    DIV = 261,
    MOD = 262,
    EQL = 263,
    MEQL = 264,
    PEQL = 265,
    AND = 266,
    OR = 267,
    EQLEQL = 268,
    NEQL = 269,
    LT = 270,
    GT = 271,
    LEQ = 272,
    GEQ = 273,
    OCUR = 274,
    CCUR = 275,
    OPAR = 276,
    CPAR = 277,
    OSQU = 278,
    CSQU = 279,
    INT = 280,
    BOOLEAN = 281,
    VOID = 282,
    CLASS = 283,
    PROGRAM = 284,
    IF = 285,
    ELSE = 286,
    FOR = 287,
    BREAK = 288,
    CONTINUE = 289,
    RETURN = 290,
    CALLOUT = 291,
    TRUE = 292,
    FALSE = 293,
    NOT = 294,
    SCOLON = 295,
    COMMA = 296,
    UMINUS = 297,
    CHAR = 298,
    INT_VAL = 299,
    ID = 300,
    STR = 301
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
