#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include "code.h"

extern int yylineno;

int isNumeric(const char *str) 
{
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}
int float_test(const char *s) {
  char *endptr;
  errno = 0;
  float f = strtof(s, &endptr);
  if (s == endptr)  {
    return 0;
  }
  while (isspace((unsigned char) *endptr)) {  
    endptr++;
  }   
  if (*endptr) {
    return 0; 
  }

  if (errno) {
    return errno; 
  }  

  return 1;
}
int validateString(const char* s)
{
    const char c;
    for (int i=0;i<strlen(s);i++) {
        if (!isalpha(s[i]) && !isspace(s[i]))
            return 0;
    }

    return 1;
}
void make_sym_table(struct tabela_simboluri* p) {
    if(p == 0) sym_table = &sy_table;
    else sym_table = p;
}
void new_entry_sy(char* nume, int is_const, char* tip, char* valoare, struct list* matrix) 
{
    int i=0;
    for(i=0;i< sym_table->nr_entries; i++)
    {
        if(strcmp(sym_table->entries[i].nume,nume)==0)
        {
            char* error[100];
            strcpy(error,"There already exists a variable called \"");
            strcat(error,nume);
            strcat(error, "\".");
            yyerror(strdup(error));
            exit(0);
        }
    }
    int k=0;
    for(k=0;k< fn_table.nr_entries; k++)
    {
        if(strcmp(fn_table.entries[k].name,nume)==0)
        {
            char* error[100];
            strcpy(error,"There already exists a function called \"");
            strcat(error,nume);
            strcat(error, "\".");
            yyerror(strdup(error));
            exit(0);
        }
    }

    struct simbol newentry;
    newentry.tip = malloc(sizeof(struct Tip_Date));
	newentry.nume = strdup(nume);
	newentry.tip->tip = strdup(tip);
	newentry.tip->is_const = is_const;
    if(matrix==NULL)
    {
        newentry.tip->size= malloc(sizeof(struct list));
        newentry.tip->size->nr_dimensiuni = 0;
    }
    else
    {
        newentry.tip->size = matrix;
    }

    int size = 1;
    for(int i=0;i<newentry.tip->size->nr_dimensiuni;i++)
    {
        size=size*(*((int*)(newentry.tip->size->dimensiune[i])));
    }

	if(0 == strcmp(tip,"int")) {
		newentry.valoare = (char*) malloc(sizeof(int) * size);
        if (valoare != 0)
    		*((int*)newentry.valoare) = *((int*) valoare);
        else 
            *((int*)newentry.valoare) = 0;
	}
	else if(0 == strcmp(tip,"bool")) {
		newentry.valoare = malloc(sizeof(char) * size);
		if (valoare != 0)
    		*((char*)newentry.valoare) = *((char*) valoare);
        else 
            *((char*)newentry.valoare) = 0;
	}
	else if(0 == strcmp(tip,"float")) {
		newentry.valoare = malloc(sizeof(float) * size);
		if (valoare != 0)
    		*((float*)newentry.valoare) = *((float*) valoare);
        else 
            *((float*)newentry.valoare) = 0;
	}
	else if(0 == strcmp(tip,"char")) {
		newentry.valoare = malloc(sizeof(char) * size);
		if (valoare != 0)
    		*((char*)newentry.valoare) = *((char*) valoare);
        else 
            *((char*)newentry.valoare) = 0;
	}
	else if(0 == strcmp(tip,"string")) {
        newentry.valoare = malloc(sizeof(char*) * size);
        memset(newentry.valoare,NULL,sizeof(char*) * size);
        if (valoare != 0)
    		newentry.valoare = strdup(valoare);
        else 
            newentry.valoare = strdup("");
		
	}
    else {
        newentry.valoare = 0;
    }
	sym_table->entries[sym_table->nr_entries++] = newentry;
}
void verify_expresie(int tipuri_expresii[100],int nr_expresii)
{
    int i=0;
    int primul = tipuri_expresii[0];
    
    for(i=1;i<nr_expresii;i++)
    {
        if(tipuri_expresii[i] != primul)
        {
            printf("tipul primului = %d\ntipul urmatorului = %d\n",primul,tipuri_expresii[i]);
            yyerror("Operands in the right side don't have the same type.");
            exit(0);
        }
    }
}
void verify_assignement(char* leftvalue, int tipuri_expresii[100],int nr_expresii)
{
    int i=0;
    int primul = tipuri_expresii[0];

    for(i=1;i<nr_expresii;i++)
    {
        if(tipuri_expresii[i] != primul)
        {
            printf("lvalue type = %d,\nrvalue type = %d\n",tipuri_expresii[i],primul);
            yyerror("Operands in the right side don't have the same type.");
            exit(0);
        }
    }
    if(get_typeof(leftvalue) != primul)
    {
        printf("lvalue type = %d,\nrvalue type = %d\n",get_typeof(leftvalue),primul);
        yyerror("The left side and the right side don't have the same type.");
        exit(0);
    }
}
void new_entry_fn(char* nume, struct Tip_Date* ret, struct list* param) 
{

    int j=0;
    for(j=0;j< sy_table.nr_entries; j++)
    {
        if(strcmp(sy_table.entries[j].nume,nume)==0)
        {
            char* error[100];
            strcpy(error,"There already exists a variable called \"");
            strcat(error,nume);
            strcat(error, "\".");
            yyerror(strdup(error));
            exit(0);
        }
    }
    int k=0;
    for(k=0;k< fn_table.nr_entries; k++)
    {
        if(strcmp(fn_table.entries[k].name,nume)==0)
        {
            struct functie fnc_same_name;
            for (int i = 0; i < param->nr_dimensiuni; i++) 
            {
                fnc_same_name.param[i] = param->dimensiune[i];
            }
            int w,ok=1;
            if(strcmp(ret->tip,fn_table.entries[k].return_type->tip)==0)
            {
                for (w = 0; w < param->nr_dimensiuni; w++) 
                {
                    if(strcmp(fnc_same_name.param[w]->tip->tip,fn_table.entries[k].param[w]->tip->tip)!=0)
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok==1)
                {
                    char* error[100];
                    strcpy(error,"There already exists a function called \"");
                    strcat(error,nume);
                    strcat(error, "\" having the parameters's types exactly the same.");
                    yyerror(strdup(error));
                    exit(0);
                }
            }  
        }
    }

	struct functie newentry;
    newentry.return_type = ret;
    newentry.name = strdup(nume);
    newentry.nr_param = param->nr_dimensiuni;
    
	for (int i = 0; i < param->nr_dimensiuni; i++) {
        newentry.param[i] = param->dimensiune[i];
    }
    
	fn_table.entries[fn_table.nr_entries++] = newentry;
}
int exists_variable(char *s)
{
    int i=0;
    for(i=0;i<sym_table->nr_entries;i++)
    {
        if(strcmp(s,sym_table->entries[i].nume)==0)
            return i;
    }
    return -1;
}
void check_arrayList(char* nume, struct list* array_sizes) {
    int i=0;
    for(i=0;i<sy_table.nr_entries;i++)
    {
        if(strcmp(nume,sy_table.entries[i].nume)==0)
            break;
    }
    if(array_sizes->nr_dimensiuni != sy_table.entries[i].tip->size->nr_dimensiuni) {
        yyerror("Numar incorect de dimensiuni");
        exit(0);
    }
    for(int j = 0; j < array_sizes->nr_dimensiuni; j++) {
        if( 0 > *((int*)(array_sizes->dimensiune[j])) || *((int*)(array_sizes->dimensiune[j])) >= *((int*)(sy_table.entries[i].tip->size->dimensiune[j]))) {
            printf("%d,%d\n",*((int*)(array_sizes->dimensiune[j])), *((int*)(sy_table.entries[i].tip->size->dimensiune[j])));
            yyerror("index out of bounds.");
            exit(0);
        }
    }
}
int exists_function(char *s)
{
    int i=0;
    for(i=0;i<fn_table.nr_entries;i++)
    {
        if(strcmp(s,fn_table.entries[i].name)==0)
            return i;
    }
    return -1;
}
int verify_no_parameters(char* s)
{
    int i=0;
    for(i=0;i<fn_table.nr_entries;i++)
    {
        if(strcmp(s,fn_table.entries[i].name)==0)
            break;
    }
    if(fn_table.entries[i].nr_param == 0)
    {
        return 1;
    }
    return 0;
}
void verify_parameters(char* s,char parameters[100][100],int nr_parametri)
{
    int i=0;
    for(i=0;i<fn_table.nr_entries;i++)
    {
        if(strcmp(s,fn_table.entries[i].name)==0)
            break;
    }
    int k=i;
    if(nr_parametri != fn_table.entries[i].nr_param)
    {
        char error[100];
        char aux[100];
        strcpy(error,"The number of parameters of function \"");
        strcat(error,s);
        strcat(error, "\" is ");
        sprintf(aux,"%d",nr_parametri);
        strcat(error,aux);
        strcat(error, ", when it should be ");
        sprintf(aux,"%d",fn_table.entries[i].nr_param);
        strcat(error,aux);
        strcat(error, ".");
        yyerror(strdup(error));
        exit(0);
    }
    int j=0;
    for(j=0;j<nr_parametri;j++)
    {
        for(i=0;i<sy_table.nr_entries;i++)
        {
            if(strcmp(parameters[j],sy_table.entries[i].nume)==0)
            {
                strcpy(parameters[j], sy_table.entries[i].tip->tip);
                break;
            }
        }
        if(strcmp(parameters[j],fn_table.entries[k].param[j]->tip->tip)!=0)
        {
            if (float_test(parameters[j]) && !(isNumeric(parameters[j]) && strcmp(fn_table.entries[k].param[j]->tip->tip,"int")==0)) 
            {
                char error[100];
                char aux[100];
                strcpy(error,"Parameter type of function ");
                strcat(error, "is not ");
                strcat(error,fn_table.entries[k].param[j]->tip->tip);
                strcat(error, ".");
                yyerror(strdup(error));
                exit(0);
            }
            else if (!isNumeric(parameters[j]) && !(validateString(parameters[j]) && strcmp(fn_table.entries[k].param[j]->tip->tip,"string")==0)) 
            {
                char error[100];
                char aux[100];
                strcpy(error,"Parameter type of function ");
                strcat(error, "is not ");
                strcat(error,fn_table.entries[k].param[j]->tip->tip);
                strcat(error, ".");
                yyerror(strdup(error));
                exit(0);
            }
            
            else if((float_test(parameters[j]) && strcmp(fn_table.entries[k].param[j]->tip->tip,"float")==0))
            {
                char error[100];
                char aux[100];
                strcpy(error,"Parameter type of function ");
                strcat(error, "is not ");
                strcat(error,fn_table.entries[k].param[j]->tip->tip);
                strcat(error, ".");
                yyerror(strdup(error));
                exit(0);
            }
        }
    }
}
int get_typeof(char* s)
{
    int i=0;
    for(i=0;i<sy_table.nr_entries;i++)
    {
        if(strcmp(s,sy_table.entries[i].nume)==0)
            break;
    }
    if(i==sy_table.nr_entries)
    {
        int j=0;
        for(j=0;j<fn_table.nr_entries;j++)
        {
            if(strcmp(s,fn_table.entries[j].name)==0)
                break;
        }
        if(strcmp(fn_table.entries[j].return_type->tip,"int")==0)
        {
            return 1;
        }
        else if(strcmp(fn_table.entries[j].return_type->tip,"float")==0)
        {
            return 2;
        }
        else if(strcmp(fn_table.entries[j].return_type->tip,"char")==0)
        {
            return 3;
        }
        else if(strcmp(fn_table.entries[j].return_type->tip,"string")==0)
        {
            return 4;
        }
        else if(strcmp(fn_table.entries[j].return_type->tip,"bool")==0)
        {
            return 5;
        }
    }
    else
    {
        if(strcmp(sy_table.entries[i].tip->tip,"int")==0)
        {
            return 1;
        }
        else if(strcmp(sy_table.entries[i].tip->tip,"float")==0)
        {
            return 2;
        }
        else if(strcmp(sy_table.entries[i].tip->tip,"char")==0)
        {
            return 3;
        }
        else if(strcmp(sy_table.entries[i].tip->tip,"string")==0)
        {
            return 4;
        }
        else if(strcmp(sy_table.entries[i].tip->tip,"bool")==0)
        {
            return 5;
        }
        else {
            int k = 0;
            for(k = 0; k < userdef_table.nr_dimensiuni; k++) {
                if(strcmp(((struct UserDef*)(userdef_table.dimensiune[k]))->nume, sy_table.entries[i].tip->tip) == 0) {
                    return k + 6;
                }
            }
        }
    }
}
void export_sy_table() {
    int fd = open("symbol_table.txt", O_CREAT | O_TRUNC | O_WRONLY, 0750);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    char entry[300];

    for(int i = 0; i < sy_table.nr_entries; ++i) {
        int size = 1;
        for(int j=0;j<sy_table.entries[i].tip->size->nr_dimensiuni;j++)
        {
            size=size*(*((int*)(sy_table.entries[i].tip->size->dimensiune[j])));
        }
        sprintf(entry, "Nume: %s, Tip:%s, Const?:%d, size:%d\n", 
                                        sy_table.entries[i].nume, 
                                        sy_table.entries[i].tip->tip, 
                                        sy_table.entries[i].tip->is_const,
                                        size);
        if ( 0 > write(fd, entry, strlen(entry))) {
            perror("write");
        }
    }
    close(fd);
}
void export_fn_table() 
{
    int fd = open("symbol_table_functions.txt", O_CREAT | O_TRUNC | O_WRONLY, 0750);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    char entry[4000];
    char temp[300];

    for(int i = 0; i < fn_table.nr_entries; ++i) {
        bzero(entry, 4000);
        sprintf(entry, "{\nName: %s,\nRet_type: ", fn_table.entries[i].name);
        
        int size = 1;
        for(int j=0;j<fn_table.entries[i].return_type->size->nr_dimensiuni;j++)
        {
            size=size * (*((int*)(fn_table.entries[i].return_type->size->dimensiune[j])));
        }
        
        sprintf(temp,"{Tip:%s, Const?:%d, size:%d}",
                                        fn_table.entries[i].return_type->tip, 
                                        fn_table.entries[i].return_type->is_const,
                                        size);
        strcat(entry,temp);
        strcat(entry,",\nParams : [\n");
        for(int k = 0 ; k < fn_table.entries[i].nr_param; k++ ) {
            int size = 1;
            for(int j=0;j<fn_table.entries[i].param[k]->tip->size->nr_dimensiuni;j++)
            {
                size=size*(*((int*)(fn_table.entries[i].param[k]->tip->size->dimensiune[j])));
            }
            

            sprintf(temp, "\t{Nume: %s, Tip:%s, Const?:%d, size:%d}\n",
                                        fn_table.entries[i].param[k]->nume, 
                                        fn_table.entries[i].param[k]->tip->tip, 
                                        fn_table.entries[i].param[k]->tip->is_const,
                                        size);
            strcat(entry,temp);

        }
        strcat(entry,"\t]\n}\n");
        if ( 0 > write(fd, entry, strlen(entry))) {
            perror("write");
        }
    }
    close(fd);
}
struct AstNode* buildAST(char* root, struct AstNode* left, struct AstNode* right, int type)
{
    struct AstNode* self = malloc(sizeof(struct AstNode));
    self->Left = left; self->Right = right;
    self->tip = type;

    if(type == INT)
    {
        self->valoare = *((int*)root);
        //printf("%d\n",self->valoare);
    }
    else if(type == OP) 
    {
        //printf("operator %c\n", *((char*)root));
        self->valoare = *((char*)root);
    }
    else if(type == IDENTIFIER) 
    {
        int i=0;
        //printf("Looking for var %s\n",root);
        for(i=0;i<sym_table->nr_entries;i++)
        {
            if(strcmp(root,sym_table->entries[i].nume)==0) {
                self->valoare = i;
                //printf("ID index: %d\n", i);
                self->valoare = i;
                break;
            }
        }
        if(i == sym_table->nr_entries) {
            printf("EvalERROR: Variable not found\n");
            exit(1);
        }
    }
    else if (type == FNC) {
        int i=0;
        //printf("Looking for fnc %s\n",root);
        for(i=0;i<sym_table->nr_entries;i++)
        {
            if(strcmp(root,fn_table.entries[i].name)==0) {
                self->valoare = i;
                //printf("FNC index: %d\n", i);
                break;
            }
        }
        if(i == fn_table.nr_entries) {
            printf("EvalERROR: Variable not found\n");
            exit(1);
        }

    }
    else {
        self->valoare = 0;
    }
    //printf("%d, %d\n",self->valoare,self->tip);
    return self;
}
int is_ASTint(struct AstNode* root) {
    int left = 1;
    int right = 1;
    int self = 1;
    if(root->Left != 0) {
        left = is_ASTint(root->Left);
    }
    if(root->Right != 0) {
        right = is_ASTint(root->Right);
    }
    if (root->tip == FNC) {
        if(strcmp(fn_table.entries[root->valoare].return_type->tip, "int") != 0)
            self = 0;
    }
    else if (root->tip == IDENTIFIER) {
        if(strcmp(sym_table->entries[root->valoare].tip->tip, "int") != 0)
            self = 0;
    }
    else if (root->tip != INT && root->tip != OP) {
        self = 0;
    }
    return (self && left && right);
}
void freeAST(struct AstNode* self) {
    if (self->Left != 0) {
        freeAST(self->Left);
    }
    if (self->Left != 0) {
        freeAST(self->Right);
    }
    //?free(tip);
    free(self);
}
int EvalAST(struct AstNode* root) {
    if(root->tip == INT) 
    {
        return root->valoare;
    }
    else if (root->tip == OP) {
        switch (root->valoare)
        {
        case '+':
            return (EvalAST(root->Left) + EvalAST(root->Right));
        case '-':
            return (EvalAST(root->Left) - EvalAST(root->Right));
        case '*':
            return EvalAST(root->Left) * EvalAST(root->Right);
        case '/':
            return EvalAST(root->Left) / EvalAST(root->Right);
        default:
            yyerror("Unknown operator");
            exit(0);
        }
    }
    else if (root->tip == IDENTIFIER) {
        if(strcmp(sym_table->entries[root->valoare].tip->tip, "int") == 0)
            return *((int*)(sym_table->entries[root->valoare].valoare));
        else 
            return 0;
    }
    else if (root->tip == FNC) {
        printf("NOTE : Function found, since function calls are not implemented it will return 0.\tLINE : %d\n",yylineno);
        return 0;
    }
    else {
        return -1;
    }
}
void assign(int index, struct AstNode* root) {
    if(index < 0 || index >= sym_table->nr_entries) {
        yyerror("Variable index is out of bounds.");
        exit(2);
    }
    if (sym_table->entries[index].tip->is_const == 1) {
        yyerror("Cannot assign to const variable");
        exit(0);
    }
    if(is_ASTint(root)) {
        *((int*)(sym_table->entries[index].valoare)) = EvalAST(root);
    }
    else {
        printf("NOTE : Assignment works only on int\tLINE : %d\n",yylineno);
    }
}