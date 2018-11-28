/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 84 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 177 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    79,    83,    87,    92,    96,   101,   106,
     110,   115,   119,   124,   128,   133,   137,   142,   146,   151,
     156,   162,   166,   172,   178,   183,   188,   193,   199,   203,
     208,   212,   217,   222,   226,   231,   232,   236,   240,   244,
     248,   252,   256,   260,   264,   268,   273,   277,   281,   286,
     290,   294,   299,   305,   309,   314,   318,   323,   327,   332,
     336,   340,   344,   348,   352,   356,   360,   364,   368,   372,
     376,   380,   384,   388,   392,   396,   400,   403,   408,   412,
     417,   421,   425,   429
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PLUS", "MINUS", "MULT", "DIV", "MOD",
  "EQL", "MEQL", "PEQL", "AND", "OR", "EQLEQL", "NEQL", "LT", "GT", "LEQ",
  "GEQ", "OCUR", "CCUR", "OPAR", "CPAR", "OSQU", "CSQU", "INT", "BOOLEAN",
  "VOID", "CLASS", "PROGRAM", "IF", "ELSE", "FOR", "BREAK", "CONTINUE",
  "RETURN", "CALLOUT", "TRUE", "FALSE", "NOT", "SCOLON", "COMMA", "UMINUS",
  "CHAR", "INT_VAL", "ID", "STR", "$accept", "program", "field_decl_list",
  "field_decl", "var_or_array_identifier_list", "var_or_array_identifier",
  "identifier_list", "method_decl_list", "method_decl",
  "type_identifier_list", "type_identifier", "block", "statement_list",
  "var_decl_list", "var_decl", "type", "statement", "assign_op",
  "method_call", "expr_list", "callout_arg_list", "location", "expr",
  "callout_arg", "literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,   -22,    32,    23,   -54,    48,   -54,   -54,   -54,     2,
      57,   -54,   174,   -54,    20,    60,   -54,   -54,   243,   -54,
     -54,    44,   -18,    38,   -54,    -8,   -54,    72,    45,    54,
     -54,    50,   109,   -16,   -54,    91,   109,   -14,   113,   115,
     -54,   172,   -54,   109,    62,   -54,   -54,   109,   -54,   -54,
     126,   103,   123,   124,    76,   128,   -54,    15,   -54,   208,
     190,   -54,   120,   -54,   141,    41,   -54,   -54,   -54,    86,
     182,   -54,   -54,    86,    86,   -54,   -54,    86,   -54,   -54,
     -54,   -54,   -54,   155,   -54,   133,    96,    86,   -54,   -54,
     -54,   226,   -54,   -54,    51,   -54,   -54,   -54,   -54,    86,
     285,    86,   -54,   305,   -54,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,   -54,   -13,
     -54,   -12,   342,   269,   -54,   -54,   148,   171,   109,   139,
     -54,   350,   350,   350,   350,   350,   356,   356,   -54,   -54,
      92,    92,    92,    92,   -54,    65,   -54,    86,   -54,   -54,
     -54,   165,    86,   -54,   -10,   342,   -54,   342,   109,   325,
     -54,    65,   -54,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     5,    33,    34,     0,
       0,     6,     0,    15,     0,     0,     3,     7,     0,     4,
      16,     0,    11,     0,     9,     0,     2,     0,     0,     0,
       8,     0,     0,     0,    21,     0,     0,     0,     0,    11,
      10,     0,    20,     0,     0,    23,    18,     0,    12,    27,
       0,     0,     0,     0,     0,     0,    35,    57,    45,     0,
       0,    30,     0,    28,     0,     0,    19,    22,    17,     0,
       0,    43,    44,     0,     0,    82,    83,     0,    42,    81,
      80,    60,    59,     0,    61,     0,     0,     0,    26,    29,
      25,     0,    31,    13,     0,    37,    46,    48,    47,     0,
       0,     0,    76,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
      50,     0,    53,     0,    24,    32,     0,     0,     0,     0,
      77,    70,    71,    72,    73,    74,    63,    62,    64,    65,
      66,    69,    67,    68,    52,     0,    49,     0,    58,    14,
      36,    39,     0,    79,     0,    78,    55,    54,     0,     0,
      51,     0,    38,    40,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   193,   -54,   183,   -54,   203,     1,   191,
     177,   -32,   158,   -54,   169,    25,   -52,   -54,   -19,   -54,
     -54,   -15,   -53,    70,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    23,    24,    94,    12,    13,    33,
      34,    58,    59,    60,    61,    35,    63,    99,    81,   121,
     154,    82,   155,   156,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    83,     1,    28,    46,    29,    43,    89,    47,   144,
     146,    66,   160,    20,    32,    68,   100,     7,     8,    20,
     102,   103,    64,     3,   104,    44,    65,    44,   145,   147,
      14,   161,     4,   122,   123,    14,    86,    21,    87,    89,
      64,    64,     5,    21,    65,    65,   127,    15,   129,    96,
      97,    98,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    22,    62,    36,     6,    73,
       7,     8,    64,     7,     8,     9,    65,    16,    30,    31,
      73,    25,     7,     8,     9,    62,    74,     7,     8,    27,
      73,   125,   126,    28,   157,    39,   151,    74,    38,   159,
      73,    55,    75,    76,    77,   112,   113,    74,    79,    80,
      57,   153,    55,    75,    76,    77,    78,    74,   120,    79,
      80,    57,    55,    75,    76,    77,   162,   163,    41,    79,
      80,    57,    55,    75,    76,    77,    45,    48,    29,    79,
      80,    57,   105,   106,   107,   108,   109,    69,    70,    85,
     110,   111,   112,   113,   114,   115,   116,   117,   105,   106,
     107,   108,   109,    71,    72,    93,   110,   111,   112,   113,
     114,   115,   116,   117,   105,   106,   107,   108,   109,   119,
     152,    95,   110,   111,   112,   113,   114,   115,   116,   117,
     101,    41,    49,   149,    19,   118,   158,     7,     8,     7,
       8,     9,    50,    17,    51,    52,    53,    54,    55,    41,
      90,   150,    56,    18,    40,     7,     8,    57,    91,    37,
      50,    67,    51,    52,    53,    54,    55,    41,    88,    92,
      56,   164,     0,     0,     0,    57,     0,     0,    50,     0,
      51,    52,    53,    54,    55,    41,   124,     0,    56,     0,
       0,     0,     0,    57,     0,     0,    50,     0,    51,    52,
      53,    54,    55,    26,     0,     0,    56,     0,     7,     8,
       9,    57,   105,   106,   107,   108,   109,     0,     0,     0,
     110,   111,   112,   113,   114,   115,   116,   117,   105,   106,
     107,   108,   109,   148,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   128,   105,   106,
     107,   108,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,     0,     0,     0,   130,   105,   106,
     107,   108,   109,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,    41,   105,   106,   107,   108,   109,
       0,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   110,   111,   112,   113,   114,   115,   116,   117,   112,
     113,   114,   115,   116,   117
};

static const yytype_int16 yycheck[] =
{
      32,    54,    28,    21,    36,    23,    22,    59,    22,    22,
      22,    43,    22,    12,    22,    47,    69,    25,    26,    18,
      73,    74,    41,    45,    77,    41,    41,    41,    41,    41,
       5,    41,     0,    86,    87,    10,    21,    12,    23,    91,
      59,    60,    19,    18,    59,    60,    99,    45,   101,     8,
       9,    10,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    45,    41,    22,    20,     4,
      25,    26,    91,    25,    26,    27,    91,    20,    40,    41,
       4,    21,    25,    26,    27,    60,    21,    25,    26,    45,
       4,    40,    41,    21,   147,    45,   128,    21,    44,   152,
       4,    36,    37,    38,    39,    13,    14,    21,    43,    44,
      45,    46,    36,    37,    38,    39,    40,    21,    22,    43,
      44,    45,    36,    37,    38,    39,   158,   159,    19,    43,
      44,    45,    36,    37,    38,    39,    45,    24,    23,    43,
      44,    45,     3,     4,     5,     6,     7,    21,    45,    21,
      11,    12,    13,    14,    15,    16,    17,    18,     3,     4,
       5,     6,     7,    40,    40,    45,    11,    12,    13,    14,
      15,    16,    17,    18,     3,     4,     5,     6,     7,    46,
      41,    40,    11,    12,    13,    14,    15,    16,    17,    18,
       8,    19,    20,    45,    20,    40,    31,    25,    26,    25,
      26,    27,    30,    10,    32,    33,    34,    35,    36,    19,
      20,    40,    40,    10,    31,    25,    26,    45,    60,    28,
      30,    44,    32,    33,    34,    35,    36,    19,    20,    60,
      40,   161,    -1,    -1,    -1,    45,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    19,    20,    -1,    40,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    20,    -1,    -1,    40,    -1,    25,    26,
      27,    45,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,     3,     4,
       5,     6,     7,    24,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    22,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    22,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    11,    12,    13,    14,    15,    16,    17,    18,    13,
      14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    48,    45,     0,    19,    20,    25,    26,    27,
      49,    50,    54,    55,    62,    45,    20,    50,    54,    20,
      55,    62,    45,    51,    52,    21,    20,    45,    21,    23,
      40,    41,    22,    56,    57,    62,    22,    56,    44,    45,
      52,    19,    58,    22,    41,    45,    58,    22,    24,    20,
      30,    32,    33,    34,    35,    36,    40,    45,    58,    59,
      60,    61,    62,    63,    65,    68,    58,    57,    58,    21,
      45,    40,    40,     4,    21,    37,    38,    39,    40,    43,
      44,    65,    68,    69,    71,    21,    21,    23,    20,    63,
      20,    59,    61,    45,    53,    40,     8,     9,    10,    64,
      69,     8,    69,    69,    69,     3,     4,     5,     6,     7,
      11,    12,    13,    14,    15,    16,    17,    18,    40,    46,
      22,    66,    69,    69,    20,    40,    41,    69,    22,    69,
      22,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    22,    41,    22,    41,    24,    45,
      40,    58,    41,    46,    67,    69,    70,    69,    31,    69,
      22,    41,    58,    58,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    56,    56,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     5,     4,     1,     2,     3,     1,
       3,     1,     4,     1,     3,     1,     2,     6,     5,     6,
       5,     1,     3,     2,     4,     3,     3,     2,     1,     2,
       1,     2,     3,     1,     1,     1,     4,     2,     7,     5,
       7,     3,     2,     2,     2,     1,     1,     1,     1,     4,
       3,     6,     4,     1,     3,     1,     3,     1,     4,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 75 "parser.y" /* yacc.c:1646  */
    {
            (yyval.program) = new ast_program(std::string((yyvsp[-4].sval)), (yyvsp[-2].field_decl_list), (yyvsp[-1].method_decl_list)); start = (yyval.program);
            //printf("program -> CLASS ID OCUR field_decl_list method_decl_list CCUR\n");
          }
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "parser.y" /* yacc.c:1646  */
    {
            (yyval.program) = new ast_program(std::string((yyvsp[-3].sval)), (yyvsp[-1].field_decl_list), NULL); start = (yyval.program);
            //printf("program -> CLASS ID OCUR field_decl_list CCUR\n");
          }
#line 1423 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "parser.y" /* yacc.c:1646  */
    {
            (yyval.program) = new ast_program(std::string((yyvsp[-3].sval)), NULL, (yyvsp[-1].method_decl_list)); start = (yyval.program);
            //printf("program -> CLASS ID OCUR method_decl_list CCUR\n");
          }
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "parser.y" /* yacc.c:1646  */
    {
            (yyval.program) = new ast_program(std::string((yyvsp[-2].sval)), NULL, NULL); start = (yyval.program);
            //printf("program -> CLASS ID OCUR CCUR\n");
          }
#line 1441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.field_decl_list) = new std::vector<ast_field_decl *>(); (yyval.field_decl_list)->push_back((yyvsp[0].field_decl));
                    //printf("field_decl_list -> field_decl\n");
                  }
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "parser.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].field_decl_list)->push_back((yyvsp[0].field_decl)); (yyval.field_decl_list) = (yyvsp[-1].field_decl_list);
                    //printf("field_decl_list -> field_decl_list field_decl\n");
                  }
#line 1459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "parser.y" /* yacc.c:1646  */
    {
                (yyval.field_decl) = new ast_field_decl((yyvsp[-1].var_or_array_identifier_list), (yyvsp[-2].type));
                //printf("field_decl -> type var_or_array_identifier_list SCOLON\n");
              }
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "parser.y" /* yacc.c:1646  */
    {
                                  (yyval.var_or_array_identifier_list) = new std::vector<ast_id *>(); (yyval.var_or_array_identifier_list)->push_back((yyvsp[0].var_or_array_identifier));
                                  //printf("var_or_array_identifier_list -> var_or_array_identifier\n");
                                }
#line 1477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 110 "parser.y" /* yacc.c:1646  */
    {
                              (yyvsp[-2].var_or_array_identifier_list)->push_back((yyvsp[0].var_or_array_identifier)); (yyval.var_or_array_identifier_list) = (yyvsp[-2].var_or_array_identifier_list);
                              //printf("var_or_array_identifier_list -> var_or_array_identifier_list COMMA var_or_array_identifier\n");
                             }
#line 1486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.var_or_array_identifier) = new ast_id(std::string((yyvsp[0].sval)));
                            //printf("var_or_array_identifier -> ID\n");
                          }
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.var_or_array_identifier) = new ast_id(std::string((yyvsp[-3].sval)), (yyvsp[-1].ival));
                            //printf("var_or_array_identifier -> ID OSQU INT_VAL CSQU\n");
                          }
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "parser.y" /* yacc.c:1646  */
    {
                      (yyval.identifier_list) = new std::vector<ast_id *>(); (yyval.identifier_list)->push_back(new ast_id(std::string((yyvsp[0].sval))));
                      //printf("identifier_list -> ID\n");
                    }
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "parser.y" /* yacc.c:1646  */
    {
                    (yyvsp[-2].identifier_list)->push_back(new ast_id(std::string((yyvsp[0].sval)))); (yyval.identifier_list) = (yyvsp[-2].identifier_list);
                    //printf("identifier_list -> identifier_list COMMA ID\n");
                  }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.method_decl_list) = new std::vector<ast_method_decl *>(); (yyval.method_decl_list)->push_back((yyvsp[0].method_decl));
                    //printf("method_decl_list -> method_decl\n");
                  }
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 137 "parser.y" /* yacc.c:1646  */
    {
                    (yyvsp[-1].method_decl_list)->push_back((yyvsp[0].method_decl)); (yyval.method_decl_list) = (yyvsp[-1].method_decl_list);
                    //printf("method_decl_list -> method_decl_list method_decl\n");
                  }
#line 1540 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "parser.y" /* yacc.c:1646  */
    {
                (yyval.method_decl) = new ast_method_decl(std::string((yyvsp[-4].sval)), (yyvsp[-5].type), (yyvsp[-2].type_identifier_list), (yyvsp[0].block));
                //printf("method_decl -> type ID OPAR type_identifier_list CPAR block\n");
              }
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 147 "parser.y" /* yacc.c:1646  */
    {
                (yyval.method_decl) = new ast_method_decl(std::string((yyvsp[-3].sval)), (yyvsp[-4].type), NULL, (yyvsp[0].block));
                //printf("method_decl -> type ID OPAR CPAR block\n");
              }
#line 1558 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "parser.y" /* yacc.c:1646  */
    {
                (yyval.method_decl) = new ast_method_decl(std::string((yyvsp[-4].sval)), Datatype::void_type, (yyvsp[-2].type_identifier_list), (yyvsp[0].block));
                //printf("method_decl -> VOID ID OPAR type_identifier_list CPAR block\n");
              }
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 157 "parser.y" /* yacc.c:1646  */
    {
                (yyval.method_decl) = new ast_method_decl(std::string((yyvsp[-3].sval)), Datatype::void_type, NULL, (yyvsp[0].block));
                //printf("method_decl -> VOID ID OPAR CPAR block\n");
              }
#line 1576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 162 "parser.y" /* yacc.c:1646  */
    {
                          (yyval.type_identifier_list) = new std::vector<ast_type_identifier *>(); (yyval.type_identifier_list)->push_back((yyvsp[0].type_identifier));
                          //printf("type_identifier_list -> type_identifier \n");
                        }
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 167 "parser.y" /* yacc.c:1646  */
    {
                          (yyvsp[-2].type_identifier_list)->push_back((yyvsp[0].type_identifier)); (yyval.type_identifier_list) = (yyvsp[-2].type_identifier_list);
                          //printf("type_identifier_list -> type_identifier_list COMMA type_identifier\n");
                        }
#line 1594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 173 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.type_identifier) = new ast_type_identifier(std::string((yyvsp[0].sval)), (yyvsp[-1].type));
                    //printf("type_identifier -> type ID\n");
                  }
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 179 "parser.y" /* yacc.c:1646  */
    {
          (yyval.block) = new ast_block_statement((yyvsp[-1].statement_list), (yyvsp[-2].var_decl_list));
          //printf("block -> OCUR var_decl_list statement_list CCUR\n");
        }
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 184 "parser.y" /* yacc.c:1646  */
    {
          (yyval.block) = new ast_block_statement(NULL, (yyvsp[-1].var_decl_list));
          //printf("block -> OCUR var_decl_list CCUR\n");
        }
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 189 "parser.y" /* yacc.c:1646  */
    {
          (yyval.block) = new ast_block_statement((yyvsp[-1].statement_list), NULL);
          //printf("block -> OCUR statement_list CCUR\n");
        }
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "parser.y" /* yacc.c:1646  */
    {
          (yyval.block) = new ast_block_statement(NULL, NULL);
          //printf("block -> OCUR CCUR\n");
        }
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 199 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.statement_list) = new std::vector<ast_statement *>(); (yyval.statement_list)->push_back((yyvsp[0].statement));
                  //printf("statement_list -> statement\n");
                }
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 203 "parser.y" /* yacc.c:1646  */
    {
                  (yyvsp[-1].statement_list)->push_back((yyvsp[0].statement)); (yyval.statement_list) = (yyvsp[-1].statement_list);
                  //printf("statement_list -> statement_list statement\n");
                }
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 208 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.var_decl_list) = new std::vector<ast_var_decl *>(); (yyval.var_decl_list)->push_back((yyvsp[0].var_decl));
                  //printf("var_decl_list -> var_decl\n");
                }
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "parser.y" /* yacc.c:1646  */
    {
                  (yyvsp[-1].var_decl_list)->push_back((yyvsp[0].var_decl)); (yyval.var_decl_list) = (yyvsp[-1].var_decl_list);
                  //printf("var_decl_list -> var_decl_list var_decl \n");
                }
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 217 "parser.y" /* yacc.c:1646  */
    {
            (yyval.var_decl) = new ast_var_decl((yyvsp[-1].identifier_list), (yyvsp[-2].type));
            //printf("var_decl -> type identifier_list SCOLON\n");
          }
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 222 "parser.y" /* yacc.c:1646  */
    {
        (yyval.type) = Datatype::int_type;
        //printf("type -> INT\n");
      }
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 226 "parser.y" /* yacc.c:1646  */
    {
        (yyval.type) = Datatype::bool_type;
        //printf("type -> BOOLEAN\n");
      }
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.statement) = NULL; }
#line 1708 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_assignment_statement((yyvsp[-2].assign_op), (yyvsp[-3].location), (yyvsp[-1].expr));
              //printf("statement -> location assign_op expr SCOLON\n");
            }
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 236 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = (yyvsp[-1].method_call);
              //printf("statement -> method_call SCOLON\n");
            }
#line 1726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_if_statement((yyvsp[-4].expr), (yyvsp[-2].block), (yyvsp[0].block));
              //printf("statement -> IF OPAR expr CPAR block ELSE block\n");
            }
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_if_statement((yyvsp[-2].expr), (yyvsp[0].block), NULL);
              //printf("statement -> IF OPAR expr CPAR block \n");
            }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 248 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_for_statement((yyvsp[-3].expr), (yyvsp[-1].expr), (yyvsp[0].block), std::string((yyvsp[-5].sval)));
              //printf("statement -> FOR ID EQL expr COMMA expr block\n");
            }
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_return_statement((yyvsp[-1].expr));
              //printf("statement -> RETURN expr SCOLON\n");
            }
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 256 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_return_statement(NULL);
              //printf("statement -> RETURN SCOLON\n");
            }
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 260 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_break_statement();
              //printf("statement -> BREAK SCOLON\n");
            }
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 264 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = new ast_continue_statement();
              //printf("statement -> CONTINUE SCOLON\n");
            }
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "parser.y" /* yacc.c:1646  */
    {
              (yyval.statement) = (yyvsp[0].block);
              //printf("statement -> block\n");
           }
#line 1798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 273 "parser.y" /* yacc.c:1646  */
    {
            (yyval.assign_op) = AssignOp::equal;
            //printf("assign_op -> EQL\n");
            }
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 277 "parser.y" /* yacc.c:1646  */
    {
          (yyval.assign_op) = AssignOp::plus_equal;
          //printf("assign_op -> PEQL\n");
          }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 281 "parser.y" /* yacc.c:1646  */
    {
          (yyval.assign_op) = AssignOp::minus_equal;
          //printf("assign_op -> MEQL\n");
          }
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 286 "parser.y" /* yacc.c:1646  */
    {
              (yyval.method_call) = new ast_normal_method(std::string((yyvsp[-3].sval)), (yyvsp[-1].expr_list));
              //printf("method_call -> ID OPAR expr_list CPAR\n");
            }
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 290 "parser.y" /* yacc.c:1646  */
    {
            (yyval.method_call) = new ast_normal_method(std::string((yyvsp[-2].sval)), NULL);
            //printf("method_call -> ID OPAR CPAR\n");
            }
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 295 "parser.y" /* yacc.c:1646  */
    {
                (yyval.method_call) = new ast_callout_method(std::string((yyvsp[-3].sval)), (yyvsp[-1].callout_arg_list));
                //printf("method_call -> CALLOUT OPAR STR COMMA callout_arg_list CPAR\n");
              }
#line 1852 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 299 "parser.y" /* yacc.c:1646  */
    {
            (yyval.method_call) = new ast_callout_method(std::string((yyvsp[-1].sval)), NULL);
            //printf("method_call -> CALLOUT OPAR STR CPAR\n");
            }
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 305 "parser.y" /* yacc.c:1646  */
    {
                (yyval.expr_list) = new std::vector<ast_expression *>(); (yyval.expr_list)->push_back((yyvsp[0].expr));
                //printf("expr_list -> expr\n");
            }
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 309 "parser.y" /* yacc.c:1646  */
    {
                (yyvsp[-2].expr_list)->push_back((yyvsp[0].expr)); (yyval.expr_list) = (yyvsp[-2].expr_list);
                //printf("expr_list -> expr_list COMMA expr\n");
            }
#line 1879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 314 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.callout_arg_list) = new std::vector<ast_callout_arg *>(); (yyval.callout_arg_list)->push_back((yyvsp[0].callout_arg));
                    //printf("callout_arg_list -> callout_arg\n");
                   }
#line 1888 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 318 "parser.y" /* yacc.c:1646  */
    {
                    (yyvsp[-2].callout_arg_list)->push_back((yyvsp[0].callout_arg)); (yyval.callout_arg_list) = (yyvsp[-2].callout_arg_list);
                    //printf("callout_arg_list -> callout_arg_list COMMA callout_arg\n");
                   }
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 323 "parser.y" /* yacc.c:1646  */
    {
              (yyval.location) = new ast_var_location(std::string((yyvsp[0].sval)));
              //printf("location -> ID\n");
           }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 327 "parser.y" /* yacc.c:1646  */
    {
              (yyval.location) = new ast_array_location(std::string((yyvsp[-3].sval)), (yyvsp[-1].expr));
              //printf("location -> ID OSQU expr CSQU\n");
            }
#line 1915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 332 "parser.y" /* yacc.c:1646  */
    {
          (yyval.expr) = (yyvsp[0].location);
          //printf("expr -> location\n");
      }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 336 "parser.y" /* yacc.c:1646  */
    {
          (yyval.expr) = (yyvsp[0].method_call);
          //printf("expr -> method_call\n");
      }
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 340 "parser.y" /* yacc.c:1646  */
    {
          (yyval.expr) = (yyvsp[0].literal);
          //printf("expr -> literal\n");
      }
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 344 "parser.y" /* yacc.c:1646  */
    {
          (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::or_op);
          //printf("expr -> expr OR expr\n");
        }
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 348 "parser.y" /* yacc.c:1646  */
    {
          (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::and_op);
          //printf("expr -> expr AND expr\n");
        }
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 352 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::equalequal_op);
            //printf("expr -> expr EQLEQL expr\n");
        }
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 356 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::notequal_op);
            //printf("expr -> expr NEQL expr\n");
        }
#line 1978 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 360 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::lessthan_op);
            //printf("expr -> expr LT expr\n");
        }
#line 1987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 364 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::lessequal_op);
            //printf("expr -> expr LEQ expr\n");
        }
#line 1996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 368 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::greaterequal_op);
            //printf("expr -> expr GEQ expr\n");
        }
#line 2005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 372 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::greaterthan_op);
            //printf("expr ->expr GT expr  \n");
        }
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 376 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::plus_op);
            //printf("expr ->expr PLUS expr \n");
        }
#line 2023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 380 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::minus_op);
            //printf("expr ->expr MINUS expr \n");
        }
#line 2032 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 384 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::multiply_op);
            //printf("expr ->expr MULT expr \n");
        }
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 388 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::divide_op);
            //printf("expr ->expr DIV expr \n");
        }
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 392 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_binary_operation_expression((yyvsp[-2].expr), (yyvsp[0].expr), bin_op::modulo_op);
            //printf("expr ->expr MOD expr \n");
        }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 396 "parser.y" /* yacc.c:1646  */
    {
              (yyval.expr) = new ast_unary_operation_expression((yyvsp[0].expr), un_op::not_op);
              //printf("expr -> NOT expr\n");
        }
#line 2068 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 400 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = new ast_unary_operation_expression((yyvsp[0].expr), un_op::minus_op);
        }
#line 2076 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 403 "parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = (yyvsp[-1].expr);
            //printf("expr -> OPAR expr CPAR\n");
        }
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 408 "parser.y" /* yacc.c:1646  */
    {
                (yyval.callout_arg) = new ast_expression_callout_arg((yyvsp[0].expr));
                //printf("callout_arg -> expr\n");
              }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 412 "parser.y" /* yacc.c:1646  */
    {
                (yyval.callout_arg) = new ast_string_callout_arg(std::string((yyvsp[0].sval)));
                //printf("callout_arg -> STR\n");
              }
#line 2103 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 417 "parser.y" /* yacc.c:1646  */
    {
            (yyval.literal) = new ast_integer_literal_expression((yyvsp[0].ival));
            //printf("literal -> INT_VAL\n");
          }
#line 2112 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 421 "parser.y" /* yacc.c:1646  */
    {
            (yyval.literal) = new ast_char_literal_expression((yyvsp[0].cval));
            //printf("literal -> CHAR\n");
          }
#line 2121 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 425 "parser.y" /* yacc.c:1646  */
    {
            (yyval.literal) = new ast_true_literal_expression();
            //printf("literal -> TRUE\n");
          }
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 429 "parser.y" /* yacc.c:1646  */
    {
            (yyval.literal) = new ast_false_literal_expression();
            //printf("literal -> FALSE\n");
          }
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2143 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 434 "parser.y" /* yacc.c:1906  */



void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
