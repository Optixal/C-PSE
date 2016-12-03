#include <stdio.h>

void main() {
    FILE *in;
    FILE *out;
    int value;

    int chars = 0;
    int lines = 0;
    int words = 0;

    int wordDetected = 0;

    in = fopen("fox.txt", "rb");
    if (in) {
        while(1) {
            value = fgetc(in);
            if (value == EOF) {
                if (wordDetected) {
                    words++;
                }
                break;
            } else if (value >= 65 && value <= 122) {
                /* Word detected */
                chars++;
                wordDetected = 1;
            } else if (value == ' ') {
                /* Word detection ended */
                if (wordDetected) {
                    words++;
                    wordDetected = 0;
                }
            } else if (value == '\n') {
                lines++;
                if (wordDetected) {
                    words++;
                    wordDetected = 0;
                }
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
