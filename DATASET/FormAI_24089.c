//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char fileName[100];
    FILE *file;
    printf("Please enter the name of the file: ");
    fgets(fileName, 100, stdin);
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Invalid file name or file does not exist!\n");
        return 0;
    }
    char c, prevC;
    int tabs = 0, spaces = 0, newLine = 1;
    printf("Beautified code:\n");
    while ((c = fgetc(file)) != EOF) {
        if (c == '<') {
            if (prevC == '/' || prevC == '=') {
                printf("%c", c);
            } else {
                printf("\n");
                for (int i = 0; i < tabs; i++) {
                    printf("\t");
                }
                printf("%c", c);
            }
            newLine = 0;
        } else if (c == '>') {
            printf("%c", c);
            newLine = 1;
        } else if (c == '/') {
            printf("%c", c);
        } else if (newLine == 1 && (c == ' ' || c == '\t')) {
            continue;
        } else if (c == '\n') {
            printf("%c", c);
            newLine = 1;
        } else {
            printf("%c", c);
            newLine = 0;
        }
        prevC = c;
        if (newLine == 1) {
            if (prevC == '/') {
                tabs--;
            }
            for (int i = 0; i < spaces; i++) {
                printf(" ");
            }
            spaces = 0;
        } else {
            if (c == '>' && (prevC == '/' || prevC == '=')) {
                tabs--;
            }
            if (prevC == '/' && c != '>') {
                tabs++;
            }
            spaces++;
        }
    }
    fclose(file);
    return 0;
}