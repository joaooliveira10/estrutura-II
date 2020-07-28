#include <stdio.h>
#include <stdlib.h>

#include "generallist.h"

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
