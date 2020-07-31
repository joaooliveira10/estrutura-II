#include <stdio.h>
#include <stdlib.h>

#include "generallist.h"

/*
//adiciona um átomo na lista
int addAtom(Node **list, int atom)
{

}
*/

/*
//adiciona uma sublista na lista
int addList(Node **list, Node **subList){

}
*/

//retorna o primeiro elemento da lista (átomo ou lista)
Node* head(Node *list) {
    Node *node = (Node*) malloc(sizeof(Node));
  
    switch((*list).type)
    {
    case 0:
        node->type = 0;
        node->atomList.atom = list->atomList.atom;
        break;
    case 1:
        node->type = 1;
        node->atomList.list = list->atomList.list;
        break;
    }

    node->next = NULL;
    return node;
}

// retorna o resto (uma outra lista, mesmo que vazia)
Node* tail(Node *list) {
    Node *node = (Node*) malloc(sizeof(Node));
  
    switch(list->type)
    {
    case 0:
        node->type = 0;
        node->atomList.atom = list->next->atomList.atom;
        break;
    case 1:
        node->type = 1;
        node->atomList.list = list->next->atomList.list;
        break;
    }

    node->next = list->next->next;
    return node;
}

// exibe a lista
void show(Node *list) {
    printf("[");
    Node *node = list;

    while (node != NULL)
    {
        switch (node->type)
        {
        case 0:
            printf("%d", node->atomList.atom);
            break;
        case 1:
            show(node->atomList.list);
            break;
        }

        node = node->next;

        if (node != NULL) {
            printf(", ");
        }
    }

    printf("]");
}

/*
//localiza um átomo na lista
enum boolean search(Node *list, int atom){

}
*/

/*
//retorna a profundidade da lista
int depth(Node *list){

}
*/