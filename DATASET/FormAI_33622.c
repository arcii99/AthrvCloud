//FormAI DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main()
{
    char inputString[MAX_STRING_LENGTH];
    char word[MAX_STRING_LENGTH];
    int count = 0, i = 0, j = 0, flag = 0;

    printf("Enter the string: ");
    fgets(inputString, MAX_STRING_LENGTH, stdin);

    printf("Enter the word whose occurrence you want to find: ");
    scanf("%s", word);

    for(i=0; i<strlen(inputString); i++)
    {
        if(inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\t')
        {
            flag = 0;
        }
        else if(flag == 0)
        {
            flag = 1;
            if(inputString[i] == word[j])
            {
                j++;
                if(j == strlen(word))
                {
                    count++;
                    j = 0;
                }
            }
            else
            {
                j = 0;
            }
        }
    }

    printf("The word '%s' occurs %d times in the given string.", word, count);

    return 0;
}