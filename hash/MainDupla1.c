#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
typedef struct Cliente {
    char nome[50];
    char email[50];
}Cliente;
bool comparaChaves(void* key, void* data) {
    char* chave = (char*)key;
    Cliente* c = (Cliente*)data;

    return (strcmp(chave, c->email) == 0) ? true : false;
}
void printCliente(void* data) {
    Cliente* cliente = (Cliente*)data;
    printf("{%s,%s} - ", cliente->nome, cliente->email);
}
int main() {
    HashStruct hashes;
    initHash(&hashes);
    printf("%d\n", hash("victor.h.a.macedo@gmail.com"));
    Cliente* c = (Cliente*)malloc(sizeof(Cliente));
    strcpy(c->nome, "Victor Hugo");
    strcpy(c->email, "victor.h.a.macedo@gmail.com");
    printf("%d\n", hash(c->email));
    put(&hashes, c->email, c, comparaChaves);
    c = (Cliente*)malloc(sizeof(Cliente));
    strcpy(c->nome, "thays");
    strcpy(c->email, "thays@email.br");
    put(&hashes, c->email, c, comparaChaves);
    isHashEmpty(&hashes);
    showHashStruct(&hashes, printCliente);
    return 0;
}