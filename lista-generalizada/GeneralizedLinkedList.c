
// retorna o primeiro elemento da lista (átomo ou lista)
// rubia e cristian 
Node *head(Node *list) {
  //
    if (list == NULL) 
    {
        return NULL;
    }

    Node *node = (Node *) malloc(sizeof(Node));
    node->type = list->type;
    node->next = NULL;

    switch (list->type) {
    case 0:
        node->atomList.atom = list->atomList.atom;
        break;
    case 1:
        node->atomList.list = list->atomList.list;
        break;
    }
    
    return node;
}

// retorna o resto (uma outra lista, mesmo que vazia)
Node *tail(Node *list) {
    // caso o próximo elemento seja nulo
    // retorna a própria lista
    if ((*list).next == NULL)
    {
        return list;
    }

    return (*list).next;
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
