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
    //reserva um espaço novo na memória 
  Node *newNode = (Node*)malloc(sizeof(Node));
    //caso nao tenha espaço na memoria ou seja novo nó for nulo entao 
    //retornamos -1 para que o usario entenda que tem algo errado
    if (newNode==NULL) return -1;
    newNode->data = data;
    //deixa o novo nó apontando para nexte que recebe list na pocisao inicial
    newNode->next = list->first;
    //novo nó apontando para o anterior recebe a lista apontando para o primeiro que aponta para o ultimo
    newNode->previous = list->first->previous;
    //list que aponta para o primero, aponta para o ultimo que aponta para o proximo que recebe o novo
    list->first->previous->next = newNode;
    //list aponta para o primeira, aponta para ultimo que recebe o proximo
    list->first->previous = newNode;
    // almenta o tamanho da lista
    list->size++;
    //retorna 1 e encerra o programa
    return 1;

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
    //A função fist analiza o primeiro dado 
void* first(DoublyLinkedList *list){
    return list->first->next->data;
    //Faz o primeiro receber o proximo e aponta para o dado
}
void* last(DoublyLinkedList *list){

}
int push(DoublyLinkedList *list, void *data){
    Node *newNode = (Node*) malloc(sizeof(Node)); 
    //cria uma variavel novoNode para inserir um novo nó apos inserção de valor, e verifica se a espaço na memoria para alocar esta variavel de 'node'.

    if (newNode==NULL)
    return -1;     
     //caso não tenha espaço retorna -1.

    newNode->data = data; 
    // aqui o novo nó passa a apontar para variavel data que recebe dados.

    newNode->next = list->first->next; 
    //neste parametro o novo nó aponta para next que recebe a lista com a primeira posição dela que é first que aponta de volta next.

    newNode->previous = list->first;
    // a variavel newnode volta em ação apontando para previous que é a estrutura anterior, que estará recebendo a lista com a primeira posição que é first.

    list->first->next->previous = newNode;
    // esta condição entrará se atribuição de função do newNode for afirmada, o parametro apresentado refere-se a como a lista se encontra após ter sido adicionado algo

    list->first->next = newNode;
    // após a apresentação acima a lista volta para a primeira posição.

    list->size++; 
    //aqui a lista é "atualizada" com os novos valores.

    return 1;
}
void* pop(DoublyLinkedList *list){
    return dequeue(list);
}
void* top(DoublyLinkedList *list){  
    return first(list);             //O ponteiro consuta o topo da pilha retornando o primeiro da fila
}
bool isEmpty(DoublyLinkedList *list){
    return (list->size == 0);
}
int indexOf(DoublyLinkedList *list,void *data, compare equal){
if (isEmpty(list)) return -1; //verifica se a lista está vazia
    int count=0;
    Node *aux = list->first->next; // nó auxiliar para guardar o endereço do primeiro nó com dado

    while(aux!=list->first && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }

    return (aux==list->first)?-1:count;//se achou o dado, retorna a posição, se não retorna -1
}
Node* getNodeByPos(DoublyLinkedList *list,int pos){

}
void* getPos(DoublyLinkedList *list,int pos){

}
int add(DoublyLinkedList *list, int pos, void *data){
    Node *aux = getNodeByPos(list, pos); 
    if (aux==NULL) return -2; // Compara para ver se a posição informada é valida, se não é retorna -2
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    
    newNode->data = data;
    newNode->next = aux;
    newNode->previous = aux->previous;
    aux->previous->next = newNode;
    aux->previous = newNode;
    
    list->size++;
    
    return 1;
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
//Função responsavel por remover um dado
bool removeData(DoublyLinkedList *list, void *data, compare equal){
    if(isEmpty(list)) return 0;
    Node *aux = list->first->next;
    while(aux != list->first ){
        if(equal(aux->data,data)){
            aux->previous->next = aux->next;
            aux->next->previous = aux->previous;
            free(aux->data);
            free(aux);
            return 1;
            list->size--;
        }
      aux = aux->next;
    }
    return 0;
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
