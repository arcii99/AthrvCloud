//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main()
{
    char input[1000];
    char *wordList[100];
    int wordCount[MAX_WORD_LENGTH] = {0};
    int i, j, k, index = 0;
 
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    //Removing newline character from input
    input[strcspn(input, "\n")] = '\0';

    //Splitting input sentence into separate words
    char *token = strtok(input, " ");
    while(token != NULL)
    {
        wordList[index] = token;
        index++;
        token = strtok(NULL, " ");
    }

    //Finding word count for each length
    for(i=0; i<index; i++)
    {
        int length = strlen(wordList[i]);
        if(length > MAX_WORD_LENGTH)
        {
            printf("\nError: Maximum word length exceeded.");
            return 0;
        }
        wordCount[length-1]++;
    }

    //Printing word count for each length
    for(i=0; i<MAX_WORD_LENGTH; i++)
    {
        if(wordCount[i] != 0)
        {
            printf("Number of %d letter words: %d\n", i+1, wordCount[i]);
        }
    }

    return 0;
}