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
    float area , perimeter;
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
        option = atoi(input);
        if (option <= 0 || option > 4) {
            error();
            continue;
        }

        float diameter, length, breadth, base, height;
        switch (option) {
            case 1: /* Circle - Request Diameter */ 
                while (1) {   
                    printf("Please enter a diameter: ");
                    scanf("%f", &diameter);
                    if (diameter <= 0) {
                        printf("Please enter a value greater than 0\n");
                        continue;
                    } else {
                        break;
                    }
                }
                area = (1.0 / 4.0) * PI * diameter * diameter;
                perimeter = PI * diameter;
                break;
            case 2: /* Rectangle - Request Length and Breadth*/
                while (1) {   
                    printf("Please enter a length: ");
                    scanf("%f", &length);
                    if (length <= 0) {
                        printf("Please enter a value greater than 0\n");
                        continue;
                    } else {
                        break;
                    }
                }
                while (1) {   
                    printf("Please enter a breadth: ");
                    scanf("%f", &breadth);
                    if (breadth <= 0) {
                        printf("Please enter a value greater than 0\n");
                        continue;
                    } else {
                        break;
                    }
                }
                area = length * breadth;
                perimeter = 2 * length + 2 * breadth;
                break;
            case 3: /* Right-Angle Triangle - Base and Height */
                while (1) {
                    printf("Please enter a base: ");
                    scanf("%f", &base);
                    if (base <= 0) {
                        printf("Please enter a value greater than 0\n");
                        continue;
                    } else {
                        break;
                    }
                }
                while (1) {
                    printf("Please enter a height: ");
                    scanf("%f", &height);
                    if (height <= 0) {
                        printf("Please enter a value greater than 0\n");
                        continue;
                    } else {
                        break;
                    }
                }
                area = base * height * 0.5;
                perimeter = base + height + sqrt(pow(base, 2) + pow(height, 2));
                break;
            case 4:
                return 0;
        }

        printf("The area is %.2f\n", area);
        printf("The perimeter is %.2f\n", perimeter);

    } while (1);

}
