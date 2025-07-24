//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50 // Maximum length of a word
#define MAX_MISSPELLED_WORDS 1000 // Maximum number of misspelled words to store

// Define a struct to store misspelled words and their suggestions
typedef struct {
    char word[MAX_WORD_LEN+1];
    char suggestions[10][MAX_WORD_LEN+1];
    int num_suggestions;
} misspelled_word;

// Function to load the dictionary file and store the words in a hash table
int load_dictionary(const char* dictionary_file, char* hash_table[]) {
    FILE* fp;
    char word[MAX_WORD_LEN+1];
    int word_count = 0;
    
    fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to all lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // Add word to hash table
        int index = (word[0] - 'a') % 26;
        hash_table[index] = (char*) malloc((strlen(word)+1) * sizeof(char));
        strcpy(hash_table[index], word);
        word_count++;
    }
    
    fclose(fp);
    
    return word_count;
}

// Function to check if a word is spelled correctly
int check_word(const char* word, char* hash_table[]) {
    char lower_word[MAX_WORD_LEN+1];
    
    // Convert word to all lowercase
    strcpy(lower_word, word);
    for (int i = 0; lower_word[i]; i++) {
        lower_word[i] = tolower(lower_word[i]);
    }
    
    // Look up word in hash table
    int index = (lower_word[0] - 'a') % 26;
    if (hash_table[index] == NULL) {
        return 0;
    }
    if (strcmp(hash_table[index], lower_word) == 0) {
        return 1;
    }
    
    // Word not found, suggest alternatives
    char suggestions[10][MAX_WORD_LEN+1];
    int num_suggestions = 0;
    
    // Check for one-letter insertion errors
    for (int i = 0; lower_word[i]; i++) {
        char word_copy[MAX_WORD_LEN+1];
        strcpy(word_copy, lower_word);
        memmove(&word_copy[i+1], &word_copy[i], strlen(word_copy)-i);
        for (char c = 'a'; c <= 'z'; c++) {
            word_copy[i] = c;
            int suggestion_index = (word_copy[0] - 'a') % 26;
            if (hash_table[suggestion_index] != NULL && strcmp(hash_table[suggestion_index], word_copy) == 0) {
                strcpy(suggestions[num_suggestions++], word_copy);
                if (num_suggestions == 10) {
                    break;
                }
            }
        }
        if (num_suggestions == 10) {
            break;
        }
    }
    
    // Check for one-letter deletion errors
    for (int i = 0; lower_word[i]; i++) {
        char word_copy[MAX_WORD_LEN+1];
        strcpy(word_copy, lower_word);
        memmove(&word_copy[i], &word_copy[i+1], strlen(word_copy)-i);
        int suggestion_index = (word_copy[0] - 'a') % 26;
        if (hash_table[suggestion_index] != NULL && strcmp(hash_table[suggestion_index], word_copy) == 0) {
            strcpy(suggestions[num_suggestions++], word_copy);
            if (num_suggestions == 10) {
                break;
            }
        }
    }
    
    // Check for one-letter substitution errors
    for (int i = 0; lower_word[i]; i++) {
        char word_copy[MAX_WORD_LEN+1];
        strcpy(word_copy, lower_word);
        for (char c = 'a'; c <= 'z'; c++) {
            if (c != lower_word[i]) {
                word_copy[i] = c;
                int suggestion_index = (word_copy[0] - 'a') % 26;
                if (hash_table[suggestion_index] != NULL && strcmp(hash_table[suggestion_index], word_copy) == 0) {
                    strcpy(suggestions[num_suggestions++], word_copy);
                    if (num_suggestions == 10) {
                        break;
                    }
                }
            }
        }
        if (num_suggestions == 10) {
            break;
        }
    }
    
    // Create misspelled_word struct and add to global array of misspelled words
    misspelled_word misspelled;
    strcpy(misspelled.word, word);
    misspelled.num_suggestions = num_suggestions;
    for (int i = 0; i < num_suggestions; i++) {
        strcpy(misspelled.suggestions[i], suggestions[i]);
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: spell_check <dictionary_file> <input_file>\n");
        exit(EXIT_FAILURE);
    }
    
    char* hash_table[26]; // Create hash table for storing dictionary words
    memset(hash_table, 0, sizeof(hash_table)); // Initialize all elements to NULL
    
    int num_words = load_dictionary(argv[1], hash_table); // Load dictionary and store words in hash table
    
    FILE* fp;
    char word[MAX_WORD_LEN+1];
    misspelled_word misspelled_words[MAX_MISSPELLED_WORDS];
    int num_misspelled = 0;
    
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }
    
    // Read each word from input file and check if it is spelled correctly
    while (fscanf(fp, "%s", word) != EOF && num_misspelled < MAX_MISSPELLED_WORDS) {
        if (!check_word(word, hash_table)) { // Word is misspelled
            // Do nothing, check_word function adds misspelled word and suggestions to global array
        }
    }
    
    fclose(fp);
    
    // Print misspelled words and their suggestions
    for (int i = 0; i < num_misspelled; i++) {
        printf("Misspelled word: %s\n", misspelled_words[i].word);
        printf("Suggestions:\n");
        for (int j = 0; j < misspelled_words[i].num_suggestions; j++) {
            printf("%s\n", misspelled_words[i].suggestions[j]);
        }
        printf("\n");
    }
    
    // Free memory used by hash table
    for (int i = 0; i < 26; i++) {
        free(hash_table[i]);
    }
    
    return 0;
}