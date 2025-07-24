//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void beautify(char* html_file) {
    FILE* fp;
    char c, next_c;
    int indent = 0;
    fp = fopen(html_file, "r+");
    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            next_c = fgetc(fp);
            if (next_c == '/') {
                indent--;
                printf("\n");
                for (int i = 0; i < indent; i++) {
                    printf("    ");
                }
            }
            else {
                printf("\n");
                for (int i = 0; i < indent; i++) {
                    printf("    ");
                }
                indent++;
            }
            printf("<%c", next_c);
        }
        else if (c == '>') {
            printf(">");
        }
        else {
            printf("%c", c);
        }
    }
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./beautify <html_file>");
        exit(1);
    }
    char* html_file = argv[1];
    beautify(html_file);
    return 0;
}