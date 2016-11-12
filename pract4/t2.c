/* source file p4t2v1.c */
#include <stdio.h> 
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
struct entry {     
    char name [NAME_SIZE]; 
    int mark; 
}; 
typedef struct entry Student ; 
Student slist[MAX_ENTRY]; /* from 0 to (MAX_ENTRY – 1) */ 

int entry_total=0;  /* keep track of the no of entries */ 

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

void add_new(Student curlist[], int curTotal) {
    /* get the user input of the student name and mark, 
       to append the entry data, store the input in curlist[curTotal] 
       */
    printf("Name => ");
    scanf("%s", curlist[curTotal].name);

    printf("Mark => ");
    scanf("%d", &curlist[curTotal].mark);
}

void list_all(Student curlist[], int curTotal) {
    printf("%-20s%20s\n", "Student", "Mark");
    int i;
    for (i = 0; i < curTotal; i++) {
        printf("%-20s%20d\n", curlist[i].name, curlist[i].mark);
    }
}

void print_avg(Student curlist[], int curTotal) {
    int sum = 0;
    int i;
    for (i = 0; i < curTotal; i++) {
        sum += curlist[i].mark;
    }
    printf("Average Mark is %.2lf for the %d entries\n", (double)sum/curTotal, curTotal);
}

void list_fail(Student curlist[], int curTotal) {
    printf("%-20s%20s\n", "Student", "Mark");
    int i;
    for (i = 0; i < curTotal; i++) {
        if (curlist[i].mark < 40) {
            printf("%-20s%20d\n", curlist[i].name, curlist[i].mark);
        }
    }
}

void print_min(Student curlist[], int curTotal) {
    printf("List of lowest mark students\n");
    int lowest = curlist[0].mark;
    int i;
    for (i = 1; i < curTotal; i++) {
        if (curlist[i].mark < lowest) {
            lowest = curlist[i].mark;
        }
    }
    for (i = 0; i < curTotal; i++) {
        if (curlist[i].mark == lowest) {
            printf("%-20s%20d\n", curlist[i].name, curlist[i].mark);
        }
    }
}

void print_max(Student curlist[], int curTotal) {
    printf("List of lowest mark students\n");
    int highest = curlist[0].mark;
    int i;
    for (i = 1; i < curTotal; i++) {
        if (curlist[i].mark > highest) {
            highest = curlist[i].mark;
        }
    }
    for (i = 0; i < curTotal; i++) {
        if (curlist[i].mark == highest) {
            printf("%-20s%20d\n", curlist[i].name, curlist[i].mark);
        }
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

void main() {
    int opt;      
    do {          
        menu();  
        opt=get_cmd(); 
        switch(opt) {      
            case ADDNEW: 
                if (entry_total < MAX_ENTRY) { 
                    add_new(slist, entry_total);  	 	 	 	
                    entry_total++; 
                }  
                break;          
            case LISTALL:          
                list_all(slist, entry_total);
                break;
            case CLEAR:          
                entry_total = 0;
                break;
            case PRINTAVG:          
                print_avg(slist, entry_total);
                break;
            case LISTFAIL:
                list_fail(slist, entry_total);
                break;
            case PRINTMAX:          
                print_max(slist, entry_total);
                break;
            case PRINTMIN:          
                print_min(slist, entry_total);
                break;
            case EXIT:               
                printf("Thank You, have a nice day\n");
                break; 
        } 
    } while (opt != EXIT ) ; 
} /* end of main */

