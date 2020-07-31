#include <stdio.h>
#include <stdlib.h>

#include "generallist.h"

int main() {
    
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;

    Node n6;
    Node n7;
    Node n8;
    Node n9;
    Node n10;

    //head
    n1.type = 0;
    n1.atomList.atom = 1;
    n1.next = &n2;

    // tail
    n2.type = 0;
    n2.atomList.atom = 2;
    n2.next = &n3;

    n3.type = 0;
    n3.atomList.atom = 3;
    n3.next = &n4;

    n4.type = 0;
    n4.atomList.atom = 4;
    n4.next = &n5;

    n5.type = 0;
    n5.atomList.atom = 5;
    n5.next = &n6;

    n6.type = 1;
    n6.atomList.list = &n7;
    n6.next = NULL;

    n7.type = 0;
    n7.atomList.atom = 6;
    n7.next = &n8;

    n8.type = 0;
    n8.atomList.atom = 7;
    n8.next = &n9;

    n9.type = 0;
    n9.atomList.atom = 8;
    n9.next = &n10;

    n10.type = 0;
    n10.atomList.atom = 9;
    n10.next = NULL;

    printf("Lista:\n");
    show(&n1);

    printf("\nCabeça da lista:\n");
    show(head(&n1));

    printf("\nCauda da lista:\n");
    show(tail(&n1));

    printf("\nCabeça da cauda da lista:\n");
    show(head(tail(&n1)));

    printf("\n");
    
    return 0;
}