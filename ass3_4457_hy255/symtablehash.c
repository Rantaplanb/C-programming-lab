/*
    Loukas Mertzanis 4457
    HY255 - Ex03
    symtablehash.c
*/

#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HASH_MULTIPLIER 65599
#define TABLE_SIZE 509

struct SymTable{
    struct node* array[TABLE_SIZE];
};

struct node{
    char* key;
    void* value;
    struct node* next;
};

/*Returns index for hash table. Range: 0 - TABLE_SIZE-1 */
static unsigned int Hash(const char *pcKey)
{

    size_t ui;
    unsigned int uiHash = 0U;
    assert(pcKey);
    for (ui = 0U; pcKey[ui] != '\0'; ui++)
        uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
    /*return value must be in range of table indexes(0-508)*/
    return uiHash % TABLE_SIZE;
}

/*Returns a new empty SymbolTable or NULL if allocation fails*/
SymTable_T SymTable_new(void)
{
    int i;
    SymTable_T newTable = (SymTable_T)malloc(sizeof(struct SymTable));
    if(newTable == NULL){
        fprintf(stderr, "Memory allocation failed!");
        return NULL;
    }
    /*Initialize all linked list head pointers to null*/
    for(i=0; i<TABLE_SIZE; i++)
        newTable->array[i] = NULL;
    return newTable;
}

/*Frees memory used by oSymTable*/
void SymTable_free(SymTable_T oSymTable)
{
    int i;
    struct node* tmp;
    struct node* current;
    assert(oSymTable);
    for(i=0; i<TABLE_SIZE; i++){
        current = oSymTable->array[i];
        for(; current != NULL; current = tmp){
            tmp = current->next;
            free(current->key);
            /*free(current->value);*/
            free(current);
        }
    }
    free(oSymTable);
}

/*Returns the number of bindings contained in oSymTable*/
unsigned int SymTable_getLength(SymTable_T oSymTable)
{
    int i;
    unsigned int nodes = 0;
    struct node* tmp;
    assert(oSymTable);
    for(i=0; i<TABLE_SIZE; i++){
        for(tmp = oSymTable->array[i]; tmp; tmp=tmp->next)
            nodes++;
    }
    return nodes;
}

/*Returns 1 if there is a binding in oSymTable with key
same as pcKey, or 0 otherwise*/
int SymTable_contains(SymTable_T oSymTable, const char *pcKey)
{
    struct node* tmp;
    unsigned int index = Hash(pcKey);
    assert(oSymTable);
    assert(pcKey);
    for(tmp = oSymTable->array[index]; tmp; tmp = tmp->next)
        if(!strcmp(tmp->key, pcKey))
            return 1;
    return 0; /*Not found*/
}

/*Adds a new binding with pcKey and pvValue and returns 1.
If a binding with the same key as pcKey is already existent,
no changes are made to the oSymTable and 0 is returned*/
int SymTable_put(SymTable_T oSymTable, const char *pcKey, const void *pvValue)
{
    struct node* newNode;
    int index = Hash(pcKey);
    assert(oSymTable);
    assert(pcKey);
    if(SymTable_contains(oSymTable, pcKey))
        return 0;
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
    newNode->next = oSymTable->array[index];
    oSymTable->array[index] = newNode;
    return 1;
}

/*Removes binding with key same as pcKey from the oSymTable and returns 1.
If such a binding does not exist, no changes are made and 0 is returned*/
int SymTable_remove(SymTable_T oSymTable, const char *pcKey)
{
    int index;
    struct node* previous = NULL;
    struct node* current;
    assert(oSymTable);
    assert(pcKey);
    index = Hash(pcKey);
    for(current = oSymTable->array[index]; current; current = current->next)
        if(!strcmp(current->key, pcKey)) break;
        else previous = current;
    if(current == NULL) return 0; /*node with pcKey not contained*/
    if(current == oSymTable->array[index]) /*Delete 1st node*/
        oSymTable->array[index] = current->next;
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
    int index;
    assert(oSymTable);
    assert(pcKey);
    index = Hash(pcKey);
    for(tmp = oSymTable->array[index]; tmp; tmp = tmp->next)
        if(!strcmp(tmp->key, pcKey))
            return tmp->value;
    return NULL;
}

/*Applies pfApply function to every binding contained in oSymTable*/
void SymTable_map(SymTable_T oSymTable,
void (*pfApply)(const char *pcKey, void *pvValue, void *pvExtra),
const void *pvExtra)
{
    int i;
    struct node* tmp;
    assert(oSymTable);
    assert(pfApply);
    for(i=0; i<TABLE_SIZE; i++)
        for(tmp = oSymTable->array[i]; tmp; tmp = tmp->next)
            pfApply((const char*)tmp->key, tmp->value, (void*)pvExtra);
    return;
}
