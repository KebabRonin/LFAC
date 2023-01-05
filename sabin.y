%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Functii.h"
extern FILE* yyin;
 FILE *fis;
extern char* yytext;
extern int yylineno;

expresie_info* create_int_expr(int value);
expresie_info* create_str_expr(char* value1, char* value2);
expresie_info* create_float_expr(float value);
expresie_info* create_bool_expr(int value);
void free_expr(expresie_info* expr);
void print_expr(expresie_info* expr);
struct variable{
     char *nume;
     char *tip;
     char *utilizare;
     char *constant;
     char *valoarechar;
     float  valoareint;
}variabile[100];
int nrVariabile = 0;

struct functile{
     char *nume;
     char *tip;
     
}functii[100];
int nrfunctii = 0;


int inseramVariabila(char *nume, char *tip,char *utilizare,char *constant,char *valoarechar, float valoareint){
     int i=0;
     for(i=0;i< nrVariabile ; i++){
          if(strcmp(variabile[i].nume,nume)==0)
               {
                    yyerror("Variabila este deja declarata! Eroare");
                    exit(0);
                         }
     }
     variabile[nrVariabile].nume = strdup(nume);
     variabile[nrVariabile].tip = strdup(tip);
     variabile[nrVariabile].utilizare = strdup(utilizare);
     variabile[nrVariabile].constant = strdup(constant);
     variabile[nrVariabile].valoarechar = strdup(valoarechar);
     variabile[nrVariabile].valoareint = valoareint;
     nrVariabile++;
     return 1;
}
int existaVariabila(char *s){
     int i=0;
     for(i=0;i<nrVariabile;i++){
          if(strcmp(s,variabile[i].nume)==0)
               return i;
     }
     yyerror("Variabila nu este declarata! Eroare");
     exit(0);
}

int existaFunctie(char *s){
     int i=0;
     for(i=0;i<nrfunctii;i++){
          if(strcmp(s,functii[i].nume)==0)
               return i;
     }
     yyerror("Functia nu este declarata! Eroare");
     exit(0);
}



int inseramFunctie(char *nume, char *tip){
    
     
    functii[nrfunctii].nume = strdup(nume);
     functii[nrfunctii].tip = strdup(tip);
     nrfunctii++;
     return 1;
}

int parcurgere(){
    fis = fopen ("symbol_table.txt", "wt");
   fprintf(fis,"%s\n","NUME-TIP-UTILIZARE-CONSTANTA-VALOARE INITIALA");
    int i=0;
     for(i=0;i<nrVariabile;i++){
       fprintf(fis,"%s- ",variabile[i].nume);
       if((strstr(variabile[i].tip,"sir_caractere")!=0) && (strcmp(variabile[i].valoarechar,"None")==0)){
       strcpy(variabile[i].tip,"vector de numere ");
       
       }
       fprintf(fis,"%s- ",variabile[i].tip);
       fprintf(fis,"%s- ",variabile[i].utilizare);
        fprintf(fis,"%s- ",variabile[i].constant);
        if(strcmp(variabile[i].valoarechar,"None")!=0){
        fprintf(fis,"%s\n",variabile[i].valoarechar);
        }else{
        fprintf(fis,"%f\n",variabile[i].valoareint);
        }
        
         
       }
       fclose(fis);
       }
       
       int parcurgere1(){
       FILE *fis1;
       fis1 = fopen ("symbol_table_functions.txt", "wt");
       fprintf(fis1,"%s\n","NUME-TIPUL DE RETURN");
    int i=0;
     for(i=0;i<nrfunctii;i++){
       fprintf(fis1,"%s-",functii[i].nume);
       fprintf(fis1,"%s\n",functii[i].tip);
       
       }
       fclose(fis1);
       }

int isGlobal = 1;
int inFunctii = 0;
int inMain = 0;
char *vectorVar;


int tipVector=0,tipVectorValoareCurenta=0; /*0-set tip 1-int, 2-float 3-char 4-char* 5-bool */
int tipVar=0,tipVarCurenta; /*0-set tip 1-int, 2-float 3-char 4-char* 5-bool pentru a verifica daca este initializata cu o valoare corecta*/
%}
%union {
     int valoareIntreg;
     char* tipData;
     char* valoareSirCaractere;
     float valoareReal;
     char valoareCaracter;
     struct expresie_info* expresie_info;
}

%token BGIN END ASSIGN START_FCT END_FCT BGIN_MAIN END_MAIN CONSTANT
%token IF ELSE WHILE FOR COMP PRINT
%token <valoareCaracter> VALOARE_CARACTER
%token <valoareIntreg> VALOARE_INTREG
%token <valoareIntreg> BOOLVALUE
%token <valoareReal> VALOARE_REAL
%token <valoareSirCaractere> VALOARE_CUVANT
%token <valoareSirCaractere> VAR
%token <valoareSirCaractere> VECTOR
%token <tipData> STRUCT
%token <tipData> TIP
%token <valoareSirCaractere> OP
%type <expresie_info> valoriVar
%type <expresie_info> EXPRESIE
%start progr
%%
progr: global functii bloc {printf("Programul este corect corect sintactic\n");}
     ;
global : BGIN
        {printf("%s\n","Intram in global");} 
        declaratii END 
        {
           printf("%s\n","Am iesit din global");
           isGlobal = 0;
           inFunctii = 1; 
           printf("%s\n","Urmeaza functiile");
         }
     ;

declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : TIP VAR {
                     if(isGlobal==1){
               inseramVariabila($2, $1,"globala","variabila","None",0);
                  
                    }else{
                    inseramVariabila($2, $1,"locala","variabila","None",0);
              
                    }
                    }
           | CONSTANT TIP VAR {
           if (isGlobal==1){
               inseramVariabila($3, $2,"globala","constanta","None",0);
                
                    }else{
                    inseramVariabila($3, $2,"locala","constanta","None",0);
                    }
                    }
           | TIP VECTOR {
               vectorVar = strdup(extractVarFromArray($2));
             
       if(isGlobal==1){        inseramVariabila(vectorVar,"sir_caractere","globala","variabila","None",0);
       }else{
       inseramVariabila(vectorVar,"sir_caractere","locala","variabila","None",0);
                    }
                    }
           | TIP VECTOR ASSIGN '{' vectorAssign '}'{
               tipVector = returnTipData($1);
               vectorVar = strdup(extractVarFromArray($2));
    if(isGlobal==1){        inseramVariabila(vectorVar,"sir_caractere","globala","variabila","None",0);
    }else{
                    inseramVariabila(vectorVar,"sir_caractere","locala","variabila","None",0);         
                    }
              }      
           | STRUCT '{' declaratii '}' VAR {
               inseramVariabila($5,$1,"globala","variabila","None",0);
                   
                    }
           | TIP VAR ASSIGN EXPRESIE {
               tipVar = returnTipData($1);
               if(tipVar == tipVarCurenta){
                    if($4->type ==1){
                    inseramVariabila($2,$1,"globala","variabila","None",$4->intvalue);
                    }
                     if($4->type ==2){
                    inseramVariabila($2,$1,"globala","variabila","None",$4->floatvalue);
                    }
                     if($4->type ==3){
                    inseramVariabila($2,$1,"globala","variabila",$4->strvalue,0);
                    }
                     if($4->type ==4){
                    inseramVariabila($2,$1,"globala","variabila","None",$4->intvalue);
                    }
                       
               }else
                    {
                    yyerror("Valoarea nu corespunde cu tipul variabilei! Eroare");
                    exit(0);
                    }
               }
               
           | CONSTANT TIP VAR ASSIGN EXPRESIE {
          if(isGlobal==1){
               inseramVariabila($3,$2,"globala","constanta","None",0);
                   }else{
                  inseramVariabila($3,$2,"locala","constanta","None",0);
                  }
                  }
                   
                   
           ;

vectorAssign : valori ',' vectorAssign {
                    if(tipVector!=0)
                         if(tipVector!=tipVectorValoareCurenta)
                              {
                                   yyerror("Vectorul trebuie sa fie de un singur tip! Eroare");
                                   exit(0);
                              }
                    
                    }
                    
           | valori
           ;
           
valori : VALOARE_REAL {if(tipVector ==0) {tipVector =2;tipVectorValoareCurenta=2;}else tipVectorValoareCurenta=2;}
           | VALOARE_INTREG {if(tipVector ==0) {tipVector =1;tipVectorValoareCurenta=1;}else tipVectorValoareCurenta=1;}
           | VALOARE_CUVANT {if(tipVector ==0) {tipVector =4;tipVectorValoareCurenta=4;}else tipVectorValoareCurenta=4;}
           | VALOARE_CARACTER {if(tipVector ==0) {tipVector =3;tipVectorValoareCurenta=3;}else tipVectorValoareCurenta=3;}
           | BOOLVALUE {if(tipVector ==0) {tipVector =5;tipVectorValoareCurenta=5;}else tipVectorValoareCurenta=5;}
           ;

valoriVar: VALOARE_REAL {
                         if(tipVar ==0) 
                              {    tipVar =2;
                                   tipVarCurenta=2;
                              }else
                                   tipVarCurenta=2;
                         $$ = create_float_expr($1);
                         }
           | VALOARE_INTREG {if(tipVar ==0) {tipVar =1;tipVarCurenta=1;}else tipVarCurenta=1;
                         $$ = create_int_expr($1);}
           | VALOARE_CARACTER {if(tipVar ==0) {tipVar =3;tipVarCurenta=3;}else tipVarCurenta=3;
                         $$ = create_str_expr(transformchar($1),NULL);}
           | VALOARE_CUVANT {if(tipVar ==0) {tipVar =4;tipVarCurenta=4;}else tipVarCurenta=4;
                         $$ = create_str_expr($1,NULL);}
           | BOOLVALUE {if(tipVar ==0) {tipVar =5;tipVarCurenta=5;}else tipVarCurenta=5;
                         
                         $$ = create_bool_expr($1);
                        }
           ;

asignari : VAR ASSIGN EXPRESIE {int ok=0;
                 if(existaVariabila($1)){
                     for(int i=0;i<nrVariabile;i++){
                         if(strcmp($1,variabile[i].nume)==0){
                                                             if((strcmp(variabile[i].tip,"intreg")==0) && $3->type==1) ok=1;
                                                                                                                          if((strcmp(variabile[i].tip,"real")==0) && $3->type==2) ok=1;
                                                                                                                          
 if((strcmp(variabile[i].tip,"caracter")==0) && $3->type==3) ok=1;
  
 if((strcmp(variabile[i].tip,"bool")==0) && $3->type==4) ok=1;
   
 if((strcmp(variabile[i].tip,"sir_caractere")==0) && $3->type==3) ok=1;   
 }
 }
 if(ok==0){
       yyerror("NU poti atribui tipuri diferite! Eroare");
                                   exit(0);
                                   }
                                   }
                                   
                                                                                                                    


printf("Asignare ok \n");}
          | VECTOR ASSIGN EXPRESIE {if(existaVariabila(extractVarFromArray($1))) printf("Asignare ok \n");}
          ;
EXPRESIE: VAR {if(existaVariabila($1)){
              $$ = create_int_expr(1);
              }
              }
          | VAR '('')'{ if(existaFunctie($1)) {$$ = create_int_expr(1);}}
          | VAR '(' lista_param ')'{ if(existaFunctie($1)) {$$ = create_int_expr(1);}}
          | VECTOR { $$ = create_int_expr(1);}
          | valoriVar { $$=$1;}
          | EXPRESIE OP EXPRESIE{
               if($1->type == 1 && $3->type == 1)
                    {
                         if(strcmp($2,"+")==0)
                         $$ = create_int_expr($1->intvalue + $3->intvalue);
                         if(strcmp($2,"-")==0)
                         $$ = create_int_expr($1->intvalue - $3->intvalue);
                         if(strcmp($2,"*")==0)
                         $$ = create_int_expr($1->intvalue * $3->intvalue);
                         if(strcmp($2,"/")==0)
                         $$ = create_int_expr($1->intvalue / $3->intvalue);
                         if(strcmp($2,"%")==0)
                         $$ = create_int_expr($1->intvalue % $3->intvalue);
                 }        
               if($1->type == 2 && $3->type == 2)
                    {
                         if(strcmp($2,"+")==0)
                         $$ = create_float_expr($1->floatvalue + $3->floatvalue);
                         if(strcmp($2,"-")==0)
                         $$ = create_float_expr($1->floatvalue - $3->floatvalue);
                         if(strcmp($2,"*")==0)
                         $$ = create_float_expr($1->floatvalue * $3->floatvalue);
                         if(strcmp($2,"/")==0)
                         $$ = create_float_expr($1->floatvalue / $3->floatvalue);
                    printf(" \n \n \n Rezultatul expresiei este: %f \n \n \n ", $$->floatvalue);}
               if($1->type == 3 && $3->type == 3)
                    {
                         if(strcmp($2,"+")==0)
                              $$ = create_str_expr($1->strvalue,$3->strvalue);
                         else
                         {
                              yyerror("Nu exista aceasta operatie pentru siruri de caractere! Eroare");
                              exit(0);
                         }
                         }
                   
               if($1->type == 4 && $3->type == 4)
                    {
                         if(strcmp($2,"+")==0)
                         $$ = create_bool_expr($1->intvalue + $3->intvalue);
                         if(strcmp($2,"-")==0)
                         $$ = create_bool_expr($1->intvalue - $3->intvalue);
                         if(strcmp($2,"*")==0)
                         $$ = create_bool_expr($1->intvalue * $3->intvalue);
                         if(strcmp($2,"/")==0)
                         $$ = create_bool_expr($1->intvalue / $3->intvalue);
                         if(strcmp($2,"%")==0)
                         {
                              yyerror("Nu exista aceasta operatie pentru boolean-uri! Eroare");
                              exit(0);
                         }
                   
               free_expr($3);free_expr($1);
          }
          }
print: PRINT '(' VALOARE_CUVANT ',' EXPRESIE ')'
;



lista_param : param
            | lista_param ','  param 
            ;            
param : TIP VAR 
          | CONSTANT TIP VAR
          | VAR '('')'
          | VAR '(' lista_param ')'
          | EXPRESIE 
          | conditii
          
      ; 
functii : START_FCT continut END_FCT{
printf("%s\n","Sau terminat functiile");


}
          ;
continut : TIP VAR '(' lista_param ')' {
            printf(" \n Am ajuns la o funtie cu parametri\n");
            inseramFunctie($2, $1);
           
            }
          | TIP VAR '('')' {  inseramFunctie($2, $1);}
          | TIP VAR '(' lista_param ')' '{' continut_functie '}'{printf(" \n Am ajuns la o funtie cu param si continut\n");
            inseramFunctie($2, $1);
          }
          | TIP VAR '(' ')' '{' continut_functie '}'{inseramFunctie($2, $1);}
          | continut TIP VAR '(' lista_param ')' {inseramFunctie($3, $2);}
          | continut TIP VAR '(' ')'{inseramFunctie($3, $2);}
          | continut TIP VAR '(' lista_param ')' '{' continut_functie '}'{
          {inseramFunctie($3, $2);}}
          | continut TIP VAR '(' ')' '{' continut_functie '}'{inseramFunctie($3, $2);}
          ;
continut_functie : declaratii
;

/* bloc */
bloc : BGIN_MAIN list END_MAIN  {
parcurgere();
parcurgere1();
}
     ;

/* lista instructiuni */
list :  statement ';' 
     |  statement ';' list
     ;

/* instructiune */
statement: declaratie
          | asignari
          | print
          | VAR'('')'
         | VAR '(' lista_apel ')'
         | IF '(' conditii ')' '{' list '}'
         | IF '(' conditii ')' '{' list '}' ELSE '{' list '}'
         | WHILE '(' conditii ')' '{' list '}'
         | FOR '(' declaratie ',' conditii ',' EXPRESIE ')' '{' list '}'
         ;
        
conditii:  EXPRESIE
          | conditii COMP conditii
          ;
lista_apel : EXPRESIE
           | lista_apel ',' EXPRESIE
           ;
%%

expresie_info* create_int_expr(int value)
{
       
   expresie_info* expr = (expresie_info*)malloc(sizeof(expresie_info));
   expr->intvalue = value;
   expr->type = 1;
   return expr;
}

expresie_info* create_bool_expr(int value)
{
       
   expresie_info* expr = (expresie_info*)malloc(sizeof(expresie_info));
   if(value > 0)
     expr->intvalue = 1;
   else
    expr->intvalue = 0;
   expr->type = 4;
   
   return expr;
}
expresie_info* create_float_expr(float value)
{
       
   expresie_info* expr = (expresie_info*)malloc(sizeof(expresie_info));
   expr->floatvalue = value;
   expr->type = 2;
   return expr;
}

expresie_info* create_str_expr(char* value1, char* value2) 
{
   expresie_info* expr = (expresie_info*)malloc(sizeof(expresie_info));
   int len2 = value2 ? strlen(value2) : 0;
   expr->strvalue = (char*) malloc(sizeof(char)*(strlen(value1) + len2 +1)); 
   strcpy(expr->strvalue, value1);
   if(value2)
   {
      strcat(expr->strvalue, value2);
   }
   expr->type = 3;
   return expr;
          
}

void free_expr(expresie_info* expr)
{
  if(expr->type == 2)
  {
     free(expr->strvalue);
  }
  free(expr);
}


void print_expr(expresie_info* expr)
{
   if(expr->type == 1) 
   {
     printf("Int expr with value:%d",expr->intvalue);
   }
   else
   {
     printf("Str expr with value:%s", expr->strvalue); 
   } 
}

int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 

