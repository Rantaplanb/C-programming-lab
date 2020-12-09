/*
    Loukas Mertzanis 4457
    HY255 - Ex03
    symtablelist.c
*/

#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define TEST_SIZE 1000

void printStudent(const char* AM, void* Name, void* pvExtra)
{
    printf("AM%s\tName: %s\n",AM, (char*)Name);
}

char *randstring(unsigned int length) {

    static char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *randomString = NULL;
    int n;
    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            for (n = 0;n < length;n++) {
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }
    return randomString;
}

int main()
{
    int i;
    char bufferAM[10];
    char* name;
    SymTable_T table = SymTable_new();
    /*Add TEST_SIZE bindings to the symbol table with 'random' names as values, and AM's as keys*/
    for(i=3000; i<(3000+TEST_SIZE); i++){
        sprintf(bufferAM, "%d", i);
        name = (char*)malloc(15);
        name = randstring(14); /*pseudorandom 14*char string*/
        SymTable_put(table, bufferAM, name);
    }

    printf("The table contains %d bindings!\n", SymTable_getLength(table));

    SymTable_put(table, "4457", "Loukas Mertzanis");
    SymTable_put(table, "9999", "DEN EIMAI CSDas!");
    SymTable_put(table, "4511", "Kapoios Sunadelfos");
    if(SymTable_remove(table, "9999"))
        printf("Removal was successfull!\n");
    else
        printf("Such a key does not exist!\n");

    if(SymTable_contains(table, "4457"))
        printf("There is a binding with such a key!\n");
    else
        printf("There is not a binding with such a key\n");

    printf("%s\n", (char*)SymTable_get(table, "4511"));
    printf("All the bindings contained in the table:\n");
    SymTable_map(table,printStudent,"");
    SymTable_free(table);
    printf("Memory deallocated successfully!\nAll operations were successful, exiting...");
	
    return 0;
}
