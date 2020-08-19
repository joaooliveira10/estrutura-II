#include <assert.h>
#include <string.h>
#include "BinarySearchTree.h"

//Elemento que será guardado na árvore
typedef struct buscabinaria {
    int key;
    char valor[10];
} buscabinaria;

int comparadorInt(void *element1, void *element2) {
    
    buscabinaria *e1 = (buscabinaria *) element1;

    buscabinaria *e2 = (buscabinaria *) element2;

    if (e1->key > e2->key)
        return 1;
    if (e1->key < e2->key)
        return -1;

    return 0;

}

int main(int argc, char** argv){
  
  
    buscabinaria *elem, findEl;

     add_teste(1,2, comparadorInt);
     add_teste(3,3, comparadorInt);
     add_teste(12,2, comparadorInt);
     add_teste(13,15, comparadorInt);
     add_teste(4,6, comparadorInt);
}