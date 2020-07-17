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
    //feito para testar a função addAll
    //if(isEmpty(list) || pos > list->size)return NULL;

    //Node * aux = list->first->next;

    //int count;
    //for(count = 0; (aux != list->first->previous && pos != count); count++, aux = aux->next);

    //return aux;
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
    Node * listSourceFirst = listSource->first;
    Node * listSourceLast  = listSource->first->previous; 

    listSource->first->previous->next = aux->next;
    listSource->first->previous = aux;
    aux->next->previous = listSourceLast;
    aux->next = listSourceFirst;

    listDest->size += listSource->size;
    return listDest->size;
}
void* removePos(DoublyLinkedList *list, int pos){

}
bool removeData(DoublyLinkedList *list, void *data, compare equal){

}
void show(DoublyLinkedList *list, printNode print){

}
void showMem(DoublyLinkedList *list){

}