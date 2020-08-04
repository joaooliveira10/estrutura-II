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
         printf("Key[%d]:%c",i,key[i]);
        sum+=key[i]*(i+1);
    }
    return sum%MAX; //retorna o resto da divisÃ£o
}
//Dupla 4 - Andre e Danubia
int put(HashStruct *hashStruct, char *key, void *data, compare equal){

    //teste sem a containsKey
    int pos = hash(key);

    int keyExist = indexOf(&hashStruct->hashes[pos],data,equal);

    if(keyExist < 0 || isEmpty(&hashStruct->hashes[pos])){
        enqueue(&hashStruct->hashes[pos],data);
        hashStruct[pos].size++;
        return 1;
    }
    return -1;
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
<<<<<<< HEAD
}
=======
}
>>>>>>> 40009f1973e6b36c0f32f3fa423eb3aeabc57056
