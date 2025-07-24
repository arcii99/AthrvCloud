//FormAI DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countWords(char *inputString) {
    int wordCount = 0;
    char *token = strtok(inputString, " "); //Split the string by space
    while (token != NULL) {
        wordCount++; // If a word splitted increment wordCount
        token = strtok(NULL, " ");
    }

    printf("\nTotal words: %d", wordCount);
}

int main() {
    char inputString[10000];

    printf("Enter the string to count words: ");
    fgets(inputString, sizeof(inputString), stdin); // Get Input string

    countWords(inputString); // Call the function

    return 0;
}