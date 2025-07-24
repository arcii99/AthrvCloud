//FormAI DATASET v1.0 Category: Spell checking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORDS 1024

// Function to convert all characters in a string to lowercase
void to_lower(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char line[MAX_LINE_LENGTH]; // String to hold a line of text
    char* words[MAX_WORDS]; // Array to hold individual words in the line
    int word_count = 0; // Counter for the number of words in the line
    
    // Read in a line of text from stdin
    printf("Enter a line of text:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);
    
    // Tokenize the line into individual words
    char* token = strtok(line, " \t\n");
    while(token != NULL) {
        // Append word to array
        words[word_count++] = token;
        
        // Get next word
        token = strtok(NULL, " \t\n");
    }
    
    // Check spelling of each word
    for(int i = 0; i < word_count; i++) {
        char* word = words[i];
        to_lower(word); // Convert word to lowercase for case-insensitivity
        
        // Check for misspelling
        if(strcmp(word, "hello") != 0) {
            printf("Did you mean 'hello' instead of '%s'?\n", words[i]);
        }
    }
    
    return EXIT_SUCCESS;
}