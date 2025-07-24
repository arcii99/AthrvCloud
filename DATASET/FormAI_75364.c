//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the array of words to be translated
const char* englishWords[] = {"cat", "scratch", "meow", "purr", "mouse"};
const char* cCatWords[] = {"me", "claw", "mew", "rumble", "rat"};

int main() {
    char input[100];
    printf("Enter a sentence in English:\n");
    fgets(input, 100, stdin); // Get input from user
    
    // Tokenize the input sentence into words
    char* word = strtok(input, " ");
    while (word != NULL) {
        // Loop through the array of English words and check if the current word should be translated
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, englishWords[i]) == 0) { // Translate the word if it matches the English word
                printf("Translated: %s ", cCatWords[i]);
                break;
            }
        }
        // Print the word without translation if it does not match any English word
        if (strcmp(word, "\n") != 0) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }
    printf("\n");
    return 0;
}