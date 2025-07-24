//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main()
{
    char phrase[100];
    printf("Enter a phrase in Cat language: ");
    scanf("%[^\n]", phrase);

    // Translation Logic

    int i = 0;
    char translated_phrase[200] = "";
    while (phrase[i] != '\0')
    {
        switch (phrase[i])
        {
        case 'M': strcat(translated_phrase, "Meow"); break;
        case 'N': strcat(translated_phrase, "Nyan"); break;
        case 'P': strcat(translated_phrase, "Purr"); break;
        case 'C': strcat(translated_phrase, "Chirp"); break;
        default: strcat(translated_phrase, "Meow"); break;
        }

        i++;
    }

    printf("Translation: %s\n", translated_phrase);

    return 0;
}