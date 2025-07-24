//FormAI DATASET v1.0 Category: Spell checking ; Style: energetic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence to check for spelling errors: ");
    fgets(input, 100, stdin);

    char dictionary[][15] = {"apple", "banana", "cherry", "orange", "peach", "grape", "lemon", "melon", "pear", "plum"};
    int numWords = sizeof(dictionary) / sizeof(dictionary[0]);
    int counter = 0;

    char *word = strtok(input, " ,.-\n");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcasecmp(word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Did you mean: ");
            for (int j = 0; j < strlen(word); j++) {
                if (!ispunct(word[j])) {
                    printf("%c", toupper(word[j]));
                }
            }
            printf("? ");
            counter++;
        }
        word = strtok(NULL, " ,.-\n");
    }

    if (counter == 0) {
        printf("Great job! No spelling errors were found.\n");
    } else {
        printf("\n%d spelling errors were found in the sentence. Please double check your spelling.\n", counter);
    }

    return 0;
}