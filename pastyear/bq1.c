#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 0;
    }

    FILE * fpIn = fopen(argv[1], "r");
    FILE * fpOut = fopen(argv[2], "w+");

    int size = 128;
    char buff[size];
    while (fgets(buff, size, fpIn) != NULL) {
        int i;
        for (i = 0; i < size; i++) {
            if (buff[i] >= 97 && buff[i] <= 122) buff[i] -= 32;
        }
        fputs(buff, fpOut);
    }
}
