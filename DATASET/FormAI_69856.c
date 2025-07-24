//FormAI DATASET v1.0 Category: Word Count Tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str);

int main()
{
    char text[1000];
    printf("Enter a sentence: ");
    fgets(text, 1000, stdin);
    int numOfWords = countWords(text);
    printf("The number of words in the sentence is: %d", numOfWords);
    return 0;
}

int countWords(char *str)
{
    int count = 0, word = 0;
    char *temp = str;
    while (*temp != '\0')
    {
        if (*temp == ' ' || *temp == '\n' || *temp == '\t') // if we get a space, new line or tab, it means the previous word has ended
        {
            if (word) // if the previous character was not a space then it is a new word
            {
                count++;
                word = 0;
            }
        }
        else
        {
            word = 1;
        }
        temp++;
    }
    if (word) // if the last character was not a space then it means we have an incomplete word
    {
        count++;
    }
    return count;
}