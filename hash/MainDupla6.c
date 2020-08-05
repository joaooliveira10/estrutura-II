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
    printf("%d\n",hash("joaoangello10@gmail.com"));
    
    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    strcpy(c->nome,"Joao Angello") ;
    strcpy(c->email,"joaoangello10@gmail.com");
    printf("%d\n",hash(c->email));
    put(&hashes, c->email, c, comparaChaves);
    printf("%d\n",hashes.hashes[hash("joaoangello10@gmail.com")].size);
    printf("%d\n",hashes.size);
    printf("%d\n",containsKey(&hashes, "joaoangello10@gmail.com", comparaChaves));
    
    Cliente *cliente = (Cliente*)get(&hashes, "joaoangello10@gmail.com", comparaChaves);
    printf("%s\n",cliente->nome);
    

showHashStruct(&hashes, printCliente);
    return 0;
}
