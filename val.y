%{
#include <stdio.h>
#include <string.h>
#include <math.h>
%}
%union {
int intval;
char* strval;
}
%token <strval>STRING 
%token <intval>NR
%type <intval>e
%type <strval>str
%left '+' '!'
%left '^' '%'

%%
s : e {printf("s-a recunoscut valoarea numerica:%d\n",$<intval>$);}
 | str  {printf("s-a recunoscut sirul:%s\n",$<strval>$);}
 ;
e: e '+' e  {$$=$1+$3;}
 | NR {$$=$1;}
 ;  
str :  str '+' str  {   
			char* s=strdup($1);
                        strcat(s,$3);
			$$=s;
		    }   
    | STRING {$$=strdup($1);}
   
%%
void yyerror(char* s) {
 printf("error:%s\n",s);
}

int main(){
 yyparse();
}    
