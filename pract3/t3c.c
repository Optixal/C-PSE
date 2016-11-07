#include <stdio.h>

/* The program accepts one integer then computes and
 * displays the corresponding inverse rule */

float compute();

int main() {
    int num;

    printf("Please enter a number\n");
    scanf("%d", &num);
    printf("The inverse of %d is %.2f\n", num, compute(&num));
}

float compute(int *n) {
    return 1.0 / *n;
}
