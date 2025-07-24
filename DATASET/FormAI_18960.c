//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[1000];
    int totalCount = 0;

    printf("Enter a string: ");
    fgets(inputString, 1000, stdin);

    // Counting words
    for (int i = 0; i < strlen(inputString); i++)
    {
        // Checking for spaces and newline character
        if (inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t')
        {
            totalCount++;
        }
    }

    printf("Total number of words in the input string: %d\n", totalCount);
    return 0;
}