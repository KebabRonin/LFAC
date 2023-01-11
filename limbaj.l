%{
#include <stdio.h>
#include <string.h>
#include "code.h"
#include "y.tab.h"
%}
%option noyywrap
%%
"//"(.*) {}
"int"|"float"|"char"|"string"|"bool" {yylval.strval=strdup(yytext); return TIP;}
"begin_progr" {return BGIN;}
"_global" {return GLOBDEF;}
"_fnc" {return FNCDEF;}
"_userdef" {return STRUCTDEF;}
"end_progr" {return END;}
"TypeOf" {return TYPEOF;}
"Eval" {return EVAL;}
"struct" {return CLASS;}
"const" {return CONST;}
"if" {return IF;}
"else" { return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"do" {return DO;}
"and" {return BOOLAND;}
"or" {return BOOLOR;}
"true"|"false" {if(strcmp(yytext,"true")==0)
                {
                    yylval.intval=1;
                }
                else yylval.intval=0;
                return BOOL;}
"=="|(<=?)|(>=?)|"!=" {return CMP_OP;}
[_a-zA-Z][_a-zA-Z0-9]* {yylval.strval=strdup(yytext); return ID;}
\'[a-zA-Z0-9 _\-=+()\\/?;:'!@#$%^&*]\' {yylval.charval=yytext[1]; return CHAR;}
"=" {return ASSIGN;}
[0-9]+ {yylval.intval = atoi(yytext); return NR;}
[0-9]+"."[0-9]+ {yylval.floatval = atof(yytext); return FLOAT;}
\"[a-zA-Z0-9 _\-=+()\\/?;:'!@#$%^&*]*\" { yylval.strval=strndup(yytext+1, strlen(yytext+1) -1); return STRING;}
[ \t] ;
\n {yylineno++;}
\r ;
. {return yytext[0];}

