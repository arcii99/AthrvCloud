//FormAI DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str);

int main()
{
    char input[1000];
    int numWords;
    
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);
    
    numWords = countWords(input);
    
    printf("Total number of words in the sentence: %d\n", numWords);
    
    return 0;
}

int countWords(char *str)
{
    int numWords = 0;
    int inWord = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            if(!inWord)
            {
                inWord = 1;
                numWords += 1;
            }
        }
        else
        {
            inWord = 0;
        }
    }
    
    return numWords;
}