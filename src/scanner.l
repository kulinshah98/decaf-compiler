%{
#include "ast.h"
#include "parser.tab.h"
#include "visitor.h"
#define YY_DECL extern "C" int yylex()

extern union node yylval;
int lineno = 0;

char * translateString(char *, int);
%}

%option noyywrap


CHAR (\.|[^\"])


%%

  /* Binary operators  */
\+                              {
                                  //printf("plus\n");
                                  return (PLUS);
                                }
\-                              {
                                  //printf("minus\n");
                                  return (MINUS);
                                }
\*                              {
                                  //printf("mult\n");
                                  return (MULT);
                                }
\/                              {
                                  //printf("div\n");
                                  return (DIV);
                                }
\%                              {
                                  //printf("mod\n");
                                  return (MOD);
                                }

\=                              {
                                  //printf("eql\n");
                                  return (EQL);
                                }
\-\=                            {
                                  //printf("meql\n");
                                  return (MEQL);
                                }
\+\=                            {
                                  //printf("peql\n");
                                  return (PEQL);
                                }

 /* conditional operators  */
\&\&                            {
                                  //printf("and\n");
                                  return (AND);
                                }
\|\|                            {
                                  //printf("or\n");
                                  return (OR);
                                }

\=\=                            {
                                  //printf("eql_eql\n");
                                  return (EQLEQL);
                                }
\!\=                            {
                                  //printf("neql\n");
                                  return (NEQL);
                                }

\<                              {
                                  //printf("lt\n");
                                  return (LT);
                                }
\>                              {
                                  //printf("gt\n");
                                  return (GT);
                                }
\<\=                            {
                                  //printf("leq\n");
                                  return (LEQ);
                                }
\>\=                            {
                                  //printf("geq\n");
                                  return (GEQ);
                                }


 /* brackets  */
\{                              {
                                  //printf("ocur\n");
                                  return (OCUR);
                                }
\}                              {
                                  //printf("ccur\n");
                                  return (CCUR);
                                }
\(                              {
                                  //printf("opar\n");
                                  return (OPAR);
                                }
\)                              { //printf("cpar\n");
                                    return (CPAR); }
"["                             { //printf("osqu\n");
                                    return (OSQU); }
\]                              { //printf("csqu\n");
                                    return (CSQU); }

  /* comment */
\/\/.*				;


  /* Data Type */
int                             { //printf("INT\n");
                                    return (INT); }
boolean                         { //printf("Boolean\n");
                                    return (BOOLEAN); }
void                            { //printf("Void\n");
                                    return (VOID); }


 /* Keywords */
class                           { //printf("class\n");
                                    return (CLASS); }
if                              { //printf("if\n");
                                    return (IF); }
else                            { //printf("else\n");
                                    return (ELSE); }
for                             { //printf("for\n");
                                    return (FOR); }
break                           { //printf("break\n");
                                    return (BREAK); }
continue                        { //printf("continue\n");
                                    return (CONTINUE); }
return                          { //printf("return\n");
                                    return (RETURN); }
callout                         { //printf("callout\n");
                                    return (CALLOUT); }
true                            { //printf("true\n");
                                    return (TRUE); }
false                           { //printf("false\n");
                                    return (FALSE); }


 /* Numbers, Strings and Others */
0x[0-9a-fA-F][0-9a-fA-F]*       { //printf("hex\n");
                                    return (INT_VAL); }
[0-9]+                          { //printf("decimal\n");
                                    yylval.ival = atoi(yytext); return (INT_VAL); }
\"{CHAR}*\"                     { //printf("string\n");
                                  yylval.sval = translateString(yytext + 1, strlen(yytext) - 2); return (STR);}
\'{CHAR}?\'                     { //printf("char\n");
                                  yylval.cval = yytext[1]; return (CHAR); }
[a-zA-Z_][a-zA-Z0-9_]*          { //printf("id\n");
                                  yylval.sval = strdup(yytext); return (ID); }


  /* Special Characters */
!                               { //printf("excla\n");
                                    return (NOT); }
;                               { //printf("scolon\n");
                                    return (SCOLON); }
,                               { //printf("comma\n");
                                    return (COMMA); }
\t
\n                              {lineno++;}
" "
.				                {printf("Error here\n");}

  /* Comment Line */
\/\/(.*)"\n"




%%
char * translateString(char * string, int size) {
    char * ch = string;
    char * newString = (char *) malloc(size + 1);
    char * temp = newString;
    int i;
    for (i = 0; i < size; i++) {
        switch (*ch) {
            case '\\':
                i++;
                ch++;
                switch (*ch) {
                    case 'a':
                        *temp = '\a';
                        break;
                    case 'b':
                        *temp = '\b';
                        break;
                    case 'f':
                        *temp = '\f';
                        break;
                    case 'n':
                        *temp = '\n';
                        break;
                    case 'r':
                        *temp = '\r';
                        break;
                    case 't':
                        *temp = '\t';
                        break;
                    case 'v':
                        *temp = '\v';
                        break;
                    case '\\':
                        *temp = '\\';
                        break;
                    case '\'':
                        *temp = '\'';
                        break;
                    case '\"':
                        *temp = '\"';
                        break;
                    case '?':
                        *temp = '\?';
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                        // TODO: Fill
                        break;
                    case 'x':
                        // TODO: Fill
                        break;
                    default:
                        break;
                }
                break;
            default:
                *temp = *ch;
                break;
        }
        ch++;
        temp++;
    }
    *temp = '\0';
    return newString;
}
