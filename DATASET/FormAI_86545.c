//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char alienLanguage[50];
    printf("Welcome to the Alien Language Translator.\n");
    printf("Please enter a word or phrase in the C Alien Language to translate:\n");
    scanf("%s", alienLanguage);

    printf("Translating \"%s\"...\n", alienLanguage);

    // Start translation code here
    int len = strlen(alienLanguage);
    for (int i = 0; i < len; i++) {
        int translation = alienLanguage[i] - 3;
        printf("%c", translation);
    }
    // End of translation code

    printf("\n\nTranslation complete.\n");

    return 0;
}