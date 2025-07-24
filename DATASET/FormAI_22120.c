//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Welcome to the Amazing Spell Checking Program!\n\n");

    // Ask user to enter a sentence
    printf("Please enter a sentence: ");
    char sentence[100];
    scanf("%[^\n]", sentence);

    // Convert sentence to lowercase
    for (int i = 0; sentence[i]; i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Check each word for spelling errors
    char word[20];
    int is_word = 0;
    int error_count = 0;
    for (int i = 0, j = 0; sentence[i]; i++) {
        if (isalpha(sentence[i])) {
            word[j++] = sentence[i];
            is_word = 1;
        } else if (is_word) {
            word[j] = '\0';
            // Check if the word is spelled correctly
            if (strcmp(word, "amazing") != 0 && strcmp(word, "program") != 0) {
                printf("Error: %s is misspelled\n", word);
                error_count++;
            }
            j = 0;
            is_word = 0;
        }
    }

    // Print results
    printf("\n\n");
    if (error_count == 0) {
        printf("Congratulations, your sentence has no spelling errors!\n");
    } else {
        printf("There were %d spelling errors in your sentence.\n", error_count);
    }
    return 0;
}