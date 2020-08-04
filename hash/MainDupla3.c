#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
// MAIN CRISTIAN e RUBIA
typedef struct Cliente {
    char nome[50];
    char email[50];
} Cliente;

bool comparaChaves(void *key, void *data) {
    char *chave = (char*)key;
    Cliente *c = (Cliente*)data;
    
    return (strcmp (chave, c->email) == 0)?true:false;
}

void printCliente(void *data) {
    Cliente *cliente = (Cliente*)data;
    printf("{%s, %s}\n", cliente->nome, cliente->email);
}

int menu()
{
    printf("+---------[TABELA HASH]---------+\n");
    printf("|[1] -- inserir um cliente      |\n");
    printf("|[2] -- exibir o hash           |\n");
    printf("|[3] -- sair                    |\n");
    printf("+-------------------------------+\n");
    printf("Insira a opcao: ");

    int opcao = 0;
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    char chave[50];
    int posicao = 0;
    
    HashStruct hashStruct;
    initHash(&hashStruct);

    bool sair = false;

    while (!sair)
    {
        switch(menu())
        {
        case 1:
        {
            Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));
            printf("Insira o nome: ");
            scanf("%s", cliente->nome);

            printf("Insira o email: ");
            scanf("%s", cliente->email);

            put(&hashStruct, cliente->email, cliente, comparaChaves);
            break;
        }
        case 2:
            showHashStruct(&hashStruct, printCliente);
            break;
        case 3:
            printf("Saindo...\n");
            sair = true;
            break;
        }
    }

    return 0;
}