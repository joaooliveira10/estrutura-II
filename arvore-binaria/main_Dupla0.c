#include <string.h>

#include "BinarySearchTree.h"

// DUPLA 03 - RUBIA E CRISTIAN

//Estrutura criada para ser armazenada dentro da arvore
typedef struct buscabinaria {
    int key;
    char valor[10];
} buscabinaria;

// Essa função faz a comparação dos elementos para saber suas prioridades
// para saber qual nº será armazenado na esquerda e qual a direita
int comparadorInt(void *element1, void *element2) {
    
    buscabinaria *e1 = (buscabinaria *) element1;

    buscabinaria *e2 = (buscabinaria *) element2;

    if (e1->key > e2->key)
        return 1;
    if (e1->key < e2->key)
        return -1;

    return 0;

}

// Essa função irá receber os dados que foram armazenados
// e apresentará na tela um nº inteiro
void printInteiro(void *dados) {
    buscabinaria *b = (buscabinaria*)dados;
    printf("%d ", b->key);
}

int main(int argc, char** argv){
//nó de arvore declarado começa nulo 
TreeNode *tree = NULL;
  buscabinaria *elemento, localel;
  //pedimos espaço na memória para alocar um ponteiro do tipo busca binária
  elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
    if(elemento != NULL)
    elemento->key = 50;

    add(&tree, elemento, &comparadorInt);
    add(&tree, elemento, &comparadorInt);
     
  elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
    if(elemento != NULL)
    elemento->key = 51;

    add(&tree, elemento, &comparadorInt);
    add(&tree, elemento, &comparadorInt);

  elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
    if(elemento != NULL)
    elemento->key = 52;

    add(&tree, elemento, &comparadorInt);
    add(&tree, elemento, &comparadorInt);

  elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
    if(elemento != NULL)
    elemento->key = 53;

    add(&tree, elemento, &comparadorInt);
    add(&tree, elemento, &comparadorInt);

  elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
    if(elemento != NULL)
    elemento->key = 54;

    add(&tree, elemento, &comparadorInt);
    add(&tree, elemento, &comparadorInt);

  elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
    if(elemento != NULL)
    elemento->key = 55;

    add(&tree, elemento, &comparadorInt);
    add(&tree, elemento, &comparadorInt);

//sistema que printa os valores como se fossem calculadora polonesa
//printando a raiz em prmeiro, no meio e no final das árvores.
    in_order(tree, printInteiro);
    printf("\n");
    pre_order(tree, printInteiro);
    printf("\n");
    post_order(tree, printInteiro);
    printf("\n\n");

    //utilizando a função find para localizar a key e junto com a removeTreeNode para retirar o elemento 50 
    if(find(tree, &localel, &comparadorInt,(void **) &elemento) == 0){
      elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
      elemento->key=50;
      removeTreeNode(&tree, elemento, &comparadorInt);
    }
    
    in_order(tree, printInteiro);
    printf("\n");
    pre_order(tree, printInteiro);
    printf("\n");
    post_order(tree, printInteiro);
    printf("\n\n");
  
    //utilizando a função find para localizar a key e junto com a removeTreeNode para retirar o elemento 50 
  if(find(tree, &localel, &comparadorInt,(void **) &elemento) == 0){
      elemento = (buscabinaria *) malloc(sizeof(buscabinaria));
      elemento->key=51;
      removeTreeNode(&tree, elemento, &comparadorInt);
    }
    
    in_order(tree, printInteiro);
    printf("\n");
    pre_order(tree, printInteiro);
    printf("\n");
    post_order(tree, printInteiro);
    printf("\n\n");
  

}