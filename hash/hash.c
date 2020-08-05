#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "DoublyLinkedList.c"


void initHash(HashStruct *hashStruct) {
    for (int i=0;i<MAX;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}
bool isHashEmpty(HashStruct *hashStruct){
    return hashStruct->size == 0;
}
int hash(char *key){ //( Dupla 3- rubia e cristian)
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
         printf("Key[%d]:%c",i,key[i]);
        sum+=key[i]*(i+1);
    }
    return sum%MAX; //retorna o resto da divisão
}
//Dupla 4 - Andre e Danubia
int put(HashStruct *hashStruct, char *key, void *data, compare equal)  {
    if (!containsKey(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    return 0;
}
// Dupla 05 Caroline e Gabriel
bool containsKey(HashStruct *hashStruct, char *key, compare equal){
	 //calcula a posi��o
    int hashValue = hash(key);
    //busca na fila a posi��o da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);

    return (pos!=-1)?true:false;
}
void* get(HashStruct *hashStruct, char *key, compare equal) {
    // descobre em qual fila/lista está o dado
    int hashValue = hash(key);
    //first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    // procuramos o dado na lista
    while(aux!=hashStruct->hashes[hashValue].first && !equal(aux->data, key))
        aux=aux->next;

    return aux->data;
}

//Grupo 02 -Bruno e Henrique
void* removeKey(HashStruct *hashStruct, char *key, compare equal){
    //essa função encontra um dado utilizando uma lista, uma chave e
    //uma função de comparação, depois remove o dado.
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
    return result;
}

void showHashStruct(HashStruct *hashStruct, printNode print) {
    printf("There are %d elements in the Hash\n\n",hashStruct->size);
    for (int i=0; i < MAX; i++) {
        printf("Hash %d has %d elements: ",i,hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i],print);
        printf("\n");
    }
}
