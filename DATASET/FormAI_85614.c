//FormAI DATASET v1.0 Category: Word Count Tool ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char paragraph[1000];
    int wordCount = 0, i;

    printf("Enter a paragraph: ");
    fgets(paragraph, 1000, stdin);

    // Loop through all characters in paragraph
    for(i = 0; i < strlen(paragraph); i++) {
        // Check for spaces and new lines
        if (paragraph[i] == ' ' || paragraph[i] == '\n') {
            wordCount++;
        }
    }

    // Check if paragraph ends in a word or not
    if (paragraph[strlen(paragraph) - 1] != ' ' && paragraph[strlen(paragraph) - 1] != '\n') {
        wordCount++;
    }

    printf("Total words in paragraph: %d", wordCount);

    return 0;
}