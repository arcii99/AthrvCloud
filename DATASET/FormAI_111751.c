//FormAI DATASET v1.0 Category: Word Count Tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputText[1000];
    int wordCount = 0;

    printf("Welcome to the Genius Word Count Tool!\n");
    printf("Enter your text here:\n");

    // Get input text from user
    fgets(inputText, 1000, stdin);

    // Remove newline character from input text if entered
    if (inputText[strlen(inputText) - 1] == '\n') {
        inputText[strlen(inputText) - 1] = '\0';
    }

    // Count number of words in input text
    for (int i = 0; i < strlen(inputText); i++) {
        if (inputText[i] == ' ' || inputText[i] == '\t' || inputText[i] == '\n') {
            wordCount++;
        }
    }

    // Add 1 to word count to account for last word if not followed by space
    if (inputText[strlen(inputText) - 1] != ' ' && inputText[strlen(inputText) - 1] != '\t' && inputText[strlen(inputText) - 1] != '\n') {
        wordCount++;
    }

    printf("\nYour text contains %d words. Genius!\n", wordCount);

    return 0;
}