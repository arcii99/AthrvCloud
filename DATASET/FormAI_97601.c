//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about a word
typedef struct {
    char* word;
    int frequency;
} Word;

// Function to split a string into an array of words
int split_string(char* string, Word** words_ptr) {
    Word* words;
    int count = 0;
    
    // Loop through the string to count words
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            count++;
        }
    }
    
    // Allocate memory for the array of words
    words = (Word*) malloc((count+1) * sizeof(Word));
    count = 0;
    
    // Split the string into words and store in the array
    char* token = strtok(string, " ");
    while (token != NULL) {
        words[count].word = token;
        words[count].frequency = 1;
        count++;
        token = strtok(NULL, " ");
    }
    
    // Update the frequency of each word in the array
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].frequency++;
                words[j].frequency = -1;
            }
        }
    }
    
    // Remove duplicate words from the array
    Word* new_words = (Word*) malloc(count * sizeof(Word));
    int new_count = 0;
    for (int i = 0; i < count; i++) {
        if (words[i].frequency > 0) {
            new_words[new_count] = words[i];
            new_count++;
        }
    }
    
    // Update the pointer to the new array of words and return the number of unique words
    *words_ptr = new_words;
    return new_count;
}

int main() {
    char* string = "the quick brown fox jumps over the lazy dog";
    Word* words;
    int count = split_string(string, &words);
    
    // Print the unique words and their frequencies
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    
    // Free memory
    free(words);
    
    return 0;
}