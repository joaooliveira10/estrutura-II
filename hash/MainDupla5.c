#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;

bool comparaChaves(void *key, void *data) {
    char chave = (char)key;
    Cliente c = (Cliente)data;

    return (strcmp (chave, c->email) == 0)?true:false;
}

void printCliente(void *data) {
    Cliente cliente = (Cliente)data;
    printf("{%s,%s} - ", cliente->nome, cliente->email);
}

int main() {
    HashStruct hash;
    initHash(&hashe);

    Cliente caroline = (Cliente) malloc(sizeof(Cliente));
    strcpy(caroline->nome,"caroline");
    strcpy(caroline->email,"loracliny50@gmail.com");
    put(&hash,caroline->email,caroline,comparaChaves);


    Cliente maria = (Cliente) malloc(sizeof(Cliente));
    strcpy(maria->nome,"maria");
    strcpy(maria->email,"maria@gmail.com");
    put(&hash,maria->email,maria,comparaChaves);

    showHashStruct(&hash, printCliente);
return 0;
}