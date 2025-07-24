//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50   // Maximum length of a word
#define MAX_WORDS 10000   // Maximum number of words that can be stored

int main() {
    int words_count = 0;  // Store the count of total words processed
    char *words[MAX_WORDS]; // An array of pointers to store words
    int freq[MAX_WORDS] = {0}; // An array to store frequency of each word
    char line[200];  // Buffer to read input line
    char *word;      // Pointer to hold each word from input line
    
    // Read input from user
    printf("Enter text (Press Ctrl+Z and then Enter to end):\n");
    
    // Read input line by line until EOF is encountered
    while(fgets(line, sizeof(line), stdin) != NULL) {
        // Split line into words
        word = strtok(line, " \n");
        while(word != NULL) {
            // Convert word to lowercase for better counting
            for(int i = 0; word[i]; i++){
                word[i] = tolower(word[i]);
            }
            
            // Check if word already exists in array
            int found = 0;
            for(int i = 0; i < words_count; i++){
                if(strcmp(word, words[i]) == 0){
                    freq[i] += 1;  // Increment the frequency of this word
                    found = 1;
                    break;
                }
            }
            
            // If word does not exist in array, add it to the end and set freq = 1
            if(!found){
                words[words_count] = (char*) malloc(MAX_WORD_LEN * sizeof(char));
                strcpy(words[words_count], word);
                freq[words_count] += 1;
                words_count++;
            }
            
            // Get next word
            word = strtok(NULL, " \n");
        }
    }
    
    // Print the final frequency count for each word
    printf("\nWORD FREQUENCY:\n-------------\n");
    for(int i = 0; i < words_count; i++){
        printf("%s: %d\n", words[i], freq[i]);
        free(words[i]);  // Deallocate memory for each word
    }
    
    return 0;
}