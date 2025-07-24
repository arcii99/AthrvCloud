//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
/*
 * AUTHOR: Chatbot
 * DATE: 2022
 * DESCRIPTION: This program checks if the words in a sentence are spelled correctly or not. 
 * It uses a dictionary of words to check against and outputs any misspelled words.
 * This program is inspired by Claude Shannon's work in information theory.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICT_WORDS 1000
#define MAX_SENTENCE_LENGTH 1000

// Define dictionary of words
char dict[MAX_DICT_WORDS][MAX_WORD_LENGTH];

// Initialize function to load dictionary of words
void loadDictionary(const char* filename);

// Initialize function to check if a word is in the dictionary
int checkDictionary(char* word);

int main() {
    // Load dictionary of words
    loadDictionary("dictionary.txt");

    // Get input sentence from user
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    
    // Check each word in the sentence
    char* word = strtok(sentence, " \n");
    while (word != NULL) {
        // Remove any non-alphabetic characters from word
        int i = 0, j = 0;
        while (word[i]) {
            if (isalpha(word[i])) {
                word[j++] = tolower(word[i]);
            }
            i++;
        }
        word[j] = '\0';

        // Check if word is in the dictionary
        if (!checkDictionary(word)) {
            printf("Misspelled word: %s\n", word);
        }

        // Get next word
        word = strtok(NULL, " \n");
    }

    return 0;
}

void loadDictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(word, MAX_WORD_LENGTH, file)) {
        // Remove newline character from word
        word[strcspn(word, "\n")] = '\0';
        
        // Add word to dictionary
        strcpy(dict[i++], word);
    }

    fclose(file);
    printf("Dictionary loaded with %d words\n", i);
}

int checkDictionary(char* word) {
    int i = 0;
    while (dict[i][0] != '\0') {
        if (strcmp(dict[i], word) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}