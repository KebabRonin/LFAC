%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"intreg"|"real"|"caracter"|"sir_caractere"|"bool" {printf(" tip: %s", yytext);yylval.tipData = strdup(yytext); return TIP;}
"structura" {printf(" struct: %s", yytext);yylval.tipData = strdup(yytext);return STRUCT;}
"afiseaza" {return PRINT;}
"incepe_init" {return BGIN;}
"termina_init" {return END;}
"incepe_functii" {return START_FCT;}
"termina_functii" {return END_FCT;}
"incepe_main" {return BGIN_MAIN;}
"termin_main" {return END_MAIN;}
"daca" {return IF;}
"altfel" { return ELSE;}
"cat_timp" {return WHILE;}
"pentru" {return FOR;}
"constant" {return CONSTANT;}
"<"|">"|"=="|">="|"<="|"<>" {return COMP;}
"+"|"-"|"*"|"/"|"%" {yylval.valoareSirCaractere = strdup(yytext);return OP;}
"adevarat"|"fals" {printf(" bool: %s \n", yytext);
                        if(strcmp(yytext,"adevarat")==0 || 1 == atoi(yytext))
                            {yylval.valoareIntreg = 1;}
                        else{
                            yylval.valoareIntreg = 0;
                        }
                        return BOOLVALUE;
                        }
[a-zA-Z][_a-zA-Z0-9]*                           {printf(" var: %s \n", yytext);yylval.tipData = strdup(yytext);return VAR;}
[\'][a-zA-Z][\']                                {printf(" car: %s \n", yytext);yylval.valoareCaracter = yytext[1];return VALOARE_CARACTER;}
[0-9]+                                     {printf(" intreg: %s \n", yytext);yylval.valoareIntreg = atoi(yytext);return VALOARE_INTREG;}
[0-9]*\.?[0-9]+                            {printf(" real: %s \n", yytext);yylval.valoareReal = atof(yytext);return VALOARE_REAL;}

[a-zA-Z][_a-zA-Z0-9]*(\[[0-9]+\])+              {printf(" vector: %s \n", yytext);yylval.valoareSirCaractere = strdup(yytext);return VECTOR;}



\"(\\.|[^"])*\"                                 {printf(" cuv: %s \n", yytext);yylval.valoareSirCaractere = strdup(yytext);return VALOARE_CUVANT;}
"=" {return ASSIGN;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
