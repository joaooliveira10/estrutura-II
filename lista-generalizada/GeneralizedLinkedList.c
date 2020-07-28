#include <stdio.h>
#include <stdlib.h>

#include "GeneralizedLinkedList.h" 

//Grupo 1 - Thays e Victor
// adiciona um átomo na lista
int addAtom(Node **list, int atom) {
    Node* node = (Node *) malloc(sizeof(Node));

    node->type = 0;
    node->atomList.atom = atom;
    node->next = NULL;

    // se o ponteiro que aponta para a lista for nulo
    if (*list == NULL) {
        *list = node;
        return EXIT_SUCCESS;
    }
    //Ponteiro last recebe o ponteiro list com uma variável do tipo nó
    Node *last = *list;
    //Enquanto last aponta para próximo que é diferente de nulo, a variável last recebe ela mesma apontando para o próximo
    while (last->next != NULL) {
        last = last->next;
    }
    // Last aponta para next que recebe o nó
    last->next = node;
    return EXIT_SUCCESS;
}

int addList(Node **list, Node **subList){
    //Grupo 2 - Bruno e Henrique

    Node *newnode =(Node*) malloc(sizeof(Node));
    newnode->atomList->list =(*subList);
    newnode->type = 1;
    newnode->next = NULL;

    if((*list) == NULL){
        (*list) = newnode;
        return 1;

    }else if((*subList)->atomList.atom < (*list)->atomList.atom){
        Node *aux =(Node*) malloc(sizeof(Node));
        aux = (*list);
        newnode->next = aux;
        (*list) = newnode;
    }else{
        Node *aux =(Node*) malloc(sizeof(Node));
        aux = (*list);
        int atomo =(*subList)->atomList.atom;
        while(atomo > aux->next->atomList.atom && aux->next != NULL)
            aux = aux->next;
        if(aux->next != NULL){
            Node *aux2 =(Node*) malloc(sizeof(Node));
            aux2 = aux->next;
            aux->next = newnode;
            newnode->next = aux2;
        }
        aux->next = newnode;
    return 1;
    }
    return -1;

}
// Grupo3- Cristian e Rubia
// retorna o primeiro elemento da lista (átomo ou lista)
Node *head(Node *list) {
  //se lista for nula 
    if (list == NULL) 
    {  // ele retornará "[]" 
        return NULL;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    node->type = list->type;
    node->next = NULL;

    switch (list->type) {
      // caso a lista for do tipo 0 , ele será considerado do tipo atomo, o nó apontará para a lista de atomos. 
    case 0:
        node->atomList.atom = list->atomList.atom;
        break;
      // caso lista for do tipo 1 , ele será considerado do tipo "sublista", ai o nó apontará para a lista de sublista. 
    case 1:
        node->atomList.list = list->atomList.list;
        break;
    }
    
    return node;
}
// Grupo3- Cristian e Rubia
// retorna o resto (uma outra lista, mesmo que vazia)
Node *tail(Node *list) {
  //se tiver um valor na lista a cabeça seráconsiderada calda tambem.
    // caso o próximo elemento seja nulo
    // retorna a própria lista
    if ((*list).next == NULL)
    {
        return list;
    }

    return (*list).next;
}
// Grupo 04 - André e Danubia
void show(Node *list){
    Node * aux = list;
    if(aux == NULL)printf("Lista sem nós");

    printf("( ");
    for(;aux != NULL; aux = aux->next){
        if(aux->type == 0){
            printf(" %d", aux->atomList.atom);
            if(aux->next->type == 0) printf(", ");
        }else
        {
            show(aux->atomList.list);
        }
    }
    printf(" )");
}
// grupo 05 Caroline e Gabriel
bool search(Node list, int atom){
// verifica se a lista nao esta nula
 if (list == NULL) {
     return false;
 }
//verifica se o elemento que procuramos esta na lista
    else if search (head(tail(list),atom) return true;
//chama os oproximos elementos
    else return search(tail(list),atom);
}
