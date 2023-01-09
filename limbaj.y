%{
#include <stdio.h>
#include <string.h>
#include "code.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yydebug=1; 

struct Tip_Date* now_declaring = NULL;
char* function[50];
char* parameters[100][100];
int nr_parametri = 0;

void new_entry_sy(char* nume, int is_const, char* tip, char* valoare, struct list* matrix);
void new_entry_fn(char* nume, struct Tip_Date* ret, struct list* param);
void export_sy_table();
void export_fn_table();

%}
%union{
int intval;
char* strval;
char charval;
float floatval;
struct Tip_Date* tipD;
struct list* ls;
struct simbol* symbol;
}
%type <ls>lista_array lista_param lista_param_non_void
%type <tipD>tip_date
%type <symbol>param
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
				   | declaratii_globale_atomic tip_date {now_declaring = $2;} lista_id ';'  
				   ;

declaratii_fnc : /*epsilon*/
			   | FNCDEF declaratii_fnc_atomic {export_fn_table();}
			   ;

declaratii_fnc_atomic : /*epsilon*/
			   | declaratii_fnc_atomic tip_date ID '(' lista_param ')' ';' {
																				new_entry_fn($3, $2, $5);
																			}
			   | declaratii_fnc_atomic tip_date ID '(' lista_param ')' '{' list '}' {
																						new_entry_fn($3, $2, $5);
																					}
			   ;

declaratii_structuri : /*epsilon*/
			   | STRUCTDEF declaratii_structuri_atomic
			   ;

declaratii_structuri_atomic : /*epsilon*/
					 | declaratii_structuri_atomic CLASS ID '{' declaratii_globale_atomic '}'
					 ;

tip_date : TIP {$$ = malloc(sizeof(struct Tip_Date)); $$->tip = strdup($1); $$->is_const = 0; 
				$$->size = malloc(sizeof(struct list)); $$->size->nr_dimensiuni=0;
				}
		 | CONST TIP {$$ = malloc(sizeof(struct Tip_Date)); $$->tip = strdup($2); $$->is_const = 1;
				$$->size = malloc(sizeof(struct list)); $$->size->nr_dimensiuni=0;
				}
		 | CLASS ID {$$ = malloc(sizeof(struct Tip_Date)); $$->tip = strdup($2); $$->is_const = 0;
				$$->size = malloc(sizeof(struct list)); $$->size->nr_dimensiuni=0;
				}
		 | CONST CLASS ID {$$ = malloc(sizeof(struct Tip_Date)); $$->tip = strdup($3); $$->is_const = 1;
				$$->size = malloc(sizeof(struct list)); $$->size->nr_dimensiuni=0;
				}
		 | typeof {$$ = NULL;}
		 ;

typeof : TYPEOF '(' ID ')'
	   | TYPEOF '(' TIP ')'
	   | TYPEOF '(' NR ')'
	   | TYPEOF '(' BOOL ')'
	   | TYPEOF '(' STRING ')'
	   | TYPEOF '(' CHAR ')'
	   | TYPEOF '(' FLOAT ')'
	   ;

lista_array : /*epsilon*/ {$$ = malloc(sizeof(struct list)); $$->nr_dimensiuni=0;}
			| '[' NR ']' lista_array { 
										$$ = $4; 
										if($$->nr_dimensiuni == 5)
										{
											yyerror("ERROR:Array has too many dimensions.");
     										exit(0);
										}
										$$->dimensiune[$$->nr_dimensiuni]    = malloc(sizeof(int)); 
										*((int*)($$->dimensiune[$$->nr_dimensiuni]))   = $2; 
										$$->nr_dimensiuni++;}
			;

lista_id : ID lista_array {
				printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy($1, now_declaring->is_const, now_declaring->tip, 0, $2);
			}
		 | ID lista_array ASSIGN expresie {
				printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy($1, now_declaring->is_const, now_declaring->tip, /*$4*/0, $2);
			}
		 | lista_id ',' ID lista_array {
			printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
			new_entry_sy($3, now_declaring->is_const, now_declaring->tip, 0, $4);
			}
		 | lista_id ',' ID lista_array ASSIGN expresie {
				printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
				new_entry_sy($3, now_declaring->is_const, now_declaring->tip, /*$6*/0, $4);
			}
		 ;

lista_param : /*epsilon*/ {$$ = malloc(sizeof(struct list)); $$->nr_dimensiuni = 0;}
			| lista_param_non_void
			;

lista_param_non_void : param {$$ = malloc(sizeof(struct list)); $$->dimensiune[0] = $1; $$->nr_dimensiuni = 1;}
            | lista_param_non_void ','  param {$$ = $1; $$->dimensiune[$$->nr_dimensiuni++] = $3;}
            ;

param : tip_date ID lista_array {
									$$ = malloc(sizeof(struct simbol)); 
									free($1->size);
									$1->size = $3;
									$$->tip = $1;
									$$->nume = strdup($2); 
									$$->valoare = 0;
								}
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

/* lvalue : ID {
				if(exists_variable($1)==1)
				{
					printf("%s variable exists.\n",$1);
				}
				else
				{
					//printf("%s doesn't exists.\n",$1);
					yyerror("Variable is not declared.");
    				exit(0);
				}
			}
	   | lvalue '.' ID {
							if(exists_variable($3)==1)
							{
								printf("%s variable exists.\n",$3);
							}
							else
							{
								//printf("%s doesn't exists.\n",$3);
								yyerror("Variable is not declared.");
								exit(0);
							}
						}
	   | lvalue '[' expresie ']'
	   ; */

assignment : ID ASSIGN expresie {
									if(exists_variable($1)==1)
									{
										printf("%s variable exists.\n",$1);
									}
									else
									{
										//printf("%s doesn't exists.\n",$1);
										yyerror("Variable is not declared.");
										exit(0);
									}
								}
		   ;

statement : assignment
          | ID '(' lista_apel ')' 	{
										if(exists_function($1)==1)
										{
											printf("%s function exists.\n",$1);
											verify_parameters($1,parameters,nr_parametri);
											if(verify_no_parameters($1)==1)
											{
												yyerror("Function is not declared with any parameters.");
												exit(0);
											}
											else
											{
												printf("%s function is called correctly.\n",$1);
											}
											nr_parametri = 0;
										}
										else
										{
											yyerror("Function is not declared.");
											exit(0);
										}
									}
		  | ID '('')'	{
							if(exists_function($1)==1)
							{
								printf("%s function exists.\n",$1);
								if(verify_no_parameters($1)==1)
								{
									printf("%s function is called correctly.\n",$1);
								}
							}
							else
							{
								yyerror("Function is not declared.");
								exit(0);
							}
						}
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


lista_apel : param_apel {}
            | lista_apel ','  param_apel {}
            ;

param_apel : ID {
					strcpy(parameters[nr_parametri],get_type($1));
					nr_parametri++;				
				}
      	   ;

/* lista_apel : /*epsilon*/
/*		   | expresie
           | lista_apel ',' expresie 
           ; */

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
 | ID 	{
			if(exists_variable($1)==1)
			{
				printf("%s variable exists.\n",$1);
			}
			else
			{
				//printf("%s doesn't exists.\n",$1);
				yyerror("Variable is not declared.");
				exit(0);
			}
 		}
 | ID '(' lista_apel ')' 	{
								if(exists_function($1)==1)
								{
									printf("%s function exists.\n",$1);
									strcpy(function,$1);
									verify_parameters($1,parameters,nr_parametri);
									if(verify_no_parameters($1)==1)
									{
										yyerror("Function is not declared with any parameters.");
										exit(0);
									}
									else
									{
										printf("%s function is called correctly.\n",$1);
									}
									nr_parametri=0;
								}
								else
								{
									yyerror("Function is not declared.");
									exit(0);
								}
							}
| ID '('')'	{
				if(exists_function($1)==1)
				{
					printf("%s function exists.\n",$1);
					if(verify_no_parameters($1)==1)
					{
						printf("%s function is called correctly.\n",$1);
					}
				}
				else
				{
					yyerror("Function is not declared.");
					exit(0);
				}
			}
 ;
%%
void yyerror(char * s)
{
  	printf("ERROR: %s line:%d\n",s,yylineno);
}

int main(int argc, char** argv)
{
	yyin=fopen(argv[1],"r");
	yyparse();
}
