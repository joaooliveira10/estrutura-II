#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;

bool comparaChaves(void *key, void *data) {
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    
    return (strcmp (chave, c->email) == 0)?true:false;
}

void printCliente(void *data) {
    Cliente *cliente = (Cliente*)data;
    printf("{%s,%s} - ", cliente->nome, cliente->email);
}

int main() {
    HashStruct hashes;
    initHash(&hashes);
    
    Cliente *andre = (Cliente*) malloc(sizeof(Cliente));
    strcpy(andre->nome,"André");
    strcpy(andre->email,"andre@gmail.com");
    int x = put(&hashes,andre->email,andre,comparaChaves);
    printf("x:%d",x);


return 0;
}
