#include <stdio.h>
#include <string.h>

void approach1(char *, char *, char *);
void approach2(char *, size_t, char *, char *);
void approach3(char *, char *, char *);

void main() {
    char userinput1[1000], userinput2[1000], combined[2000];

    printf("Enter first sentence: ");
    fgets(userinput1, sizeof(userinput1), stdin);
    printf("Enter second sentence: ");
    fgets(userinput2, sizeof(userinput2), stdin);

    approach1(userinput1, userinput2, combined);
    approach2(userinput1, sizeof(userinput1)/sizeof(char), userinput2, combined);
    approach3(userinput1, userinput2, combined);
}

void approach1(char *userinput1, char *userinput2, char *combined) {
    int i;
    for (i = 0;; i++) {
        if (userinput1[i] == '\n' || userinput1[i] == '\0') break;
        combined[i] = userinput1[i];
    }
    int j = i;
    for (j = 0;; j++) {
        if (userinput2[j] == '\n' || userinput2[j] == '\0') break;
        combined[i + j] = userinput2[j];
    }
    printf("Approach 1 Ans: %s\n", combined);
}

void approach2(char *userinput1, size_t length, char *userinput2, char *combined) {
    if (userinput1[strlen(userinput1) - 1] == '\n') {
        userinput1[strlen(userinput1) - 1] = '\0';
    }
    if (userinput2[strlen(userinput2) - 1] == '\n') {
        userinput2[strlen(userinput2) - 1] = '\0';
    }
    char userinput1_bak[length];
    strcpy(userinput1_bak, userinput1);
    combined = strcat(userinput1_bak, userinput2);
    printf("Approach 2 Ans: %s\n", combined);
}

void approach3(char *userinput1, char *userinput2, char *combined) {
    combined[0] = '\0';
    strcpy(combined, userinput1);
    sprintf(combined, "%s%s", combined, userinput2);
    printf("Approach 3 Ans: %s\n", combined);
}
