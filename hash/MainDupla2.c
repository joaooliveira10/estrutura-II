#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.c"

typedef struct pessoa{
    char nome[50];
    char email[50];
}pessoa;

bool comparachave(void *data, void *key){
    char *chave = (char*)key;
    pessoa *c = (pessoa*)data;

    return(strcmp(chave, c->email) == 0 )?true:false;
    /*strcmp(chave,email);
    Onde chave e email s�o vari�veis do tipo string que devem ser comparadas.
    A fun��o strcmp() pode retornar um valor nulo (zero), positivo ou negativo.
    Quando as palavras comparadas s�o iguais, a fun��o retorna 0. */
}
void printcliente(void *data) {
    pessoa *a = (pessoa*)data;
    printf("{%s,%s}  ", a->nome, a->email);
}

int main(){
    HashStruct hash_list;

    initHash(&hash_list);
    printf("\n%d", hash("brunoferreirasmv@gmail.com"));


    pessoa *c1 = (pessoa *)malloc(sizeof(pessoa));
    strcpy(c1->nome,"bruno ferreira santos");
    strcpy(c1->email,"brunoferreirasmv@gmail.com");
    printf("\n%d",hash(c1->email));

    put(&hash_list, c1->email, c1, comparachave);

    printf("\n%d",hash_list.hashes[hash("brunoferreirasmv@gmail.com")].size);
    printf("\n%d",hash_list.size);
    printf("\n%d",containsKey(&hash_list, "brunoferreirasmv@gmail.com", comparachave));

    pessoa *person = (pessoa*)get(&hash_list, "brunoferreirasmv@gmail.com", comparachave);
    printf("%s\n",person->nome);

    c1 = (pessoa *)malloc(sizeof(pessoa));
    strcpy(c1->nome,"Maria") ;
    strcpy(c1->email,"maria@email.br");
    put(&hash_list, c1->email, c1, comparachave);

    c1 = (pessoa *)malloc(sizeof(pessoa));
    strcpy(c1->nome,"Pedro") ;
    strcpy(c1->email,"pedro@email.com.br");
    put(&hash_list, c1->email, c1, comparachave);

    c1 = (pessoa *)malloc(sizeof(pessoa));
    strcpy(c1->nome,"Carla") ;
    strcpy(c1->email,"carla@gmail.com.br");
    put(&hash_list, c1->email, c1, comparachave);


    showHashStruct(&hash_list, printcliente);
    return 1;
}
