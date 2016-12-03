/* source file p5t3v1.c */
/* identical to file p4t2v2.c 
   This version is using array (fixed size) to maintain a list of 
   student records.
   Please modify it to use dynamic memory (linked list) as the primary
   storage.
*/
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
#define NAME_SIZE 21 
#define FAILURE_MARK 40
struct entry {     
 	char name [NAME_SIZE]; 
    int mark; 
}; 
typedef struct entry Student ; 
Student slist[MAX_ENTRY]; /* from 0 to (MAX_ENTRY – 1) */ 
 
int entry_total=0;  /* keep track of the no of entries */ 
int highest_mark = 0;
int lowest_mark=100;

void keyboardText(char * buf, int size){
    int ch;
	fgets(buf,size,stdin);
	if (buf[strlen(buf)-1]!='\n') {
       // special case, user type in input longer than buffer length 
       // consume all the extra input
      	while ( ch=getchar() != '\n') {} 
    } else {
	   buf[strlen(buf)-1]='\0'; // 
	}
}
void menu() { 
   /* print the menu */ 
   printf(" ========== MENU =============\n"); 
   /* fill in your codes please */

   printf("1. Add new entry\n");
   printf("2. List all entries\n"); 
   printf("3. Remove all entries\n"); 
   printf("4. Print the average of the marks\n");
   printf("5. Print entries which blow 40 marks\n"); 
   printf("6. Print the entry/entries with highest marks\n"); 
   printf("7. Print the entry/entries with lowest marks\n"); 
   printf("8. exit the program\n"); 
   printf("Your Command (1 to 8) => "); 

} 
void listall(Student curlist[], int curTotal){
int i;
 if (curTotal >0) {
 	printf("%-20s %-4s\n","Student","Mark");
	for(i=0;i<curTotal;i++){
	printf("%-20s %4d\n",curlist[i].name,curlist[i].mark);
	}
 } else {
 	printf("No entry found\n");
 }
}

void listExact(Student curlist[], int curTotal, int exact_mark){
//  assumption : curTotal is > 0
int i;
 	printf("%-20s %-4s\n","Student","Mark");
	for(i=0;i<curTotal;i++){
        if (curlist[i].mark == exact_mark) {
			printf("%-20s %4d\n",curlist[i].name,curlist[i].mark);
		}
	}
}
void listfailure(Student curlist[], int curTotal){
int i;
int failure = 0;
  	if (curTotal <=0) {
 		printf("No entry found\n");
		return;
	} 
  	for(i=0;i<curTotal;i++){
		if (curlist[i].mark < FAILURE_MARK) {
      		failure++;
    	}
  	}
 if (failure >0) {
 	printf("%-20s %-4s\n","Student","Mark");
	for(i=0;i<curTotal;i++){
        if (curlist[i].mark < FAILURE_MARK) {
			printf("%-20s %4d\n",curlist[i].name,curlist[i].mark);
		}
	}
 } else {
 	printf("There is no failure case.\n");
 }
}
void prtaverage(Student curlist[], int curTotal){
int i;
float total=0.0;
 if (curTotal >0) {
	for(i=0;i<curTotal;i++){
		total=total + curlist[i].mark;
	}
 	printf("Average Mark is %.2f for the %4d entries\n",total/curTotal,curTotal);
 } else {
 	printf("No entry found\n");
 }
}

void add_new(Student curlist[], int curTotal){
	/* get the user input of the student name and mark, 
		to append the entry data, store the input in curlist[curTotal] 
	*/
    char buf[NAME_SIZE];	
    printf("Name => "); 
	keyboardText(buf,NAME_SIZE);
	strcpy(curlist[curTotal].name,buf);
    printf("Mark => "); 
	keyboardText(buf,4);
	curlist[curTotal].mark=atoi(buf);
	/* fill in your codes please */
}
int get_cmd() { 
	int ans = EXIT;  // default is EXIT
	char buf [3]; // 1 digit, 1 linefeed, 1 null byte
    /* get the user choice  */ 
    /* return a valid choice (1 to 8)  to the caller */         
	/* fill in your codes please */
	keyboardText(buf,3);
	ans=atoi(buf);
	return ans;  
} 
main() {      
	int opt;      
	do {          
		menu();  
		opt=get_cmd(); 
		switch(opt) {      
		case ADDNEW: 
 	 	 	if (entry_total < MAX_ENTRY) { 
 	 	 	 	add_new(slist,entry_total);  	 	 	 	
		        // record the highest and lowest marks at this point.
			    if (slist[entry_total].mark > highest_mark) {
					highest_mark = slist[entry_total].mark;
				}
			    if (slist[entry_total].mark < lowest_mark) {
					lowest_mark = slist[entry_total].mark;
				}
				entry_total++; 
 	 	 	}  
          	break;          
		case LISTALL:          
			listall(slist,entry_total);
			break;
		case CLEAR:          
			// reset important control values
			highest_mark = 0;
			lowest_mark = 100;
			entry_total=0;
			break;
		case PRINTAVG:          
			prtaverage(slist,entry_total);
			break;
		case LISTFAIL:          
		    listfailure(slist,entry_total);
			break;
		case PRINTMAX:          
			if (entry_total) {
		      printf("List of higest mark students\n"); 		
			  listExact(slist,entry_total,highest_mark);
			} else {
			  printf("There is no entry found\n");
			}
			break;
		case PRINTMIN:          
			if (entry_total) {
		      printf("List of lowest mark students\n"); 		
			  listExact(slist,entry_total,lowest_mark);
			} else {
			  printf("There is no entry found\n");
			}
			break;
		case EXIT:               
			printf("Thank You, have a nice day\n"); 
		break; 
       } 
     } while (opt != EXIT ) ; 
} /* end of main */ 
