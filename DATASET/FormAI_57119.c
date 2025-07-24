//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

int main(int argc, char *argv[]) {
    char *filename, *token, *word;
    char delimiters[] = " \n\r\t.,;:\"?!()";
    char line[MAX_WORD_LENGTH * MAX_NUM_WORDS], lowercase[MAX_WORD_LENGTH];
    int i, word_count, total_words = 0;
    int word_lengths[MAX_NUM_WORDS], word_occurrences[MAX_NUM_WORDS];
    
    // Check if filename is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    filename = argv[1];
    
    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }
    
    // Read file line by line
    while (fgets(line, sizeof(line), file)) {
        // Tokenize line by delimiters
        token = strtok(line, delimiters);        
        while (token) {
            // Convert word to lowercase
            word_count = strlen(token);
            for (i = 0; i < word_count; i++) {
                lowercase[i] = tolower(token[i]);
            }
            lowercase[word_count] = '\0';
            word = strdup(lowercase);
            
            // Check if word has already been counted
            for (i = 0; i < total_words; i++) {
                if (strcmp(word, lowercase) == 0) {
                    word_occurrences[i]++;
                    break;
                }
            }
            
            // Add new word to array
            if (i == total_words) {
                word_lengths[i] = word_count;
                word_occurrences[i] = 1;
                if (++total_words >= MAX_NUM_WORDS) {
                    printf("Too many words (maximum: %d)\n", MAX_NUM_WORDS);
                    return 1;
                }
            }
            
            // Get next token
            token = strtok(NULL, delimiters);
        }
    }
    
    // Close file
    fclose(file);
    
    // Sort words by frequency (descending)
    int sorted_indices[MAX_NUM_WORDS];
    for (i = 0; i < total_words; i++) {
        sorted_indices[i] = i;
    }
    for (i = 0; i < total_words - 1; i++) {
        int j, max_index = i;
        for (j = i + 1; j < total_words; j++) {
            if (word_occurrences[sorted_indices[j]] > word_occurrences[sorted_indices[max_index]]) {
                max_index = j;
            }
        }
        int temp = sorted_indices[i];
        sorted_indices[i] = sorted_indices[max_index];
        sorted_indices[max_index] = temp;
    }
    
    // Print results
    printf("Total words: %d\n", total_words);
    printf("%-10s %-10s %-10s %s\n", "Length", "Frequency", "Percentage", "Word");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < total_words; i++) {
        double percentage = ((double) word_occurrences[sorted_indices[i]]) / total_words * 100;
        printf("%-10d %-10d %-10.2f %s\n", word_lengths[sorted_indices[i]], 
               word_occurrences[sorted_indices[i]], percentage, word);
    }
    
    return 0;
}