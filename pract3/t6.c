#include <stdio.h>
#include <string.h>
#define BUF_SZ 256

void reverse(char str[]) {
    int len = strlen(str);
    char new_str[len];
    int i, j;
    for (i = len - 2, j = 0; i >= 0; i--, j++) {
       new_str[j] = str[i];
    }
    new_str[len - 1] = '\0';
    strcpy(str, new_str);
}

int main() {
    char mesg[BUF_SZ];
    printf("Enter a message please=>");
    fgets(mesg, BUF_SZ, stdin);
    reverse(mesg);
    printf("%s\n", mesg);
    return 0;
}
