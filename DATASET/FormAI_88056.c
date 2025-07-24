//FormAI DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid arguments. Usage: ./wordcount <filename.txt>\n");
        exit(1);
    }
    
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    int wordCount = 0, charCount = 0, lineCount = 0;
    char c, prevChar = ' ';
    while ((c = getc(f)) != EOF) {
        if (c == '\n') {
            lineCount++;
        }
        if (isspace(c) && !isspace(prevChar)) {
            wordCount++;
        }
        if (!isspace(c)) {
            charCount++;
        }
        prevChar = c;
    }
    if (!isspace(prevChar)) {
        wordCount++;
    }
    
    printf("Word count: %d\n", wordCount);
    printf("Character count: %d\n", charCount);
    printf("Line count: %d\n", lineCount);
    
    fclose(f);
    return 0;
}