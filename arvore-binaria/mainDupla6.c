 
    //Implementação da estrutura de dados de Árvore de Busca Binária
    // Aluna  responsavel: Caroline da Souza 

#include <assert.h>
#include <string.h>
#include "BinarySearchTree.h"

//Elemento que será guardado na árvore
typedef struct busca {
    int key;
    char valor[10];
} busca;

//Função para comparar os elementos
static int buscaComparator(void *element1, void *element2){
    busca * e1 = (busca*) element1;
    busca * e2 = (busca*) element2;

    if(e1->key > e2->key) return 1;
    if(e1->key < e2->key) return -1;
    return 0;
}


void printInteger(void *data){
    busca *d1 = (busca*) data;
    printf("\n--- (%d): %s \n",d1->key,d1->value);
}


int main() {

    TreeNode * tree = NULL;

    busca *el, findEl;
      // Adiciona alguns elementos
    el = (busca*) malloc(sizeof(busca));
    assert(el != NULL);
    el->key = 30;
    snprintf(el->value,10,"Val 30");

    assert(add(&tree, el, &busca) == 1);
    assert(add(&tree,el,buscaComparator) == -1 );

    el = (busca*) malloc(sizeof(busca));
    assert(el != NULL);
    el->key = 100;
    snprintf(el->value,10,"Val 100");
    assert(add(&tree, el, &buscaComparator) == 1);

    

    printf("\nheight:%d\n",height(tree));
    printf("Antes da Remoção:\n");
    in_order(tree,printInteger);

    printf("\nremovedNode?%d\n",removeTreeNode(&tree,el,&buscaComparator));
    printf("\nPós-remoção\n");
    in_order(tree,printInteger);


    return 0;
}