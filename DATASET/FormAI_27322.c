//FormAI DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int main()
{
    char text[1000];
    printf("Enter the text that requires spell check:\n");
    fgets(text, sizeof(text), stdin);
    printf("\n");

    char dictionaryWords[370100][100], dictionaryWord[100], dictionary[370100];
    int i = 0, j = 0, k = 0, n = 0, dictionarySize = 0, isFound = 0, wordCount = 0, noMatch = 0;

    FILE *dictionaryFile;
    dictionaryFile = fopen("dictionary.txt", "r");

    while((dictionary[k] = fgetc(dictionaryFile)) != EOF)
    {
        if(dictionary[k] == '\n')
        {
            dictionary[k] = '\0';
            strcpy(dictionaryWords[i], dictionary);
            k = 0;
            i++;
        }
        else
        {
            k++;
            dictionarySize++;
        }
    }
    fclose(dictionaryFile);

    for(int a = 0; a < strlen(text); a++)
    {
        if(isalpha(text[a]))
        {
            dictionaryWord[j] = text[a];
            j++;
        }
        else if(text[a] == ' ' || text[a] == '\n' || text[a] == '\0')
        {
            wordCount++;
            dictionaryWord[j] = '\0';
            j = 0;
            for(int b = 0; b < dictionarySize; b++)
            {
                if(strcmp(dictionaryWords[b], dictionaryWord) == 0)
                {
                    isFound = 1;
                    break;
                }
            }
            if(isFound == 0)
            {
                printf("The word %s is misspelled!\n", dictionaryWord);
                noMatch++;
            }
            isFound = 0;
        }
    }

    if(noMatch == 0)
    {
        printf("No misspelled words found!\n");
    }
    else
    {
        printf("Total misspelled words found: %d\n", noMatch);
    }
    return 0;
}