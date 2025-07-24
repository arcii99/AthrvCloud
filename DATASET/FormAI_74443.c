//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LANG 10

int main()
{
    char words[MAX_WORDS][MAX_LANG];
    char c;
    int i = 0, j = 0;
    int rows = 0;

    // Take input from the user until enter key is pressed without any input
    printf("Enter words in the Alien Language: ");
    while((c = getchar()) != '\n')
    {
        if(c == ' ')
        {
            words[i][j++] = '\0';
            i++;
            j = 0;
        }
        else
        {
            words[i][j++] = c;
        }
    }
    words[i][j++] = '\0';
    rows = i + 1;

    // Print the Alien Language
    printf("You have entered the Alien Language:\n");
    for(i = 0; i < rows; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Translate the Alien Language to English
    printf("\nTranslation in English:\n");
    for(i = 0; i < rows; i++)
    {
        if(strcmp(words[i], "Zorp") == 0)
        {
            printf("Hello ");
        }
        else if(strcmp(words[i], "Moolah") == 0)
        {
            printf("Money ");
        }
        else if(strcmp(words[i], "Flam") == 0)
        {
            printf("Fire ");
        }
        else if(strcmp(words[i], "Gleep") == 0)
        {
            printf("Water ");
        }
        else if(strcmp(words[i], "Plof") == 0)
        {
            printf("Boom ");
        }
        else if(strcmp(words[i], "Plart") == 0)
        {
            printf("Laugh ");
        }
        else if(strcmp(words[i], "Noot") == 0)
        {
            printf("Me ");
        }
        else if(strcmp(words[i], "Woozle") == 0)
        {
            printf("You ");
        }
        else if(strcmp(words[i], "Flibbertigibbet") == 0)
        {
            printf("Crazy ");
        }
        else if(strcmp(words[i], "Bletchley Park") == 0)
        {
            printf("Code ");
        }
        else
        {
            printf("%s ", words[i]);
        }
    }
    printf("\n");

    return 0;
}