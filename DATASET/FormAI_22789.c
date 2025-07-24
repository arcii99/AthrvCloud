//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    char alien_language[] = "zzufrn jio, hjghre pqrzty dqwxjn cfklsa";
    char translated_language[100];
    int i;

    printf("Welcome to Alien Language Translator\n");
    printf("Original message in Alien Language: %s\n", alien_language);

    // translating the alien language
    for(i = 0; i < strlen(alien_language); i++)
    {
        if(alien_language[i] == 'z')
            translated_language[i] = 'a';
        else
            translated_language[i] = alien_language[i] + 1;
    }

    // adding null character at the end of the translated message
    translated_language[i] = '\0';

    printf("Translated message in English: %s\n", translated_language);

    return 0;
}