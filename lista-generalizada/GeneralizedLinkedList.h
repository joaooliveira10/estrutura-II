#ifndef DataStructure_GeneralizedLinkedList_h
#define DataStructure_GeneralizedLinkedList_h
enum boolean {
    true = 1, false = 0
};
typedef enum boolean bool;
typedef struct Node {
    int type; //0 atomo e 1 lista
    union {
        int atom;
        struct Node *list;
    }atomList;
    struct Node *next;
}Node;
int addAtom(Node **list, int atom);
int addList(Node **list, Node **subList);
Node* head(Node *list);
Node* tail(Node *list);
void show(Node *list);
bool search(Node *list, int atom);
int depth(Node *list);
#endif