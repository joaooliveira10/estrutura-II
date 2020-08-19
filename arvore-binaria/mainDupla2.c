/* 
    * Implementação da estrutura de dados de Árvore de Busca Binária
    * Grupos responsavel: André Geraldo e Danubia Macedo
    * Prof. Dr. João Paulo  D. Preti
    * 18 agosto de 2020.
*/ 

#include <assert.h>
#include <string.h>
#include "BinarySearchTree.h"

//Elemento que será guardado na árvore
typedef struct BinarySearchTreeElement {
    int key;
    char value[15];
}BinarySearchTreeElement;

//Função para comparar os elementos
static int BinarySearchTreeElementComparator(void *element1, void *element2){
    BinarySearchTreeElement * e1 = (BinarySearchTreeElement*) element1;
    BinarySearchTreeElement * e2 = (BinarySearchTreeElement*) element2;

    if(e1->key > e2->key) return 1;
    if(e1->key < e2->key) return -1;
    return 0;
}

void printInteger(void *data){
    BinarySearchTreeElement *d1 = (BinarySearchTreeElement*) data;
    printf("\n--- (%d): %s \n",d1->key,d1->value);
}


int main() {

    TreeNode * tree = NULL;

    BinarySearchTreeElement *el, findEl;

    el = (BinarySearchTreeElement*) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL);
    el->key = 8;
    snprintf(el->value,10,"Val 8");

    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);
    assert(add(&tree,el,BinarySearchTreeElementComparator) == -1 );

    el = (BinarySearchTreeElement*) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL);
    el->key = 10;
    snprintf(el->value,10,"Val 10");
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);


    el = (BinarySearchTreeElement*) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL);
    el->key = 3;
    snprintf(el->value,10,"Val 3");
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);
    

    printf("\nheight:%d\n",height(tree));
    printf("Antes da Remoção:\n");
    in_order(tree,printInteger);

    printf("\nremovedNode?%d\n",removeTreeNode(&tree,el,&BinarySearchTreeElementComparator));
    printf("\nPós-remoção\n");
    in_order(tree,printInteger);


    return 0;
}