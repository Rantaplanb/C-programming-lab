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

struct node{
    char* key;
    void* value;
    struct node* next;
};

struct SymTable{
    struct node* head;
};

/*Returns a new empty SymbolTable or NULL if allocation fails*/
SymTable_T SymTable_new(void)
{
    SymTable_T newTable = (SymTable_T)malloc(sizeof(struct SymTable));
    if(newTable == NULL){
        fprintf(stderr, "Memory allocation failed!");
        return NULL;
    }
    newTable->head = NULL;
    return newTable;
}

/*Frees memory used by oSymTable*/
void SymTable_free(SymTable_T oSymTable)
{
    struct node* tmp;
    struct node* current;
    if(oSymTable == NULL) return;
    /*Traverse the list and free nodes*/
    current = oSymTable->head;
    for(; current != NULL; current = tmp){
        tmp = current->next;
        free(current->key);
        /*free(current->value);*/
        free(current);
    }
    free(oSymTable);
}

/*Returns the number of bindings contained in oSymTable*/
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
    unsigned int ctr;
    struct node* tmp = oSymTable->head;
    assert(oSymTable);
    for(ctr=0; tmp; ctr++)
        tmp = tmp->next;
    return ctr;
}

/*Returns 1 if there is a binding in oSymTable with key
same as pcKey, or 0 otherwise*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
    struct node* tmp;
    assert(oSymTable);
    assert(pcKey);
    tmp = oSymTable->head;
    for(;tmp; tmp = tmp->next)
        if(!strcmp(tmp->key, pcKey))
            return 1;
    return 0;
}

/*Adds a new binding with pcKey and pvValue and returns 1.
If a binding with the same key as pcKey is already existent,
no changes are made to the oSymTable and 0 is returned*/
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue)
{
    struct node* newNode;
	int flag;
    assert(oSymTable);
    assert(pcKey);
    /*assert(pvValue);*/
    flag = SymTable_contains(oSymTable, pcKey);
    if(flag) return 0; /*Node is already existent*/
    newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed!");
        return 0;
    }
    newNode->key = (char*)malloc(sizeof(pcKey));
    if(newNode->key == NULL){
        fprintf(stderr, "Memory allocation failed!");
        return 0;
    }
    strcpy(newNode->key, pcKey);
    newNode->value = (void*)pvValue;
    newNode->next = oSymTable->head;
    oSymTable->head = newNode;
    return 1;
}

/*Removes binding with key same as pcKey from the oSymTable and returns 1.
If such a binding does not exist, no changes are made and 0 is returned*/
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
    struct node* previous = NULL;
    struct node* current;
    assert(oSymTable);
    assert(pcKey);
    /*Search for node with pcKey*/
    for(current = oSymTable->head; current; current = current->next)
        if(!strcmp(current->key, pcKey)) break;
        else previous = current;
    if(current == NULL) return 0; /*Node with pcKey not contained*/
    if(current == oSymTable->head) /*Delete 1st node*/
        oSymTable->head = current->next;
    else
        previous->next = current->next;
    free(current->key);
    /*free(current->value);*/
    free(current);
    return 1;
}

/*Returns binding value of oSymTable with key same as pcKey,
or NULL if such a key is not existent*/
void* SymTable_get(SymTable_T oSymTable, const char *pcKey)
{
    struct node* tmp;
    assert(oSymTable);
    assert(pcKey);
    for(tmp = oSymTable->head; tmp; tmp = tmp->next)
        if(!strcmp(tmp->key, pcKey))
            return tmp->value;
    return NULL;
}

/*Applies pfApply function to every binding contained in oSymTable*/
void SymTable_map(SymTable_T oSymTable,
void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),
const void *pvExtra)
{
    struct node* tmp;
    assert(oSymTable);
    assert(pfApply);
    for(tmp = oSymTable->head; tmp; tmp = tmp->next)
        pfApply((const char*)tmp->key, tmp->value, (void*)pvExtra);
    return;
}