#include <stdio.h>
#include <stdlib.h>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    int n = atoi(argv[1]);
    int array[n][n];
    int r = 0, c = 0, counter = 0, direction = RIGHT, rbound = n - 1, cbound = n - 1;
    while (counter < n * n) {
        array[r][c] = counter + 1;
        counter++;
        switch (direction) {
            case RIGHT:
                c++;
                break;
            case DOWN:
                r++;
                break; 
            case LEFT:
                c--;
                break;
            case UP:
                r--;
                break;
        }
        if (r == (n - 1) - rbound && c == cbound) {
            direction = DOWN;
        } else if (r == rbound && c == cbound) {
            direction = LEFT;
        } else if (r == rbound && c == (n - 1) - cbound) {
            direction = UP;
        } else if (r == n - rbound && c == (n - 1) - cbound) {
            direction = RIGHT;
            rbound--;
            cbound--;
        }
    }
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }
}
