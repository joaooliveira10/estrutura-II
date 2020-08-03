#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "DoublyLinkedList.c"


void initHash(HashStruct *hashStruct){
}
bool isHashEmpty(HashStruct *hashStruct){
}
int hash(char *key){ //( Dupla 3- rubia e cristian)
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os cÃ³digos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    return sum%MAX; //retorna o resto da divisÃ£o
}
//Dupla 4 - AndrÃ© e Danubia
int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    DoublyLinkedList * aux; 

    int hashCode = hash(key);
    printf("hash:%d\n",hashCode);

    return 1;
}
// Caroline e Gabriel
bool containsKey(HashStruct *hashStruct, char *key, compare equal){
	 //calcula a posição
    int hashValue = hash(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    
    return (pos!=-1)?true:false;
}
void* get(HashStruct *hashStruct, char *key, compare equal){
}
void* removeKey(HashStruct *hashStruct, char *key, compare equal){
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
    return result;
}

void showHashStruct(HashStruct *hashStruct){
}
