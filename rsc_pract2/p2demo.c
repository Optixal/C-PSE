#include <stdio.h>
#include <stdlib.h>    /* standard lib header */

/* program source : p2demo.c */
/* sample c program to demonstrate the usage of
	: command line argument
	: for, while , switch, if constructs
*/

void usage(char * cmdName) {
	printf("Usage: %s optionNum\n",cmdName);
	printf("    -: optionNum -: 1 to 3\n");
}
int main(int argc, char * argv []) {
	int i; /* for loop counter */
	if (argc != 2) {
		usage(argv[0]);
		return 0;
	}
	int opt = atoi(argv[1]) ;   /* convert string to int */
	if (opt < 1 || opt > 3) {
		usage(argv[0]);
		return 0;
	} 

	switch (opt) {
    
	case 1: /* simple for loop */
		for (i = 0 ; i< 5 ; i++) {
			printf("case 1 : for loop count : %d\n",i);
		}
		while (i > 0) {
			printf("case 1 : while loop count : %d\n",i);
			   i--;	
		}
		break;
	case 2: 
		for (i=3; i>=1 ; i--) {
			if (i == 1) {
				  printf("case 2 : magic ans is %d\n",i*2);
			} else if (i==2) {
				  printf("case 2 : magic ans is %d\n",i*3);
			} else {
				  printf("case 2 : magic ans is %d\n",i*4);
			}
		}
		break;
	default: /* must be 3 */
		printf("case 3: do nothing\n");
		break;
	}  /* end switch() */
	return 0; /* end of program */
}

