//FormAI DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a single word is spelled correctly
int spell_check(char *word) {

    // Initialize dictionary
    char dictionary[5][10] = {"peace", "love", "harmony", "kindness", "gentle"};

    // Remove punctuation and make all letters lowercase
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (ispunct(word[i])) {
            memmove(&word[i], &word[i + 1], len - i);
            len--;
            i--;
        }
        else {
            word[i] = tolower(word[i]);
        }
    }

    // Check if word is in dictionary
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is spelled correctly
        }
    }
    return 0; // Word is misspelled
}

int main() {
    printf("Enter a sentence: ");

    // Read in sentence
    char sentence[1000];
    fgets(sentence, 1000, stdin);

    // Check each word in sentence for spelling
    char *token;
    char delimiters[] = " ,.!?\n";
    token = strtok(sentence, delimiters);
    while (token != NULL) {
        int spelled_correctly = spell_check(token);
        if (spelled_correctly) {
            printf("%s ", token); // Word is spelled correctly
        }
        else {
            printf("*%s* ", token); // Word is misspelled, indicate with *
        }
        token = strtok(NULL, delimiters);
    }

    printf("\n");

    return 0;
}