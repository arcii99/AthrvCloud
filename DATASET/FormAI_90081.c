//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

// Cat language dictionary
const char* CAT_LANGUAGE[] = {
    "meow",         // hello
    "purr",         // goodbye
    "hiss",         // angry
    "pounce",       // attack
    "paw",          // touch
    "nap",          // sleep
    "lick",         // love
    "hunt",         // play
    "fish",         // eat
    "mew",          // help
    "scratch",      // hurt
    "roll",         // happy
    "nip",          // bite
    "chase",        // follow
    "yawn",         // tired
    "flick",        // dislike
    "stretch",      // lazy
    "whiskers",     // cute
    "claw",         // sharp
    "rat",          // enemy
    "bird",         // friend
    "home",         // place
    "collar"        // identity
};

int main()
{
    char input[100];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a sentence in Cat language (using words from the dictionary):\n");
    fgets(input, 100, stdin);

    printf("Translating...\n");
    char* token = strtok(input, " ");
    while (token != NULL) {
        for (int i = 0; i < 23; i++) {
            if (strcmp(token, CAT_LANGUAGE[i]) == 0) {
                printf("%s ", CAT_LANGUAGE[i]);
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    printf("\nTranslation complete. Goodbye (purr)!\n");
    return 0;
}