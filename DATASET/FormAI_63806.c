//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

int main()
{
    char alien_languages[10][15] = {"qwakkqwakkqwaak", "flibbertigibbet", "zoopadoopa"};
    char english_translations[10][15] = {"hello", "goodbye", "thank you"};
    char input[15];
    int i, j, found;

    printf("Welcome to the Alien Language Translator!\n");

    while (1) {
        printf("\nEnter a word in an alien language or type 'quit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            printf("\nThank you for using the Alien Language Translator. Goodbye!\n");
            break;
        }

        found = 0;
        for (i = 0; i < 10; i++) {
            if (strcmp(input, alien_languages[i]) == 0) {
                printf("\nTranslation: %s\n", english_translations[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nThe entered word was not found in the database. Please try again.\n");
        }
    }

    return 0;
}