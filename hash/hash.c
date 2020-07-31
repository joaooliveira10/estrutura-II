#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct){
}
bool isHashEmpty(HashStruct *hashStruct){
}
int hash(char *key){ //( Dupla 3- rubia e cristian)
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    return sum%MAX; //retorna o resto da divisão
}
int put(HashStruct *hashStruct, char *key, void *data, compare equal){
}
bool containsKey(HashStruct *hashStruct, char *key, compare equal){
}
void* get(HashStruct *hashStruct, char *key, compare equal){
}
void* removeKey(HashStruct *hashStruct, char *key, compare equal){
}
void showHashStruct(HashStruct *hashStruct){
}
