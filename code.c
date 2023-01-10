#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include "code.h"

static struct tabela_simboluri sy_table;
static struct tabela_functii   fn_table;

void new_entry_sy(char* nume, int is_const, char* tip, char* valoare, struct list* matrix) 
{
	
    int i=0;
    for(i=0;i< sy_table.nr_entries; i++)
    {
        if(strcmp(sy_table.entries[i].nume,nume)==0)
        {
            yyerror("Variable already declared.");
            exit(0);
        }
    }

    struct simbol newentry;
    newentry.tip = malloc(sizeof(struct Tip_Date));
    printf("Entered new entry\n");
	newentry.nume = strdup(nume);
	newentry.tip->tip = strdup(tip);
	newentry.tip->is_const = is_const;
    if(matrix==NULL)
    {
        printf("Matrix null\n");
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
		*((char*)newentry.valoare) = *((char*) valoare);
	}
	else if(0 == strcmp(tip,"string")) {
        newentry.valoare = malloc(sizeof(char*) * size);
        memset(newentry.valoare,NULL,sizeof(char*) * size);
        if (valoare != 0)
    		newentry.valoare = strdup(valoare);
        else 
            newentry.valoare = strdup("");
		
	}
	sy_table.entries[sy_table.nr_entries++] = newentry;
}


void new_entry_fn(char* nume, struct Tip_Date* ret, struct list* param) 
{

    int j=0;
    for(j=0;j< sy_table.nr_entries; j++)
    {
        if(strcmp(sy_table.entries[j].nume,nume)==0)
        {
            yyerror("There already exists a variable with that name.\n");
            exit(0);
        }
    }
    int k=0;
    for(k=0;k< fn_table.nr_entries; k++)
    {
        if(strcmp(fn_table.entries[k].name,nume)==0)
        {
            yyerror("There already exists a function with that name.\n");
            exit(0);
        }
    }


	struct functie newentry;
    newentry.return_type = ret;
    printf("%p\n", newentry.return_type);
    newentry.name = strdup(nume);
    printf("Entered new FN entry\n");
	//newentry.return_type = ret;
    //memcpy(newentry.return_type, ret, sizeof(struct Tip_Date)); cu malloc!!

    // int size = 1;
    // for(int i=0;i<newentry.tip->size->nr_dimensiuni;i++)
    // {
    //     size=size*newentry.tip->size->dimensiune[i];
    // }

    newentry.nr_param = param->nr_dimensiuni;
    
	for (int i = 0; i < param->nr_dimensiuni; i++) {
        newentry.param[i] = param->dimensiune[i];
    }
    
	fn_table.entries[fn_table.nr_entries++] = newentry;
}


int exists_variable(char *s)
{
    int i=0;
    for(i=0;i<sy_table.nr_entries;i++)
    {
        if(strcmp(s,sy_table.entries[i].nume)==0)
            return 1;
    }
    return 0;
}

int exists_function(char *s)
{
    int i=0;
    for(i=0;i<fn_table.nr_entries;i++)
    {
        if(strcmp(s,fn_table.entries[i].name)==0)
            return 1;
    }
    return 0;
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
    printf("nr parametri = %d, nr parametri ceruti = %d\n",nr_parametri,fn_table.entries[i].nr_param);
    if(nr_parametri != fn_table.entries[i].nr_param)
    {
        yyerror("Argument type doesn't match.");
	    exit(0);
    }
    int j=0;
    for(j=0;j<nr_parametri;j++)
    {
        printf("Verificam parametrul %d : %s\n", j, parameters[j]);
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
            printf("tipul parametrului = %s, tipul cerut = %s\n",parameters[j],fn_table.entries[k].param[j]->tip->tip);
            yyerror("Argument type doesn't match.");
			exit(0);
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
        //printf("%s\n",entry);
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