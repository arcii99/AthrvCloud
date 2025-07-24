//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

int countWords(char* string) {
    int wordCount = 0;
    int isChar = 0;

    for(int i=0; i<strlen(string); i++) {
        if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
            isChar = 1;
        } else {
            wordCount += isChar;
            isChar = 0;
        }
    }

    return wordCount + isChar;
}

int main() {
    char userInput[MAX_CHARS];

    printf("Enter a string: ");
    fgets(userInput, MAX_CHARS, stdin);
    userInput[strcspn(userInput, "\n")] = 0;

    int wordCount = countWords(userInput);
    printf("\nWord count: %d\n", wordCount);

    return 0;
}