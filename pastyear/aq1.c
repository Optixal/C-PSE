#include <stdio.h>

int main() {
    int i, x[] = {-5, 10, -10, -2, 23, -20};
    char y[20] = "goodbye";
    char * p = y;
    for (i = 0; i < 6; i++) {
        *(p + i) = *(p + i) + x[i];
    }
    y[6] = '\0';
    printf("%s\n", p);
}
