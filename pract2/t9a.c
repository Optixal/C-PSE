#include <stdio.h>

int main() {
    int marks;
    printf("Please enter your marks: ");
    scanf("%d", &marks);
    if (marks >= 80) {
        printf("A\n");   
    } else if (marks >= 70) {
        printf("B\n");
    } else if (marks >= 60) {
        printf("C\n");
    } else if (marks >= 50) {
        printf("D\n");
    } else if (marks >= 40) {
        printf("E\n");
    } else {
        printf("F\n");
    }
    return 0;
}
