#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct wordNode {
    char word[100];
    struct wordNode * next;
} W_NODE;

W_NODE * insertNode(W_NODE * headPtr, char * new_word) {
    W_NODE * prevPtr, * curPtr;
    W_NODE * newNode ;
    /* There are four cases to take care
       1. 	The headPtr is initially NULL
       2. 	The new word should be inserted in front of the headPtr
       3. 	This is the normal case, just need to loop till to the end
       of the link and find the righ insertion point.
       4.  Cannot find any insertion point, just append the new Node to the end.
       */
    /* always set up a new Node */
    newNode = (W_NODE *)malloc(sizeof(W_NODE));
    strcpy(newNode->word,new_word);
    newNode->next = NULL;
    /* now start explore the 4 possible cases */

    /* fill in your code here */
    curPtr = headPtr;
    if (curPtr == NULL) {
        headPtr = newNode;
    } else if (strcmp(curPtr->word, new_word) >= 0) {
        newNode->next = headPtr;
        headPtr = newNode;
    } else {
        while (curPtr != NULL) {
            prevPtr = curPtr;
            curPtr = curPtr->next;
            if (curPtr == NULL) {
                prevPtr->next = newNode;
                break;
            } else if (strcmp(curPtr->word, new_word) >= 0) {
                prevPtr->next = newNode;
                newNode->next = curPtr;
                break;
            }
        }
        return headPtr;
    }
}
void print_words(W_NODE * headPtr) {
    W_NODE * workPtr = headPtr;
    while (workPtr != NULL) {
        printf("%s\n",workPtr->word);
        workPtr = workPtr->next;
    }
}
void release_words(W_NODE * curPtr) {
    if (curPtr == NULL) {
        return;
    }
    release_words(curPtr->next);
    free(curPtr);

}
int getNextWord(char * word) {
    printf("next word please [or 'q' to quit]=> ");
    scanf("%s",word);
    if (strcmp(word,"q") == 0) {
        return -1;
    }
    return 0; // 0 is okay
}
int main() {
    W_NODE * rootPtr = NULL;	
    char word[100];
    for(;;) {
        if (getNextWord(word) < 0) {
            break;
        };
        rootPtr=insertNode(rootPtr,word);
    }
    print_words(rootPtr);
    release_words(rootPtr);
}
