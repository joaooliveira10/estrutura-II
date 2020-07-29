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

    //Grupo 2 - Bruno e Henrique
    //Adiciona sublistas na lista
int addList(Node **list, Node **subList){

Node *new_node = (Node*)malloc(sizeof(Node));
  
    new_node->type = 1;
    new_node->next = NULL;
    new_node->atomList.list = (subList);
  
    if((list) == NULL){
        (list) = new_node;
        return 1;
    }

    Node *aux = *list;
    for(aux->next!= NULL;aux = aux->next;);
    
    aux->next = new_node;
    
    return 1;

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
    
    Node * aux = list; // criado nó auxiliar que recebe o endereço da lista

    printf("(");
    for(;aux != NULL; aux = aux->next){      // ira percorrer a lista até aux->next ser NULL, ou seja até econtrar o fim da lista
        if(aux->type == 0){                 // se o type for == 0 apenas ira exibir o atom
            printf("%d", aux->atomList.atom);
            if(aux->next != NULL) printf(", "); 
        
        }else                                  // se não for do type == 0, logo sera uma sublista
        {   
            show(aux->atomList.list);          // chamara assim a função novamente, entretanto enviando o endereço da sublista
        }
    }
   
    
    printf("),");

}

// grupo 05 Caroline e Gabriel
bool search(Node *list, int atom){
// verifica se a lista nao esta nula
 if (list == NULL) {
     return false;
 }
//verifica se o elemento que procuramos esta na lista
    else if ( search (head(tail(list)), atom) ) return true;
//chama os oproximos elementos
    else return search(tail(list),atom);
};
//Grupo 06 João e Wigor
int depth(Node *list) {           //depth retorna a profundidade da lista
    int profundidadeAtual = 0;    //a variavel profundidadeAtual recebe o valor de 0
    if (list==NULL)               //se a lista for nula retornara 0
        return 0;

    Node *aux = NULL;                                //auxiliar aponta para nulo
    for (aux = list; aux!=NULL; aux=aux->next) {    //(para aux recebe lista, aux diferente de nulo, aux recebe o proximo.
        if (aux->type==1) {                         //se o auxiliar recebe type igual a 1
            int prof = depth(aux->atomList.list);  // a variavel prof recebe o valor da prondidade da atomLista
            if (prof>profundidadeAtual)           // (se a profundidade for maior que o valor da profundidade atual
                profundidadeAtual=prof;          //  a profundidade atual recebe o valor de profunidade
        }
    }
    return profundidadeAtual+1;                 //retornando profundidade atual +1
}
