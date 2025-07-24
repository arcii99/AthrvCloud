//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the alien words
#define MAX_WORD_SIZE 100

// Define the number of different letters in the alien alphabet
#define NUM_LETTERS 6

// Define the index of each letter in the alien alphabet
const char LETTERS[NUM_LETTERS] = {'a', 'e', 'i', 'o', 'u', 'c'};

// Define the corresponding translation for each letter in the alien language
const char TRANSLATIONS[NUM_LETTERS][MAX_WORD_SIZE] = {
    "yabba",
    "dabba",
    "doo",
    "dabba",
    "dabba",
    "do"
};

// Function to translate a single word from the alien language
void translate_word(const char *word, char *output) {
    int i, j, index;
    // Initialize the output to an empty string
    output[0] = '\0';
    // Loop through each letter of the input word
    for (i = 0; word[i] != '\0'; i++) {
        // Find the index of the current letter in the alien alphabet
        index = -1;
        for (j = 0; j < NUM_LETTERS; j++) {
            if (word[i] == LETTERS[j]) {
                index = j;
                break;
            }
        }
        // If the current letter is not in the alien alphabet, skip it
        if (index == -1) {
            continue;
        }
        // Otherwise, append the corresponding translation to the output
        strcat(output, TRANSLATIONS[index]);
    }
}

// Main function to translate a sentence from the alien language
int main(int argc, char *argv[]) {
    char sentence[MAX_WORD_SIZE], translation[MAX_WORD_SIZE];
    // Get the input sentence from the user
    printf("Enter a sentence in the alien language:\n");
    fgets(sentence, MAX_WORD_SIZE, stdin);
    // Remove the newline character from the end of the input
    sentence[strcspn(sentence, "\n")] = '\0';
    // Translate the sentence and print the result
    translate_word(sentence, translation);
    printf("Translation: %s\n", translation);
    return 0;
}