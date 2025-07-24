//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char fileName[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        return -1;
    }

    char c;
    int wordCount = 0;
    int charCount = 0;
    int lineCount = 1; // Start with 1 as there is always at least one line

    // Read file character by character
    while ((c = fgetc(file)) != EOF) {
        charCount++;

        // Check for end of word
        if (isspace(c) || ispunct(c)) {
            wordCount++;
        }

        // Check for end of line
        if (c == '\n') {
            lineCount++;
        }
    }

    // Check if file ends with a word
    if (charCount > 0) {
        wordCount++;
    }

    printf("Word count: %d\n", wordCount);
    printf("Character count: %d\n", charCount);
    printf("Line count: %d\n", lineCount);

    fclose(file);

    return 0;
}