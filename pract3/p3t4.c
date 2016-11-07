#include <stdio.h>

int lcm(int, int);

int main() {
    int n1, n2;
    printf("Enter the first integer please =>\n");
    scanf("%d", &n1);
    printf("Enter the second integer please =>\n");
    scanf("%d", &n2);
    printf("The LCM of %d and %d is %d\n", n1, n2, lcm(n1, n2));
}
