//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Alien Language Translator!\n\n");

    char alienLanguage[] = "Nbi nsp ciyegr rg ecru! Kyh'S xog M siyusv siab!";
    char translation[100];

    printf("The alien language phrase is: %s\n\n", alienLanguage);
    printf("Decrypting...\n\n");

    for(int i = 0; i < strlen(alienLanguage); i++)
    {
        if(alienLanguage[i] >= 'a' && alienLanguage[i] <= 'z')
        {
            translation[i] = 'z' - (alienLanguage[i] - 'a');
        }
        else if(alienLanguage[i] >= 'A' && alienLanguage[i] <= 'Z')
        {
            translation[i] = 'Z' - (alienLanguage[i] - 'A');
        }
        else
        {
            translation[i] = alienLanguage[i];
        }
    }

    printf("The translated phrase is: %s\n\n", translation);

    return 0;
}