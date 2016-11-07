#include <stdio.h>
#include <stdlib.h>

int getMark();
void display(char grade);
char convert(int marks);

int main() {
    for (;;) {
        int marks = getMark();
        char grade = convert(marks);
        display(grade);
    }
}

int getMark() {
    char marks[64];
    int marks_int;
    /* size_t nbytes = 255;
     * size_t bytes_read;
     * char buf[256];
     * char *buf_ptr = buf; */
    while (1) {
        printf("Enter the score (0-100)\n");
        printf("Or Just Press the Enter key to quit==> ");
        fgets(marks, 5, stdin);
        /* bytes_read = getline(&buf_ptr, &nbytes, stdin); */
        if (marks[0] == '\n') {
            printf("Thank You. See you again soon\n");
            exit(0);
        }

        marks_int = atoi(marks);
        if (!marks_int || marks_int < 0 || marks_int > 100) {
           printf("Invalid Input, please try again\n"); 
           continue;
        } else {
            break;
        }
    }
    return marks_int;
}

void display(char grade) {
    printf("The grade for the input score is %c\n", grade);
}

char convert(int marks) {
    if (marks >= 80) {
        return 'A';
    } else if (marks >= 70) {
        return 'B';
    } else if (marks >= 60) {
        return 'C';
    } else if (marks >= 50) {
        return 'D';
    } else if (marks >= 40) {
        return 'E';
    } else {
        return 'F';
    }
}
