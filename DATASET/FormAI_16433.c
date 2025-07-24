//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i=0, len=0;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter a sentence in Cat Language: ");
    fgets(str, 100, stdin);

    len = strlen(str);

    printf("\nThe translation of your sentence in human language is: ");

    for(i=0; i<len; i++)
    {
        if(str[i] == 'M')
        {
            printf("Meow ");
        }
        else if(str[i] == 'P')
        {
            printf("Purr ");
        }
        else if(str[i] == 'H')
        {
            printf("Hiss ");
        }
        else if(str[i] == 'C')
        {
            printf("Chirp ");
        }
        else if(str[i] == 'A')
        {
            printf("Paw gesture ");
        }
        else if(str[i] == 'B')
        {
            printf("Blink ");
        }
        else if(str[i] == 'R')
        {
            printf("Rub body ");
        }
        else if(str[i] == 'L')
        {
            printf("Lick ");
        }
        else if(str[i] == 'S')
        {
            printf("Scratch something ");
        }
    }

    printf("\nThank you for using our C Cat Language Translator!");

    return 0;
}