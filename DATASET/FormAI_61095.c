//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 10000

void countWords(char *inputString) {
    int i = 0;
    int wordCount = 0;
    char currentChar = inputString[0];
    while (currentChar != '\0') {
        currentChar = inputString[i];
        if (isspace(currentChar) || ispunct(currentChar)) {
            wordCount++;
        }
        i++;
    }
    printf("Word count: %d\n", wordCount);
}

int main() {
    printf("Enter a string: ");
    char inputString[MAX_STRING_LENGTH];
    fgets(inputString, MAX_STRING_LENGTH, stdin);
    countWords(inputString);
    return 0;
}