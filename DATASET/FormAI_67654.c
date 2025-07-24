//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <string.h>

// function declarations
void calculateWordCount(char*);

int main()
{
    char inputString[1000];

    printf("Enter a sentence: ");
    fgets(inputString, 1000, stdin);

    calculateWordCount(inputString);

    return 0;
}

void calculateWordCount(char* inputString)
{
    int wordCount = 0;
    int length = strlen(inputString);
    char prevChar = ' ';

    for (int i = 0; i < length; i++) {
        char curChar = inputString[i];
        if (curChar != ' ' && prevChar == ' ') {
            wordCount++;
        }
        prevChar = curChar;
    }

    printf("The sentence contains %d words.\n", wordCount);
}