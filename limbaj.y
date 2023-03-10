%{
#include <stdio.h>
#include <string.h>
#include "code.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yydebug=1; 

struct Tip_Date* now_declaring = NULL;
char parameters[100][100];
char structNames[100][100];
int nr_parametri = 0;
char* typeOf;
char* nume_typeof;
int is_char = 0;
int is_string = 0;
int is_int = 0;
int is_float = 0;
float f;
int tipuri_expresii[100];
char elemente_expresie[100][100];
int nr_expresii = 0;
int nr_elemente_expresie = 0;
int is_eval = 0;
int is_parameter=0;
char parametri[100][100];

struct AstNode* buildAST(char* root, struct AstNode* left, struct AstNode* right, int type);
void freeAST(struct AstNode* self);
int EvalAST(struct AstNode* root);

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
struct AstNode* ast;
}
%type <ls>lista_array lista_param lista_param_non_void
%type <tipD>tip_date
%type <symbol>param 
%type <ast>expresie
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
progr: declaratii_globale declaratii_fnc declaratii_structuri bloc {printf("\nCORRECT PROGRAM\n");}
	 ;

declaratii_globale : /*epsilon*/
				   | GLOBDEF { make_sym_table(0); } declaratii_globale_atomic 	{	
																					export_sy_table();
																					nr_expresii=0;
																					memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
																				}
				   ;

declaratii_globale_atomic : /*epsilon*/
				   | declaratii_globale_atomic tip_date {now_declaring = $2;} lista_id ';'  
				   ;

declaratii_fnc : /*epsilon*/
			   | FNCDEF declaratii_fnc_atomic {export_fn_table();}
			   ;

declaratii_fnc_atomic : /*epsilon*/
			   | declaratii_fnc_atomic tip_date ID '(' lista_param ')' '{' list '}' {
																						new_entry_fn($3, $2, $5);
																					}
			   | declaratii_fnc_atomic tip_date ID '(' lista_param ')' '{''}' {
							new_entry_fn($3, $2, $5);
						}
			   ;

declaratii_structuri : /*epsilon*/
			   | STRUCTDEF declaratii_structuri_atomic {export_sy_table();}
			   ;

lista_date_membru : /*epsilon*/
				   | lista_date_membru tip_date {
					now_declaring = $2; 
					} lista_id ';'  
				   ;

opt_lista_id: lista_id
			| /*epsilon*/
			;

declaratii_structuri_atomic : /*epsilon*/
					 | declaratii_structuri_atomic CLASS ID  {
					userdef_table.dimensiune[userdef_table.nr_dimensiuni] = (char*) (malloc(sizeof(struct UserDef))); 
					((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->nume = strdup($3);
					strcpy(structNames[userdef_table.nr_dimensiuni], $3);
					((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->date = malloc(sizeof(struct tabela_simboluri));
					make_sym_table((((struct UserDef*)(userdef_table.dimensiune[userdef_table.nr_dimensiuni]))->date));
					userdef_table.nr_dimensiuni++;
					} '{' lista_date_membru '}' {
						now_declaring = malloc(sizeof(struct Tip_Date));
						now_declaring->is_const = 0;
						now_declaring->tip = strdup($3);
						make_sym_table(0);
					} opt_lista_id {
						now_declaring->is_const = 0;
						free(now_declaring->tip);
						free(now_declaring);
						now_declaring = 0;
					}';'
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

typeof : TYPEOF '(' expresie ')'{
									verify_expresie(tipuri_expresii,nr_expresii);
									
									if(nr_elemente_expresie == 1)
									{
										if(is_char==1)
										{
											printf("TypeOf('%c') : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
											is_char=0;
										}
										else if(is_string==1)
										{
											printf("TypeOf(\"%s\") : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
											is_string=0;
										}
										else if(is_int==1)
										{
											printf("TypeOf(%d) : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
											is_int=0;
										}
										else if(is_float==1)
										{
											printf("TypeOf(%f) : %s\tLINE : %d\n",f,typeOf,yylineno);
											is_float=0;
										}
										else
										{
											printf("TypeOf(%s) : %s\tLINE : %d\n",nume_typeof,typeOf,yylineno);
										}
									}
									else
									{
										printf("TypeOf() : %s\tLINE : %d\n",typeOf,yylineno);
									}
									
									nr_expresii=0;
									nr_elemente_expresie = 0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
									memset(elemente_expresie, 0, sizeof(elemente_expresie));
	   							}
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
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy($1, now_declaring->is_const, now_declaring->tip, 0, $2);
			}
		 | ID lista_array ASSIGN expresie {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $1, $2->nr_dimensiuni);
				new_entry_sy($1, now_declaring->is_const, now_declaring->tip, /*$4*/0, $2);
			}
		 | lista_id ',' ID lista_array {
			// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
			new_entry_sy($3, now_declaring->is_const, now_declaring->tip, 0, $4);
			}
		 | lista_id ',' ID lista_array ASSIGN expresie {
				// printf("list_id :%s %d %s howmany:%d\n", now_declaring->tip, now_declaring->is_const, $3, $4->nr_dimensiuni);
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
bloc : BGIN {nr_expresii=0;
			memset(tipuri_expresii, 0, sizeof(tipuri_expresii));} list END
	 | BGIN END
     ;

instr_bloc : statement
		   | '{' list '}'
		   ;

/* lista instructiuni */
list : statement ';'
	 | control_statement
	 | list control_statement
     | list statement ';'
     ;


assignment : ID lista_array ASSIGN expresie {
									if(exists_variable($1)<0)
									{
										char* error[100];
										strcpy(error,"Variable \"");
										strcat(error,$1);
										strcat(error, "\" is not declared.");
										yyerror(strdup(error));
										exit(0);
									}
									check_arrayList($1, $2);
									verify_assignement($1,tipuri_expresii,nr_expresii);
									nr_expresii=0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));

									int val = exists_variable($1);
									assign(val, $4);
									freeAST($4);
								}
			| ID lista_array '.' ID ASSIGN expresie {
									if(exists_variable($1)<0)
									{
										char* error[100];
										strcpy(error,"Variable \"");
										strcat(error,$1);
										strcat(error, "\" is not declared.");
										yyerror(strdup(error));
										exit(0);
									}
									check_arrayList($1, $2);
									verify_assignement($1,tipuri_expresii,nr_expresii);
									nr_expresii=0;
									memset(tipuri_expresii, 0, sizeof(tipuri_expresii));

									int val = exists_variable($1);
									assign(val, $6);
									freeAST($6);
								}
		   ;

statement : assignment
          | ID '(' {is_parameter=1;} lista_apel ')' 	{
										
										if(exists_function($1)>=0)
										{
											verify_parameters($1,parameters,nr_parametri);
											if(verify_no_parameters($1)==1)
											{
												char* error[100];
												strcpy(error,"Function \"");
												strcat(error,$1);
												strcat(error, "\" isn't supposed to have parameters.");
												yyerror(strdup(error));
												exit(0);
											}
											nr_parametri = 0;
										}
										else
										{
											char* error[100];
											strcpy(error,"Function \"");
											strcat(error,$1);
											strcat(error, "\" is not declared.");
											yyerror(strdup(error));
											exit(0);
										}
									}
		  | ID '('')'	{
							if(exists_function($1)>=0)
							{
								verify_parameters($1,parameters,nr_parametri);

								if(verify_no_parameters($1)==1)
								{
									char* error[100];
									strcpy(error,"Function \"");
									strcat(error,$1);
									strcat(error, "\" isn't supposed to have parameters.");
									yyerror(strdup(error));
									exit(0);
								}
								nr_parametri = 0;
							}
							else
							{
								char* error[100];
								strcpy(error,"Function \"");
								strcat(error,$1);
								strcat(error, "\" is not declared.");
								yyerror(strdup(error));
								exit(0);
							}
						}
          | eval
		  | typeof
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

boolean_expr_atomic : expresie CMP_OP expresie {}
					;

boolean_expr : '(' boolean_expr ')'
			 | boolean_expr BOOLAND boolean_expr
			 | boolean_expr BOOLOR boolean_expr
			 | boolean_expr_atomic 	{
										verify_expresie(tipuri_expresii,nr_expresii);
										nr_expresii=0;
										memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
			 						}
			 ;


lista_apel : expresie 	{
							verify_expresie(tipuri_expresii,nr_expresii);
							is_parameter=1;
							nr_expresii=0;
							memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
						}
            | lista_apel ','  expresie 	{
											verify_expresie(tipuri_expresii,nr_expresii);
											is_parameter=1;
											nr_expresii=0;
											memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
										}
            ;

eval : EVAL {nr_expresii=0;
			 					memset(tipuri_expresii, 0, sizeof(tipuri_expresii));}'(' expresie ')' {	
								verify_expresie(tipuri_expresii,nr_expresii);
								if(is_ASTint($4) == 0) {
									yyerror("Type unsupported for eval");
									exit(0);
								}
								
								int rez = EvalAST($4);
								printf("Eval Result : %d\tLINE: %d\n",rez,yylineno);
								freeAST($4);
								
								nr_expresii=0;
								memset(tipuri_expresii, 0, sizeof(tipuri_expresii));
							}
	 ;

expresie: expresie '+' expresie  	{
										strcpy(elemente_expresie[nr_elemente_expresie],"+");
										nr_elemente_expresie++;
										char k = '+';
										$$ = buildAST(&k, $1, $3, OP);
									}
 | expresie '*' expresie 	{
								strcpy(elemente_expresie[nr_elemente_expresie],"*");
								nr_elemente_expresie++;
								char k = '*';
								$$ = buildAST(&k, $1, $3, OP);
							}
 | expresie '-' expresie 	{
								strcpy(elemente_expresie[nr_elemente_expresie],"-");
								nr_elemente_expresie++;
								char k = '-';
								$$ = buildAST(&k, $1, $3, OP);
							}
 | expresie '/' expresie 	{
								strcpy(elemente_expresie[nr_elemente_expresie],"/");
								nr_elemente_expresie++;
								char k = '/';
								$$ = buildAST(&k, $1, $3, OP);
							}
 | '(' expresie ')' {$$ = $2;}
 | NR 	{
			if(is_parameter==1)
			{
				//strcpy(parameters[nr_parametri],$1);
				sprintf(parameters[nr_parametri],"%d",$1);
				nr_parametri++;
				is_parameter=0;
			}
			nume_typeof = $1;
			typeOf = "int";
			is_int=1;
			tipuri_expresii[nr_expresii] = 1;
			nr_expresii++;
			int a = $1;
			$$ = buildAST(&a, 0, 0, INT);
		}
 | STRING 	{
				if(is_parameter==1)
				{
					strcpy(parameters[nr_parametri],$1);
					//sprintf(parameters[nr_parametri],"%d",$1);
					nr_parametri++;
					is_parameter=0;
				}
				nume_typeof = $1;
				typeOf = "string";
				is_string=1;
				tipuri_expresii[nr_expresii] = 4;
				nr_expresii++;
				int a = $1;
				$$ = buildAST(&a, 0, 0, STR);
			}
 | FLOAT 	{
				if(is_parameter==1)
				{
					//strcpy(parameters[nr_parametri],$1);
					sprintf(parameters[nr_parametri],"%f",$1);
					nr_parametri++;
					is_parameter=0;
				}
				f = $1;
				typeOf = "float";
				is_float=1;
				tipuri_expresii[nr_expresii] = 2;
				nr_expresii++;
				int a = $1;
				$$ = buildAST(&a, 0, 0, FLT);
			}
 | CHAR {
			if(is_parameter==1)
			{
				//strcpy(parameters[nr_parametri],$1);
				sprintf(parameters[nr_parametri],"%c",$1);
				nr_parametri++;
				is_parameter=0;
			}
			nume_typeof = $1;
			typeOf = "char";
			is_char=1;
			tipuri_expresii[nr_expresii] = 3;
			nr_expresii++;
				int a = $1;
				$$ = buildAST(&a, 0, 0, CHR);
 		}
 | BOOL {
			if(is_parameter==1)
			{
				//strcpy(parameters[nr_parametri],$1);
				sprintf(parameters[nr_parametri],"%d",$1);
				nr_parametri++;
				is_parameter=0;
			}
			if($1 == 1)
			{
				nume_typeof = "true";
			}
			else
			{
				nume_typeof = "false";
			}
			typeOf = "bool";
			tipuri_expresii[nr_expresii] = 5;
			nr_expresii++;
			int a = $1;
			$$ = buildAST(&a, 0, 0, BOL);
		}
 | ID lista_array	{
						if(exists_variable($1)>=0)
						{
							if(is_parameter==1)
							{
								strcpy(parameters[nr_parametri],$1);
								nr_parametri++;
								is_parameter=0;
							}
							
							check_arrayList($1, $2);
							nume_typeof = $1;
							if(get_typeof($1)==1)
							{
								typeOf = "int";
							}
							else if(get_typeof($1)==2)
							{
								typeOf = "float";
							}
							else if(get_typeof($1)==3)
							{
								typeOf = "char";
							}
							else if(get_typeof($1)==4)
							{
								typeOf = "string";
							}
							else if(get_typeof($1)==5)
							{
								typeOf = "bool";
							}
							else {
								typeOf = structNames[get_typeof($1)-6];
							}
							tipuri_expresii[nr_expresii] = get_typeof($1);
							nr_expresii++;
							nr_elemente_expresie++;
							$$ = buildAST($1, 0, 0, IDENTIFIER);
						}
						else
						{
							char* error[100];
							strcpy(error,"Variable \"");
							strcat(error,$1);
							strcat(error, "\" is not declared.");
							yyerror(strdup(error));
							exit(0);
						}
					}
 | ID lista_array '.' ID	{
			if(exists_variable($1)>=0)
			{
				check_arrayList($1, $2);
				nume_typeof = $1;
				if(get_typeof($1)==1)
				{
					typeOf = "int";
				}
				else if(get_typeof($1)==2)
				{
					typeOf = "float";
				}
				else if(get_typeof($1)==3)
				{
					typeOf = "char";
				}
				else if(get_typeof($1)==4)
				{
					typeOf = "string";
				}
				else if(get_typeof($1)==5)
				{
					typeOf = "bool";
				}
				else {
					typeOf = structNames[get_typeof($1)-6];
				}
				tipuri_expresii[nr_expresii] = get_typeof($1);
				strcpy(elemente_expresie[nr_elemente_expresie],$1);
				nr_expresii++;
				nr_elemente_expresie++;
				$$ = buildAST($1, 0, 0, IDENTIFIER);
			}
			else
			{
				char* error[100];
				strcpy(error,"Variable \"");
				strcat(error,$1);
				strcat(error, "\" is not declared.");
				yyerror(strdup(error));
				exit(0);
			}
 		}
 | ID '(' {is_parameter = 1;nr_parametri=0;}lista_apel ')' 	{
								
								if(exists_function($1)>=0)
								{
									verify_parameters($1,parameters,nr_parametri);
									if(verify_no_parameters($1)==1)
									{
										char* error[100];
										strcpy(error,"Function \"");
										strcat(error,$1);
										strcat(error, "\" isn't supposed to have parameters.");
										yyerror(strdup(error));
										exit(0);
									}
									else
									{
										nume_typeof = $1;
										is_char = 0;is_string = 0;is_int = 0;is_float = 0;
										if(get_typeof($1)==1)
										{
											typeOf = "int";
										}
										else if(get_typeof($1)==2)
										{
											typeOf = "float";
										}
										else if(get_typeof($1)==3)
										{
											typeOf = "char";
										}
										else if(get_typeof($1)==4)
										{
											typeOf = "string";
										}
										else if(get_typeof($1)==5)
										{
											typeOf = "bool";
										}
										tipuri_expresii[nr_expresii] = get_typeof($1);
										strcpy(elemente_expresie[nr_elemente_expresie],$1);
										nr_expresii++;
										nr_elemente_expresie++;
									}
									nr_parametri=0;
									$$ = buildAST($1, 0, 0, FNC);
								}
								else
								{
									char* error[100];
									strcpy(error,"Function \"");
									strcat(error,$1);
									strcat(error, "\" is not declared.");
									yyerror(strdup(error));
									exit(0);
								}
							}
 | ID '('')'	{
				if(exists_function($1)>=0)
				{
					verify_parameters($1,parameters,nr_parametri);
					if(verify_no_parameters($1)==1)
					{
						nume_typeof = $1;
						if(get_typeof(nume_typeof)==1)
						{
							typeOf = "int";
						}
						else if(get_typeof(nume_typeof)==2)
						{
							typeOf = "float";
						}
						else if(get_typeof(nume_typeof)==3)
						{
							typeOf = "char";
						}
						else if(get_typeof(nume_typeof)==4)
						{
							typeOf = "string";
						}
						else if(get_typeof(nume_typeof)==5)
						{
							typeOf = "bool";
						}
						tipuri_expresii[nr_expresii] = get_typeof($1);
						strcpy(elemente_expresie[nr_elemente_expresie],$1);
						nr_expresii++;
						nr_elemente_expresie++;
						$$ = buildAST($1,0,0,FNC);
					}
					else
					{
						char* error[100];
						strcpy(error,"Function \"");
						strcat(error,$1);
						strcat(error, "\" isn't supposed to have parameters.");
						yyerror(strdup(error));
						exit(0);
					}
					nr_parametri = 0;
				}
				else
				{
					char* error[100];
					strcpy(error,"Function \"");
					strcat(error,$1);
					strcat(error, "\" is not declared.");
					yyerror(strdup(error));
					exit(0);
				}
			}
 ;
%%
void yyerror(char * s)
{
  	printf("ERROR: %s\tLINE:%d\n",s,yylineno);
}

int main(int argc, char** argv)
{
	yyin=fopen(argv[1],"r");
	yyparse();
}
