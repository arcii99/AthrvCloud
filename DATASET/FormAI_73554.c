//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

void main()
{
    printf("\nWelcome to the C Cat Language Translator!\n");

    printf("\nEnter a sentence in C Cat Language:\n");

    char sentence[100];
    scanf("%[^\n]%*c", sentence); // reading input sentence

    printf("\nTranslating...\n");

    // Converting C Cat Language into English using if-else statements
    if(strcmp(sentence,"meow") == 0)
    {
        printf("I'm hungry\n");
    }
    else if(strcmp(sentence,"purr") == 0)
    {
        printf("I'm happy\n");
    }
    else if(strcmp(sentence,"hiss") == 0)
    {
        printf("I'm angry\n");
    }
    else if(strcmp(sentence,"scratch") == 0)
    {
        printf("I need attention\n");
    }
    else if(strcmp(sentence,"run") == 0)
    {
        printf("I'm scared\n");
    }
    else
    {
        printf("I have no idea what you're saying, meow!\n");
    }

    printf("\nThanks for using our C Cat Language Translator. Have a meow-tastic day! :D \n");
}