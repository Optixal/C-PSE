#include <stdio.h>

void error() {
}

int main() {
    const float PI = 3.141592653589793;
    int radius;

    printf("Radius |  Area  | Circum\n");
    printf("-------------------------\n");
    for (radius = 5; radius <= 50; radius += 5) {
        float area = PI * radius * radius;
        float circumference = 2 * PI * radius;
        printf("%-7d|%-8.2f|%-8.2f\n", radius, area, circumference);
    }
    printf("-------------------------\n");
    
    return 0;
}
