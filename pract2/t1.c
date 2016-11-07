#include <stdio.h>

int main() {
    const float PI = 3.141592653589793;
    float radius = 3.5;
    float area = PI * radius * radius;
    float circumference = 2 * PI * radius;

    printf("Radius = %.1f\n", radius);
    printf("Area = %.2f\n", area);
    printf("Circumference = %.2f\n", circumference);
    
    return 0;
}
