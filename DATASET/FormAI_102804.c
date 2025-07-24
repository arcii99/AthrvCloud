//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(char* string);

int main()
{
    char input[1000];
    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter a sentence or paragraph to count the number of words: ");

    fgets(input, 1000, stdin);

    int wordCount = countWords(input);

    printf("The number of words in your input is: %d\n", wordCount);

    return 0;
}

int countWords(char* string)
{
    int count = 0;
    int i;
    int stringLength = strlen(string);

    // Check each character in the string
    for (i = 0; i < stringLength; i++)
    {
        // If the current character is a whitespace or a newline character, increment the word count
        if (isspace(string[i]) || string[i] == '\n')
        {
            count++;
        }
    }

    // If the last character in the string is not a whitespace or a newline character, increment the word count
    if (!(isspace(string[stringLength - 1]) || string[stringLength - 1] == '\n'))
    {
        count++;
    }

    return count;
}