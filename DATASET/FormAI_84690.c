//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the C Cat Language Translator!\n\n");
    printf("Please enter the sentence you would like to translate:\n");

    char sentence[100];
    fgets(sentence, 100, stdin);

    printf("\nYour translated sentence in C Cat Language is:\n");

    // Loop through the sentence and replace "meow" with "C"
    int len = strlen(sentence);
    for (int i = 0; i < len; i++)
    {
        if (sentence[i] == 'm' && sentence[i+1] == 'e' && sentence[i+2] == 'o' && sentence[i+3] == 'w')
        {
            printf("C");
            i += 3;
        }
        else
        {
            printf("%c", sentence[i]);
        }
    }

    printf("\n\nThank you for using the C Cat Language Translator!");
    return 0;
}