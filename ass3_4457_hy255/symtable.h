/*
    Loukas Mertzanis 4457
    HY255 - Ex03
    symtable.h
*/

#ifndef _SYMTABLE_H_ /*Prevents double declaration*/
#define _SYMTABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct SymTable* SymTable_T;

/*Returns a new empty SymbolTable*/
SymTable_T SymTable_new(void);

/*Frees memory used by oSymTable*/
void SymTable_free(SymTable_T oSymTable);

/*Returns the number of bindings contained in oSymTable*/
unsigned int SymTable_getLength(SymTable_T oSymTable);

/*Adds a new binding with pcKey and pvValue and returns 1.
If a binding with the same key as pcKey is already existent,
no changes are made to the oSymTable and 0 is returned*/
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue);

/*Removes binding with key same as pcKey from the oSymTable and returns 1.
If such a binding does not exist, no changes are made and 0 is returned*/
int SymTable_remove(SymTable_T oSymTable, const char *pcKey);

/*Returns 1 if there is a binding in oSymTable with key
same as pcKey, or 0 otherwise*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey);

/*Returns binding value of oSymTable with key same as pcKey,
or 0 if such a key is not existent*/
void* SymTable_get(SymTable_T oSymTable, const char *pcKey);

/*Applies pfApply function to every binding contained in oSymTable*/
void SymTable_map(SymTable_T oSymTable,
void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),
const void *pvExtra);

#endif