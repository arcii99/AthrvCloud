//FormAI DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Please provide a C program to parse.\n");
        exit(1);
    }

    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char ch = getc(fp);
    while (ch != EOF) {

        if (ch == '/') {
            char next_ch = getc(fp);
            if (next_ch == '/') {
                while (ch != '\n') {
                    ch = getc(fp);
                }
            }
            else if (next_ch == '*') {
                ch = getc(fp);
                next_ch = getc(fp);

                while (!(ch == '*' && next_ch == '/')) {
                    ch = next_ch;
                    next_ch = getc(fp);
                }
            }
        }

        putchar(ch);
        ch = getc(fp);
    }

    fclose(fp);
    return 0;
}