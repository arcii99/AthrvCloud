//FormAI DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count words
int countWords(char *str)
{
    int count = 0;
    char *tok;
    tok = strtok(str, " ");
    while(tok != NULL)
    {
        count++;
        tok = strtok(NULL, " ");
    }
    return count;
}

int main()
{
    char inputString[1000];
    printf("Enter a sentence: ");
    fgets(inputString, 1000, stdin);
    // Remove '\n' from the input
    inputString[strcspn(inputString, "\n")] = 0;
    int words = countWords(inputString);
    printf("The number of words in the sentence is: %d", words);
    return 0;
}