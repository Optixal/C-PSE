#include <stdio.h>
#include <math.h>

double mysqrt(double);

void main() {
    double n = 50;
    printf("The square root of %f is %.32lf (math lib)\n", n, sqrt(n));
    printf("The square root of %f is %.32lf (own lib)\n", n, mysqrt(n));
}
