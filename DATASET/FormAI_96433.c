//FormAI DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 1000 // maximum length of input string

int main()
{
    char input[MAXLENGTH];
    printf("Enter a string: ");
    fgets(input, MAXLENGTH, stdin); // user inputs string

    int wordCount = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        // if current character is a whitespace and previous character is not a whitespace, increase word count
        if (isspace(input[i]) && !isspace(input[i-1]))
        {
            wordCount++;
        }
    }

    // check if the last character is not a whitespace, which indicates the end of a word
    if (!isspace(input[length-2]))
    {
        wordCount++;
    }

    printf("Word count: %d\n", wordCount);

    return 0;
}