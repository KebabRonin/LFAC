%{
#include <stdio.h>
#include <string.h>
#include "code.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yydebug=1; 

struct Tip_Date* now_declaring = NULL;

void new_entry(char* nume, int is_const, char* tip, char* valoare);
void export_sy_table();

%}
%union{
int intval;
char* strval;
char charval;
float floatval;
struct Tip_Date* tipD;
}
%type <intval>lista_array
%token <strval>ID <strval>TIP ASSIGN <intval>NR CMP_OP CLASS <strval>STRING <floatval>FLOAT <charval>CHAR <intval>BOOL
%token BGIN END CONST IF WHILE DO ELSE FOR BOOLAND BOOLOR TYPEOF EVAL GLOBDEF FNCDEF STRUCTDEF
%start progr
%left '+' '-'
%left '*' '/'
%left BOOLAND
%left BOOLOR
%left IF
%left ELSE
%%
progr: declaratii_globale declaratii_fnc declaratii_structuri bloc {printf("program corect sintactic\n");}
	 ;

declaratii_globale : /*epsilon*/
				   | GLOBDEF declaratii_globale_atomic {export_sy_table();}
				   ;

declaratii_globale_atomic : /*epsilon*/
				   | declaratii_globale_atomic tip_date lista_id ';'  
				   ;

declaratii_fnc : /*epsilon*/
			   | FNCDEF declaratii_fnc_atomic
			   ;

declaratii_fnc_atomic : /*epsilon*/
			   | declaratii_fnc_atomic tip_date ID '(' lista_param ')' ';'
			   | declaratii_fnc_atomic tip_date ID '(' lista_param ')' '{' list '}'
			   ;

declaratii_structuri : /*epsilon*/
			   | STRUCTDEF declaratii_structuri_atomic
			   ;

declaratii_structuri_atomic : /*epsilon*/
					 | declaratii_structuri_atomic CLASS ID '{' declaratii_globale_atomic '}'
					 ;

tip_date : TIP {now_declaring = malloc(sizeof(struct Tip_Date)); now_declaring->tip = strdup($1); now_declaring->is_const = 0;}
		 | CONST TIP {now_declaring = malloc(sizeof(struct Tip_Date)); now_declaring->tip = strdup($2); now_declaring->is_const = 1;}
		 | CLASS ID {now_declaring = malloc(sizeof(struct Tip_Date)); now_declaring->tip = strdup($2); now_declaring->is_const = 0;}
		 | CONST CLASS ID {now_declaring = malloc(sizeof(struct Tip_Date)); now_declaring->tip = strdup($3); now_declaring->is_const = 1;}
		 | typeof {now_declaring = NULL;}
		 ;

typeof : TYPEOF '(' ID ')'
	   | TYPEOF '(' TIP ')'
	   | TYPEOF '(' NR ')'
	   | TYPEOF '(' BOOL ')'
	   | TYPEOF '(' STRING ')'
	   | TYPEOF '(' CHAR ')'
	   | TYPEOF '(' FLOAT ')'
	   ;

lista_array : /*epsilon*/ {$$ = 1;}
			| '[' NR ']' lista_array {$$ = $2 * $4;}
			;

lista_id : ID lista_array {
				printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2);
				new_entry($1, now_declaring->is_const, now_declaring->tip, 0);
			}
		 | ID lista_array ASSIGN expresie {printf("%s\n",$1);}
		 | lista_id ',' ID lista_array {
			printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4);
			new_entry($3, now_declaring->is_const, now_declaring->tip, 0);
			}
		 | lista_id ',' ID lista_array ASSIGN expresie {printf("%s\n",$3);}
		 ;

lista_param : /*epsilon*/
			| param
            | lista_param ','  param
            ;

param : tip_date ID
      ;

/* bloc */
bloc : BGIN list END
     ;

instr_bloc : statement
		   | '{' list '}'
		   ;

/* lista instructiuni */
list :  statement ';'
	 | control_statement
	 | list control_statement
     | list statement ';'
     ;

/* instructiune */

lvalue : ID
	   | lvalue '.' ID /*date membru*/
	   | lvalue '[' expresie ']'
	   ;

assignment : lvalue ASSIGN expresie
		   ;

statement : assignment
          | lvalue '(' lista_apel ')'
          | eval
          | control_statement
          ;

control_statement : if_statement
                  | while_statement
				  | do_while_statement
                  | for_statement
				  ;

if_statement : IF '(' boolean_expr ')' instr_bloc else_statement
             | IF '(' boolean_expr ')' instr_bloc %prec IF
			 ;

else_statement : ELSE instr_bloc
		 	   ;

while_statement : WHILE '(' boolean_expr ')' instr_bloc
                ;

do_while_statement : DO instr_bloc WHILE '(' boolean_expr ')' ';'
                   ;

for_statement : FOR '(' assignment ';' boolean_expr ';' assignment ')' instr_bloc
              ;

boolean_expr_atomic : expresie CMP_OP expresie {printf("if\n");}
					;

boolean_expr : '(' boolean_expr ')'
			 | boolean_expr BOOLAND boolean_expr
			 | boolean_expr BOOLOR boolean_expr
			 | boolean_expr_atomic
			 ;

lista_apel : /*epsilon*/
		   | expresie
           | lista_apel ',' expresie
           ;

eval : EVAL '(' expresie ')'
	 ;

expresie: expresie '+' expresie  {}
 | expresie '*' expresie {}
 | expresie '-' expresie {}
 | expresie '/' expresie {}
 | '(' expresie ')' {}
 | NR {printf("Nr : |%d|\n",$1);}
 | STRING {printf("Str : |%s|\n",$1);}
 | FLOAT {printf("Float : |%f|\n",$1);}
 | CHAR {printf("Char : |%c|\n",$1);}
 | BOOL {printf("Bool : |%d|\n",$1);}
 | lvalue {}
 | lvalue '(' lista_apel ')'
 ;
%%
void yyerror(char * s){
  printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
  yyin=fopen(argv[1],"r");
  yyparse();
}
