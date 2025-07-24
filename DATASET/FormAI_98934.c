//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main()
{
    char english[1000], cclt[1000];
    int i, j;

    printf("Enter an English sentence to translate to CCLT:\n");
    scanf("%[^\n]s", english);

    for(i=0, j=0; i<strlen(english); i++)
    {
        if(english[i] == ' ')
        {
            cclt[j++] = 'm';
            cclt[j++] = 'e';
            cclt[j++] = 'o';
            cclt[j++] = 'w';
        }
        else if(english[i] >= 65 && english[i] <= 90)
        {
            cclt[j++] = english[i] + 32;
        }
        else if(english[i] >= 97 && english[i] <= 122)
        {
            cclt[j++] = english[i];
        }
    }

    printf("\nTranslated sentence in CCLT: %s", cclt);

    return 0;
}