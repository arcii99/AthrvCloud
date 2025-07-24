//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
// Romeo and Juliet C Word Frequency Counter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS_TO_COUNT 1000

// Function to remove punctuation from string
void removePunctuation(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        if(ispunct(str[i])) {    
            for(int j=i; j<len; j++) {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
}

// Function to convert string to lowercase
void toLowerCase(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        char c = tolower(str[i]);
        str[i] = c;
    }
}

int main() {
    // Declare variables
    char filename[50];
    char* words[MAX_WORDS_TO_COUNT];
    int frequency[MAX_WORDS_TO_COUNT] = {0};
    int numWords = 0;
    char word[MAX_WORD_LENGTH];
    
    // Ask user for file name
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    
    // Open file for reading
    FILE* file = fopen(filename, "r");
    
    // If file cannot be opened, print error message and exit
    if(file == NULL) {
        printf("Error opening file!");
        return 1;
    }
    
    // Read from file word by word
    while(fscanf(file, "%s", word) != EOF) {
        // Remove punctuation and convert to lowercase
        removePunctuation(word);
        toLowerCase(word);
        // Check if word is already in array of words
        int found = 0;
        for(int i=0; i<numWords; i++) {
            if(strcmp(word, words[i]) == 0) {
                frequency[i]++;
                found = 1;
                break;
            }
        }
        // If word is not already in array of words, add it
        if(!found) {
            words[numWords] = malloc(strlen(word)+1);
            strcpy(words[numWords], word);
            frequency[numWords] = 1;
            numWords++;
        }
    }
    
    // Close file
    fclose(file);
    
    // Print results
    printf("%-20s %-20s\n", "Word", "Frequency");
    printf("---------------------------------\n");
    for(int i=0; i<numWords; i++) {
        printf("%-20s %-20d\n", words[i], frequency[i]);
    }
    
    // Free memory
    for(int i=0; i<numWords; i++) {
        free(words[i]);
    }
    
    // Return success
    return 0;
}