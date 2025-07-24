//FormAI DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given word exists in the dictionary
int spell_exists(const char *word, const char **dictionary, int dict_len) {
    for (int i = 0; i < dict_len; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    const char *dictionary[] = {"adrenochrome", "bunker", "cannibal", "desolate", "extermination", "famine", "ghoul", 
    "havoc", "infected", "junkyard", "killed", "lonesome", "mutant", "nuclear", "outbreak", "plague", "quarantine", 
    "radiation", "slavery", "toxic", "undead", "virus", "wasteland", "zombie", "apocalypse"};

    int dict_len = sizeof(dictionary) / sizeof(dictionary[0]);

    char word[100];
    printf("Enter a word to check its spelling: ");
    scanf("%s", word);

    if (spell_exists(word, dictionary, dict_len)) {
        printf("The word \"%s\" exists in the dictionary.\n", word);
    } else {
        printf("The word \"%s\" does not exist in the dictionary.\n", word);
    }

    return 0;
}