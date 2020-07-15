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

}
void* getPos(DoublyLinkedList *list,int pos){

}
int add(DoublyLinkedList *list, int pos, void *data){

}
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource){

}
void* removePos(DoublyLinkedList *list, int pos){

}
bool removeData(DoublyLinkedList *list, void *data, compare equal){

}
void show(DoublyLinkedList *list, printNode print){

}
void showMem(DoublyLinkedList *list){

}