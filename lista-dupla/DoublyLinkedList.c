#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


void init(DoublyLinkedList *list){
    
    Node * trashNode = (Node *)(malloc(sizeof(Node)));

    if(trashNode == NULL)printf("Erro ao alocar o trashNode");

    trashNode->data = NULL;
    trashNode->next = trashNode;
    trashNode->previous = trashNode;

    list->first = trashNode;
    list->size = 0;
}

int enqueue(DoublyLinkedList *list, void *data){


}
void* dequeue(DoublyLinkedList *list){
    // se tiver vazia, só sai
    if (isEmpty(list)) return NULL;

    // ele cria um ponteiro, `trash`, que guarda o primeiro nó (começo da lista)
    Node *trash = list->first;

    // faz o primeiro receber o próximo nó (segundo elemento)
    Node *first = list->first->next;

    // !!! `first` agora é o segundo elemento !!!

    // o anteior do segundo elemento recebe o começo da lista
    first->next->previous = trash;

    // o próximo elemento depois do começo recebe o segundo
    trash->next = first->next;

    // guarda o dado em uma váriavel `data`
    void *data = first->data;

    // liberar a memória do `first`
    free(first);

    // diminui o tamanho da lista
    list->size--;

    // retorna o dado
    return data;
}
void* first(DoublyLinkedList *list){

}
void* last(DoublyLinkedList *list){

}
int push(DoublyLinkedList *list, void *data){

}
void* pop(DoublyLinkedList *list){

}
void* top(DoublyLinkedList *list){

}
bool isEmpty(DoublyLinkedList *list){
    return (list->size == 0);
}
int indexOf(DoublyLinkedList *list,void *data, compare equal){

}
Node* getNodeByPos(DoublyLinkedList *list,int pos){

}
void* getPos(DoublyLinkedList *list,int pos){

}
int add(DoublyLinkedList *list, int pos, void *data){

}

int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){

    if(isEmpty(listSource) || pos > listDest->size) return -1;
    if(isEmpty(listDest) || pos > listSource->size) return -2;

    if(pos < 1) return -3;

    Node * aux = getNodeByPos(listDest, (pos-1));
    Node * listSourceLast  = listSource->first->previous; 

    listSource->first->previous->next = aux->next;
    listSource->first->next->previous = aux;
    aux->next->previous = listSourceLast;
    aux->next = listSource->first->next; 

    listDest->size += listSource->size;
    return listDest->size;
}
void* removePos(DoublyLinkedList *list, int pos){

}
bool removeData(DoublyLinkedList *list, void *data, compare equal){

}
void show(DoublyLinkedList *list, printNode print){

    Node * aux = list->first->next;

    printf("\nImpressão dos dados de cada nó");
    printf("\n------------------------------\n");
    
    while (aux != list->first)
    {
        print(aux->data);
        aux = aux->next;
    }
    
    printf("\n------------------------------\n");
}
void showMem(DoublyLinkedList *list){

}