//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char alienLanguage[10][20] = {"kra", "gul", "zot", "fle", "plo", "lur", "bin", "tam", "qin", "xel"}; // 10 words in Alien Language
    char english[10][20] = {"hello", "goodbye", "world", "planet", "moon", "star", "galaxy", "universe", "alien", "spaceship"}; // Corresponding English words

    char input[20];
    printf("Enter an Alien word: ");
    scanf("%s", input);

    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(input, alienLanguage[i]) == 0) {
            printf("The English equivalent of '%s' is '%s'\n", input, english[i]);
            break;
        }
    }

    if (i == 10) {
        printf("Sorry, I don't know the English equivalent of '%s'\n", input);
    }

    return 0;
}