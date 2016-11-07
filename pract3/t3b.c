#include <stdio.h>

/* The program accepts one integer then computes and
 * displays the corresponding inverse rule */

float compute();

int main() {
    int num;
    float inverse;

    printf("Please enter a number\n");
    scanf("%d", &num);
    inverse = compute(&num);
    printf("The inverse of %d is %.2f\n", num, inverse);
}

float compute(int *n) {
    return 1.0 / *n;
}
