//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_WORDS 1000
#define MAX_LENGTH 30

int main() {
    
    // Declare variables
    char raw_input[MAX_WORDS];
    char *token;
    char word_list[MAX_WORDS][MAX_LENGTH] = {0};
    int freq[MAX_WORDS] = {0};
    int count = 0;
    
    // Get input from user
    printf("Enter a string of text: ");
    fgets(raw_input, MAX_WORDS, stdin);
    
    // Get the first word
    token = strtok(raw_input, " \n");
    
    // Tokenize the input and count the occurences of each word
    while (token != NULL && count < MAX_WORDS) {
        // Make all letters lowercase for consistency
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        
        // Check if the word is already in the list
        int word_index = -1;
        for (int i = 0; i < count; i++) {
            if (strcmp(token, word_list[i]) == 0) {
                word_index = i;
                break;
            }
        }
        
        // If the word is not in the list, add it and set frequency to 1
        if (word_index == -1) {
            strcpy(word_list[count], token);
            freq[count] = 1;
            count++;
        }
        // If the word is in the list, increment its frequency
        else {
            freq[word_index]++;
        }
        
        // Get the next word
        token = strtok(NULL, " \n");
    }
    
    // Print the frequency of each word
    printf("%-15s%s\n", "Word", "Frequency");
    printf("-----------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s%d\n", word_list[i], freq[i]);
    }
    
    return 0;
}