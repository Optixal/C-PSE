#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* Program template for ST2512 Practical 2 Task 5 */
const float PI = 3.141592653589793 ;

void error() {
	printf("Please enter 1, 2, 3 or 4 only\n");
        	printf("Press <Enter> to continue ");
	char c = getchar();
	c = getchar();
}

int main (int argc, char * argv[] ) {
/* display a menu for the user selection
   loop forever, until the user select option 4.
*/
int option = 0;
char input[80];
float area , perimeter ;
 do {
	option = 0;
	printf("----------------------------\n");
	printf("1.	Circle\n");
	printf("2.	Rectangle\n");
	printf("3.	Right-Angle Triangle\n");
	printf("4.	Exit\n");
	printf(">>");
	scanf("%s", &input[0]);
	if (strlen(input) != 1) {
		error();
		continue; /* jump back to the top of the loop */
	}
	option=atoi(input);
        /* you need to add in more validation and the actual computation */

 } while (option != 4);

}
