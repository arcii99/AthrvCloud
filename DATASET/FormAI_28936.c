//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include<stdio.h>
#include<string.h>
#define MAX_WORDS 1000

int main()
{
    char alienLanguage[MAX_WORDS][100], word[100];
    int i, j, len, flag, totalWords = 0;

    printf("Enter the number of words in the alien language: ");
    scanf("%d", &totalWords);

    for(i=0; i<totalWords; i++)
    {
        printf("Enter word %d: ", i+1);
        scanf("%s", alienLanguage[i]);
    }

    printf("\nEnter the word to be translated: ");
    scanf("%s", word);

    for(i=0; i<strlen(word); )
    {
        flag = 0;
        for(j=0; j<totalWords; j++)
        {
            len = strlen(alienLanguage[j]);
            if(strncmp(word+i, alienLanguage[j], len) == 0)
            {
                printf("%c", j+65); //Mapping each word to a unique ASCII character (A, B, C, etc.)
                i += len; //Moving to the next non-matching characters
                flag = 1;
                break;
            }
        }
        if(flag == 0) //If no match found for current sub-string
        {
            printf("\nInvalid input! The input word doesn't belong to the alien language.");
            return 0;
        }
    }

    return 0;
}