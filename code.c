#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include "code.h"

static struct tabela_simboluri sy_table;

void new_entry(char* nume, int is_const, char* tip, char* valoare, struct MatrixInfo* matrix) {
    printf("%s\n",tip);
	struct simbol newentry;
    newentry.tip = malloc(sizeof(struct Tip_Date));
    printf("Entered new entry\n");
	newentry.nume = strdup(nume);
	newentry.tip->tip = strdup(tip);
	newentry.tip->is_const = is_const;
    if(matrix==NULL)
    {
        printf("Matrix null\n");
        newentry.size= malloc(sizeof(struct MatrixInfo));
        newentry.size->nr_paranteze = 0;
    }
    else
    {
        newentry.size = matrix;
    }

    int size = 1;
    for(int i=0;i<newentry.size->nr_paranteze;i++)
    {
        size=size*newentry.size->dimensiune[i];
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

void export_sy_table() {
    int fd = open("symbol_table.txt", O_CREAT | O_TRUNC | O_WRONLY, 0750);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    char entry[300];

    for(int i = 0; i < sy_table.nr_entries; ++i) {
        int size = 1;
        for(int j=0;j<sy_table.entries[i].size->nr_paranteze;j++)
        {
            size=size*sy_table.entries[i].size->dimensiune[j];
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

void export_sy_table() 
{
    int fd = open("symbol_table_functions.txt", O_CREAT | O_TRUNC | O_WRONLY, 0750);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    char entry[300];
}