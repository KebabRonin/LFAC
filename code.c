#include <fcntl.h>
#include <sys/types.h>
#include "code.h"

static struct tabela_simboluri sy_table;

void new_entry(char* nume, int is_const, char* tip, char* valoare) {
	struct simbol newentry;
    printf("Entered new entry\n");
	newentry.nume = strdup(nume);
	newentry.tip->tip = strdup(tip);
	newentry.tip->is_const = is_const;

	if(0 == strcmp(tip,"int")) {
		newentry.valoare = (char*) malloc(sizeof(int));
        if (valoare != 0)
    		*((int*)newentry.valoare) = *((int*) valoare);
        else 
            *((int*)newentry.valoare) = 0;
	}
	else if(0 == strcmp(tip,"bool")) {
		newentry.valoare = malloc(sizeof(char));
		if (valoare != 0)
    		*((char*)newentry.valoare) = *((char*) valoare);
        else 
            *((char*)newentry.valoare) = 0;
	}
	else if(0 == strcmp(tip,"float")) {
		newentry.valoare = malloc(sizeof(float));
		*(newentry.valoare) = *((float*) valoare);
	}
	else if(0 == strcmp(tip,"char")) {
		newentry.valoare = malloc(sizeof(char));
		*(newentry.valoare) = *((char*) valoare);
	}
	else if(0 == strcmp(tip,"string")) {
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

    for( int i = 0; i < sy_table.nr_entries; ++i) {
        printf("sak\n");
        //bzero(entry, 299);
        sprintf(entry, "Nume: %s, Tip:%s, Const?:%d\n", sy_table.entries[i].nume, sy_table.entries[i].tip->tip, sy_table.entries[i].tip->is_const);
        printf("%s\n",entry);
        if ( 0 > write(fd, entry, strlen(entry))) {
            perror("write");
        }
    }
    close(fd);
}