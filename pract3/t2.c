#include <stdio.h>

int add(int, int);
int multiple(int, int);

int main(int argc, char *argv[]) {
    int x, y, res;
    char op;
    while (1) {
        printf("First number => ");
        scanf("%d", &x);
        printf("Second number => ");
        scanf("%d", &y);
        printf("Please Enter + for addition, or * for multiplication => ");
        scanf(" %c", &op);
        if (op == '+') {
            res = add(x, y);
            break;
        } else if (op == '*') {
            res = multiple(x, y);
            break;
        } else {
            printf("Invalid operator!\n");
        }
    }
    printf("Ans : %d\n", res);
}

int add(int x, int y) {
    return x + y;
}

int multiple(int x, int y) {
    return x * y;
}
