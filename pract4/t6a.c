#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1; 
    int n = 1;
    int i, j;
    for (i = 0; i < atoi(argv[1]); i++) {
        for (j = 0; j < atoi(argv[1]); j++, n++) {
            printf("%-4d", n);
        }
        printf("\n");
    }
}
