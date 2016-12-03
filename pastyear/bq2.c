#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NodeStruct {
    int num;
    struct NodeStruct * nextNode;
};
typedef struct NodeStruct Node;

Node * create_node(int num);
Node * add_node(Node * linkedlist, Node * newNode);
void release_list(Node * linkedlist);
void print_list(Node * linkedlist);

void main() {
    Node * list = NULL;
    srand((unsigned) time(NULL));
    int i, list_size = rand() % 5 + 5;
    for (i = 0; i < list_size; i++) {
        list = add_node(list, create_node(rand() % 100));
    }
    print_list(list);
    release_list(list);
    printf("\n");
}

Node * add_node(Node * list, Node * newNode) {
    newNode->nextNode = list;
    return newNode;
}

void print_list(Node * linkedlist) {
    Node * n = linkedlist;
    while (n != 0) {
        printf("%04d \n", n->num);
        n = n->nextNode;
    }
}

Node * create_node(int num) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->num = num;
    return newNode;
}

void release_list(Node * linkedlist) {
    if (linkedlist == NULL) return;
    release_list(linkedlist->nextNode);
    free(linkedlist);
}
