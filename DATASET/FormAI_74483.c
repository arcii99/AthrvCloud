//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Alien Language Translator!\n");

    char alien_language[50];
    char english_translation[50];

    printf("Enter the alien language word: ");
    scanf("%s", alien_language);

    if(strcmp(alien_language, "alienword") == 0)
    {
        printf("The English translation of 'alienword' is 'hello'.\n");
    }
    else if (strcmp(alien_language, "anotheralienword") == 0)
    {
        printf("The English translation of 'anotheralienword' is 'goodbye'.\n");
    }
    else if (strcmp(alien_language, "thirdalienword") == 0)
    {
        printf("The English translation of 'thirdalienword' is 'thank you'.\n");
    }
    else
    {
        printf("I'm sorry, I don't know that alien word.\n");
    }

    return 0;
}