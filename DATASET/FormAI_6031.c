//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 //Maximum word length for the program

int countWords(char *str);
int isStringValid(char *str);

int main()
{
    char input[MAX_WORD_LENGTH];
    int wordCount = 0;

    printf("Enter a sentence: \n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    if(isStringValid(input))
    {
        wordCount = countWords(input);
        printf("The number of words in the sentence is %d\n", wordCount);
    }
    else
    {
        printf("Invalid input!\n");
    }

    return 0;
}

int countWords(char *str)
{
    int wordCount = 0, i;

    for(i = 0; str[i] != '\0'; i++)
    {
        //If a whitespace or new line is encountered, increment word count
        if(isspace(str[i]) || str[i] == '\n')
        {
            wordCount++;
        }
    }

    return wordCount;
}

int isStringValid(char *str)
{
    int stringLength = 0, i;
    char c;

    for(i = 0; str[i] != '\0'; i++)
    {
        c = str[i];

        //Check if string only contains letters, numbers, spaces and punctuations
        if(!isalnum(c) && !isspace(c) && !ispunct(c))
        {
            return 0;
        }

        stringLength++;
    }

    //Check if string is not empty and does not end with a newline
    if(stringLength > 1 && str[stringLength-2] != '\n')
    {
        return 1;
    }

    return 0;
}