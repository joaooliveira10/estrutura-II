#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct){
}
bool isHashEmpty(HashStruct *hashStruct){
}
int hash(char *key){
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
