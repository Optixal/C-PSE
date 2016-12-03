/* source file p4t2v1.c */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#define ADDNEW   1 
#define LISTALL  2 
#define CLEAR    3 
#define PRINTAVG 4 
#define LISTFAIL 5 
#define PRINTMAX 6 
#define PRINTMIN 7 
#define EXIT     8 
#define MAX_ENTRY 25 
#define NAME_SIZE 20 
struct Node {     
    char name [NAME_SIZE]; 
    int mark; 
    struct Node * next;
};
typedef struct Node Student;

Student * studentHead = NULL;

void menu() { 
    /* print the menu */ 
    printf(" ========== MENU =============\n"); 
    printf("1. Add new entry\n");
    printf("2. List all entries\n");
    printf("3. Remove all entries\n");
    printf("4. Print the average of the marks\n");
    printf("5. Print entries which is below 40 marks\n");
    printf("6. Print the entry/entries with highest marks\n");
    printf("7. Print the entry/entries with lowest marks\n");
    printf("8. Exit the program\n");
} 

Student * add_to_tail(Student * head, Student * newNode) {
    if (head == NULL) return newNode;
    head->next = add_to_tail(head->next, newNode);
    return head;
}

Student * add_new(Student * head) {
    Student * newNode = (Student *)malloc(sizeof(Student));

    printf("Name => ");
    scanf("%s", newNode->name);

    printf("Mark => ");
    scanf("%d", &newNode->mark);

    head = add_to_tail(head, newNode);
    return head;
}

void list_all(Student * head) {
    printf("%-20s%20s\n", "Student", "Mark");
    while (head != NULL) {
        printf("%-20s%20d\n", head->name, head->mark);
        head = head->next;
    }
}

void list_all_r(Student * head) {
    Student * n = head;
    if (head == NULL) return;
    list_all_r(head->next);
    printf("%-20s%20d\n", head->name, head->mark);
}

void print_avg(Student * head) {
    int sum = 0;
    int count = 0;
    while (head != NULL) {
        sum += head->mark;
        count++;
        head = head->next;
    }
    printf("Average Mark is %.2lf for the %d entries\n", (double)sum/count, count);
}

void list_fail(Student * head) {
    printf("%-20s%20s\n", "Student", "Mark");
    while (head != NULL) {
        if (head->mark < 40) {
            printf("%-20s%20d\n", head->name, head->mark);
        }
        head = head->next;
    }
}

void print_min(Student * head_org) {
    printf("List of lowest mark students\n");
    Student * head = head_org;
    int lowest = head->mark;
    while (head != NULL) {
        if (head->mark < lowest) {
            lowest = head->mark;
        }
        head = head->next;
    }
    while (head_org != NULL) {
        if (head->mark == lowest) {
            printf("%-20s%20d\n", head_org->name, head_org->mark);
        }
        head_org = head_org->next;
    }
}

void print_max(Student * head_org) {
    Student * head = head_org;
    printf("List of lowest mark students\n");
    int highest = head->mark;
    while (head != NULL) {
        if (head->mark > highest) {
            highest = head->mark;
        }
        head = head->next;
    }
    while (head_org != NULL) {
        if (head_org->mark == highest) {
            printf("%-20s%20d\n", head_org->name, head_org->mark);
        }
        head_org = head_org->next;
    }
}

int get_cmd() { 
    int ans = EXIT;  // default is EXIT
    /* get the user choice  */ 
    /* return a valid choice (1 to 8)  to the caller */         
    printf("Your Command (1 to 8) => ");
    scanf("%d", &ans);
    return ans;  
} 

void free_list(Student * head) {
    Student * n = head;
    if (n == NULL) return;
    free_list(n->next);
    free(n);
}

void main() {
    int opt;      
    do {          
        menu();  
        opt=get_cmd(); 
        switch(opt) {      
            case ADDNEW: 
                studentHead = add_new(studentHead);
                break;          
            case LISTALL:          
                // list_all(studentHead);
                printf("%-20s%20s\n", "Student", "Mark");
                list_all_r(studentHead);
                break;
            case CLEAR:          
                free_list(studentHead);
                studentHead = NULL;
                break;
            case PRINTAVG:          
                print_avg(studentHead);
                break;
            case LISTFAIL:
                list_fail(studentHead);
                break;
            case PRINTMAX:          
                print_max(studentHead);
                break;
            case PRINTMIN:          
                print_min(studentHead);
                break;
            case EXIT:               
                printf("Thank You, have a nice day\n");
                break; 
        } 
    } while (opt != EXIT ) ; 
} /* end of main */

