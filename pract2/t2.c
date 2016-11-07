#include <stdio.h>

void error() {
}

int main() {
    const float PI = 3.141592653589793;
    float radius;
    printf("Please enter a radius: ");
    scanf("%f", &radius);

    if (radius <= 0) {
        printf("Please enter a radius greater than 0!\n");
        return 1;    
    }

    float area = PI * radius * radius;
    float circumference = 2 * PI * radius;

    printf("The circle's details are as follows\n");
    printf("Radius = %.1f\n", radius);
    printf("Area = %.2f\n", area);
    printf("Circumference = %.2f\n", circumference);
    
    return 0;
}
