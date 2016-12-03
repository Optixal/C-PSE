#include <stdio.h>

void main() {
    FILE *in;
    FILE *out;
    int value;

    int chars = 0;
    int lines = 0;
    int words = 0;

    in = fopen("fox.txt", "rb");
    if (in) {
        while(1) {
            value = fgetc(in);
            if (value == EOF) {
                break;
            } else if (value == ' ') {
                chars++;
                words++;
            } else if (value == '\n') {
                lines++;
                words++;
            } else {
                chars++;
            }
        }
        fclose(in);
    }

    out = fopen("fox_stats.txt", "wb");
    if (out) {
        fprintf(out, "Char Count: %d\n", chars);
        fprintf(out, "Line Count: %d\n", lines);
        fprintf(out, "Word Count: %d\n", words);
        fclose(out);
    }
}
