#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[] ) {
    if (argc != 3) {
        printf("Usage: %s [num1] [num2]\n", argv[0]);
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int total = 0;

    do {
        if (num1 % 2 != 0) {
            total += num1;
        }
        num1++;
    } while (num1 <= num2);
    printf("The sum of the odd numbers is %d\n", total);

    return 0;
}
