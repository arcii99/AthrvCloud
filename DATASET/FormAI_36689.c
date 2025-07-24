//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include<stdio.h>
#include<string.h>

int main()
{
    char alien[100], translated[100];
    int i, j, length;

    printf("Welcome to the Alien Language Translator!\n");
    printf("-----------------------------------------\n");

    printf("Enter the word/phrase in the Alien language: ");
    fgets(alien, sizeof(alien), stdin);

    length = strlen(alien);

    // Translation Logic

    // Replace all 'r' with 'l'
    for(i=0; i<length; i++)
    {
        if(alien[i] == 'r')
        {
            translated[i] = 'l';
        }
        else
        {
            translated[i] = alien[i];
        }
    }

    // Replace all vowels with 'o'
    for(i=0; i<length; i++)
    {
        if(translated[i] == 'a' || translated[i] == 'e' || translated[i] == 'i' || translated[i] == 'o' || translated[i] == 'u')
        {
            translated[i] = 'o';
        }
    }

    // Add 'k' at the end of the word
    length = strlen(translated);
    translated[length-1] = 'k';
    translated[length] = '\0';

    printf("\nThe translated word/phrase is: %s\n", translated);

    return 0;
}