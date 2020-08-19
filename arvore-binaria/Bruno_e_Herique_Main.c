#include "locale.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>
#include "BinarySearchTree.c"

// Bruno e Henrique
/*Elemento que será guardado*/
typedef struct objeto_conteudo{
    int key;
    char value[10];
}objeto_conteudo;

/*Função para comparação*/
static int binarysearch_treecomparator(void *element_1, void *element_2){
    objeto_conteudo *e1 = (objeto_conteudo*) element_1;
    objeto_conteudo *e2 = (objeto_conteudo*) element_2;

        if(e1->key > e2->key)return 1;

        return(e1->key < e2->key)? -1: 0;
}
/
void print_node(void *element){
    objeto_conteudo *dado = (objeto_conteudo*) element;

    printf("\n");
    printf(" chave %d ", dado->key);
    printf("\n\n");
    printf(" %s ", dado->value);
    printf("\n\n");

}
void aux_add(objeto_conteudo *el, TreeNode **raiz){
    el = (objeto_conteudo*)malloc(sizeof(objeto_conteudo));

    printf("\n digite valor: ");
    int valor;
    scanf("%d", &valor);
     el->key = valor;

    snprintf(el->value, 10, "val %d",valor);

    int resultado;
    resultado = add(raiz, el, &binarysearch_treecomparator);
    if(resultado == -1)
        printf("valor j� existe");

    int resp;
    printf("\n quer inserir outro elemento: 1-sim ou 2-n�o;");
    scanf("%d",&resp);
    if(resp == 1)
        aux_add(el, raiz);
}

// Bruno e Henrique

int main(){
    setlocale(LC_ALL,"portuguese");
    TreeNode *tree = NULL;
    objeto_conteudo *el;

    aux_add(el, &tree);
    system("cls");
    printf("\n qual chave deseja procurar ?");

    objeto_conteudo find_el;
    scanf("%d", &find_el.key);
    int resultado = find(tree, &find_el, &binarysearch_treecomparator, (void**)&el);
    if(resultado == 1){
        printf("\n A chave corresponde ao: %s", el->value);
    }else{
        printf("\n valor n�o encontrado");
    }

    int op;
    printf("\n\n Imprimir arvore");
    printf("\n 1 - in_order");
    printf("\n 2 - pre_order");
    printf("\n 3 - post_order");
    scanf("%d",&op);

    system("cls");
    switch(op){
    //Imprime os elementos raiz esquerda direita   
    case 1:
        printf("\n\n");
        in_order(tree, print_node);
    break;
    //Imprime os elementos esquerda direita raiz
    case 2:
        printf("\n\n");
        pre_order(tree, print_node);
    break;
    //Remove algum elemento
    case 3:
        printf("\n\n");
        post_order(tree, print_node);
    break;
    }

    printf("\n\n altura da arvore %d", height(tree));
    //Destrói a arvore
    destroy(&tree);
    if(tree==NULL){
        printf("\n\n arvore destruida");
    }
}

