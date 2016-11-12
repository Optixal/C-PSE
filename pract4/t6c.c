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
    int r = 0, c = 0, counter = 0, direction = RIGHT, bound = n - 1;
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
        if (r == (n - 1) - bound && c == bound) {
            direction = DOWN;
        } else if (r == bound && c == bound) {
            direction = LEFT;
        } else if (r == bound && c == (n - 1) - bound) {
            direction = UP;
        } else if (r == n - bound && c == (n - 1) - bound) {
            direction = RIGHT;
            bound--;
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
