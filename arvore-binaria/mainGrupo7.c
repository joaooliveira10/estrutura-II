#include <string.h>
#include "BinarySearchTree.h"

// Grupo 7 - Victor e Thays

//Elemento que será guardado na árvore
typedef struct BinarySearchTreeElement {
    int key;
    char value[10];
} BinarySearchTreeElement;

// Função para comparação dos elementos
static int BinarySearchTreeElementComparator(void *element1, void *element2) {
    BinarySearchTreeElement *e1 = (BinarySearchTreeElement *) element1;
    BinarySearchTreeElement *e2 = (BinarySearchTreeElement *) element2;
    
    if (e1->key > e2->key)
        return 1;
    if (e1->key < e2->key)
        return -1;

    return 0;
}

void printInteger(void *data) {
    BinarySearchTreeElement *bste = (BinarySearchTreeElement*)data;
    printf("%d ", bste->key);
}

int main(int argc, char **argv) {

    TreeNode *tree = NULL;
    BinarySearchTreeElement *el, findEl;
    
    // Adiciona alguns elementos
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));

    el->key = 45;
    printf(el->value, 10, "Val 45");
    add(&tree, el, &BinarySearchTreeElementComparator);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    el->key = 60;
    printf(el->value, 10, "Val 60");
    add(&tree, el, &BinarySearchTreeElementComparator);

    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    el->key = 50;
    printf(el->value, 10, "Val 50");
    add(&tree, el, &BinarySearchTreeElementComparator);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    el->key = 53;
    printf(el->value, 10, "Val 53");
    add(&tree, el, &BinarySearchTreeElementComparator);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    el->key = 55;
    printf(el->value, 10, "Val 55");
    add(&tree, el, &BinarySearchTreeElementComparator);
    
    
    
    in_order(tree, printInteger);
    printf("\n");
    pre_order(tree, printInteger);
    printf("\n");
    post_order(tree, printInteger);
    printf("\n");
  
   
   //depois que ele destroi a arvore a função in_order é chamada, se a arvore for nula ele mostra nulo, porque a arvore esta .
  destroy(&tree);
   in_order(tree, printInteger);
    if(tree == NULL)
    printf("\n");

    return 0;
}