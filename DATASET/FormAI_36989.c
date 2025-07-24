//FormAI DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int wordCount = 0;
    char currentChar, previousChar, newLineChar;

    previousChar = newLineChar = ' ';

    printf("Enter text (press Ctrl + D to quit):\n");

    while ((currentChar = getchar()) != EOF) {

        if (isspace(currentChar)) {
            if (previousChar != '\n') {
                ++wordCount;
            }
            previousChar = currentChar;
        }

        else if (currentChar != '\n') {
            previousChar = currentChar;
        }

        else {
            newLineChar = currentChar;
            previousChar = currentChar;
        }
    }

    if (previousChar != '\n') {
        ++wordCount;
    }

    if (newLineChar != '\n') {
        ++wordCount;
    }

    printf("The text contains %d words.\n", wordCount);

    return EXIT_SUCCESS;
}