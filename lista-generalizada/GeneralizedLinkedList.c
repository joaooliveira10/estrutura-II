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
