#include <assert.h>
#include <string.h>
#include "BinarySearchTree.h"


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
    assert(el != NULL);
    el->key = 45;
    snprintf(el->value, 10, "Val 45");
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL);
    el->key = 60;
    snprintf(el->value, 10, "Val 60");
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL);
    el->key = 50;
    snprintf(el->value, 10, "Val 50");
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);
    
    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    assert(el != NULL);
    el->key = 53;
    snprintf(el->value, 10, "Val 53");
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == 1);
    assert(add(&tree, el, &BinarySearchTreeElementComparator) == -1);
    
    
    findEl.key = 50;
    assert(find(tree, (void *) &findEl, &BinarySearchTreeElementComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 50") == 0);
    
    findEl.key = 53;
    assert(find(tree, &findEl, &BinarySearchTreeElementComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 53") == 0);
    
    findEl.key = 45;
    assert(find(tree, &findEl, &BinarySearchTreeElementComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 45") == 0);
    
    findEl.key = 60;
    assert(find(tree, &findEl, &BinarySearchTreeElementComparator,
                (void **) &el) == 1);
    assert(strcmp(el->value, "Val 60") == 0);
    
    // Tentativa que não encontra na árvore
    findEl.key = 10;
    assert(find(tree, &findEl, &BinarySearchTreeElementComparator,
                (void **) &el) == 0);

    el = (BinarySearchTreeElement *) malloc(sizeof(BinarySearchTreeElement));
    el->key=45;
    removeTreeNode(&tree, el, &BinarySearchTreeElementComparator);
    
    in_order(tree, printInteger);
    printf("\n");
    pre_order(tree, printInteger);
    printf("\n");
    post_order(tree, printInteger);
    printf("\n");
    printf("Altura: %d ", height(tree));
    printf("\n");
    destroy(&tree);
    
    in_order(tree, printInteger);
    assert(tree == NULL);
    printf("\n");
    return 0;
}