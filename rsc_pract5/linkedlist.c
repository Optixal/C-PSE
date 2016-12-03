/*
   PSE Week 5 Dynamic Memory Allocation & Linked List
Example: Linked List
Author : Karl Kwan
Last update : Nov 2016

*/

#include <stdio.h>
#include <string.h> // strlen
#include <stdlib.h> // malloc,free

struct NodeStruct{

    // Data
    int num;

    // Pointer to next node
    struct NodeStruct * nextNode;
};
typedef struct NodeStruct Node;

void printNumbers(int *, int);
// Node Management
Node * createNode( int num);
void printNode(Node *n);

// Linked List Management
Node * addNodeToTail ( Node* linkedlist, Node * newNode);
Node * addNodeToHead ( Node* linkedlist, Node * newNode);
void printLinkedList (Node* linkedlist);
void releaseLinkedList(Node* linkedlist);
void main(){
    Node* list = NULL; // Initializing an empty list 
    int i;
    int numbers[]={888,111,222,333,44,5,6,777,9,0};
    // Add the numbers in the list 
    for(i=0;i<sizeof(numbers)/sizeof(int);i++) {
        if(i%2){
            list = addNodeToTail(list, createNode(numbers[i]));
        } else {
            list = addNodeToHead(list, createNode(numbers[i]));
        }
    }
    // print the original numbers array 
    printNumbers(numbers,sizeof(numbers)/sizeof(int));
    // print the Linked List
    printLinkedList (list);
    // release the memory.
    printf("Release all nodes back to memory pool\n");
    releaseLinkedList(list);
    printf("Bye Bye\n");
}
void printNumbers(int * num,int size) {
    int i;
    for (i=0;i<size;i++) {
        printf("%4d ",*(num+i));
    }
    printf("\n");
}
Node * createNode( int num){

    // Dynamically allocate memory for one node
    Node* newNode = (Node *) malloc(sizeof(Node));

    // Fill the node
    newNode->num = num;
    newNode->nextNode = NULL; // No next Node yet to point too

}

void printNode(Node *n){
    printf("%4d ", n->num);
}

Node *  addNodeToHead ( Node* headptr, Node * newNode){
    // insert the new node to the beginning of the list
    newNode->nextNode = headptr;
    return newNode;
}
Node * addNodeToTail ( Node * headptr, Node * newNode){

    // recursive function to append the new node to the end of the list 
    if (headptr == NULL) {
        return newNode;
    }
    headptr->nextNode = addNodeToTail(headptr->nextNode,newNode);	
    return headptr;
}

void printLinkedList (Node* linkedlist){
    /* print the current node data and proceed to the next node */
    /* or stop if there is no more next node */
    Node* n = linkedlist;  
    while( n!= 0){// Visit all the nodes in the list
        printNode(n);
        n = n-> nextNode; // Jump to next node
    } 
    printf("\n");
}

void releaseLinkedList (Node* linkedlist){
    /* using recursive way to release all the allocated node*/
    /* algorithm
       1. if current link is null, stop
       2. Call ReleaseLinkedList(next node)
       3. free the memory of the current node.
       */

    Node* n = linkedlist;  
    if (n == NULL) return;  /* termination state : nothing to free*/
    releaseLinkedList(n->nextNode); /* try to free next first */
#ifdef DEBUG
    printf("going to release %4d\n",n->num);
#endif
    free(n); // release this node;
}
