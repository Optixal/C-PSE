#include <stdio.h>

int main() {
    char * p = " are going to the park.\n";
    FILE * fp;
    fp = fopen("output.txt", "w+");
    fputs("Mary and Paul", fp);

    fseek(fp, 5, SEEK_SET);
    fputs("is", fp);
    p += 4;

    fputs(p, fp);
    fclose(fp);
    return(0);
}
