//FormAI DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {

    char inputString[MAX_STRING_LENGTH];
    int i, wordCount;

    printf("Please enter a string: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);

    wordCount = 0;

    for (i = 0; i < strlen(inputString) - 1; i++) {

        if (inputString[i] == ' ' && inputString[i + 1] != ' ') {
            wordCount++;
        }

    }

    if (inputString[0] != ' ') {
        wordCount++;
    }

    printf("The number of words in this string is: %d", wordCount);

    return 0;
}