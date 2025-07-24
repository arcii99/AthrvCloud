//FormAI DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 30
// Define the dictionary size
#define DICTIONARY_SIZE 10

// Dictionary of surrealistic words
char surreal_dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH] = {
    "Dali",
    "Surrealism",
    "Dreams",
    "Metamorphosis",
    "Absurdity",
    "Melting Clocks",
    "Reality",
    "Illusion",
    "Fantasy",
    "Unconsciousness"
};

// Returns 1 if a word is found in the dictionary
int spell_check(char* word)
{
    int i;
    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(word, surreal_dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char sentence[100];
    printf("Enter a surrealistic sentence: ");
    fgets(sentence, 100, stdin);

    // Remove the trailing newline character
    sentence[strcspn(sentence, "\n")] = 0;

    char* word = strtok(sentence, " ");
    int errors = 0;

    while (word != NULL) {
        if (!spell_check(word)) {
            printf("'%s' is not a surrealistic word. Are you sure this is a Dali-esque sentence?\n", word);
            errors++;
        }
        word = strtok(NULL, " ");
    }
    if (errors == 0) {
        printf("This is a Dali-esque sentence indeed.\n");
    }

    return 0;
}