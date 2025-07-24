//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char surrealWords[10][10] = {"cucumber", "rainbow", "butterfly", "toaster", "dolphin", "unicorn", "jellyfish", "tulip", "bubble", "flamingo"};

int main() {
    char input[100];
    printf("Please enter a sentence to spell check: ");
    fgets(input, sizeof(input), stdin);

    char *word = strtok(input, " ");
    while (word != NULL) {
        int isSurreal = 0;
        for (int i = 0; i < 10; i++) {
            if (strcmp(word, surrealWords[i]) == 0) {
                isSurreal = 1;
                break;
            }
        }

        if (isSurreal) {
            printf("The word '%s' is spelled correctly, but it's too surreal for our database of words.\n", word);
        } else {
            printf("The word '%s' is spelled incorrectly.\n", word);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}