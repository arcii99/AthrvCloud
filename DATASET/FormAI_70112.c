//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Define list of known words
char dictionary[][50] = {"future", "futuristic", "innovative", "technology"};

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word) {
    for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is misspelled
int is_misspelled(char *word) {
    // Check if word is in dictionary
    if (is_in_dictionary(word)) {
        return 0;
    }
    // Add futuristic spell-checking algorithm here
    // ...
}

int main() {
    // Read input text from user
    printf("Enter text to spell-check:\n");
    char text[1000];
    fgets(text, sizeof(text), stdin);

    // Split text into words
    char *word = strtok(text, " ");
    while (word != NULL) {
        // Remove any non-alphabetic characters
        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        // Check if word is misspelled
        if (is_misspelled(word)) {
            printf("Misspelled word: %s\n", word);
        }
        // Get next word
        word = strtok(NULL, " ");
    }

    return 0;
}