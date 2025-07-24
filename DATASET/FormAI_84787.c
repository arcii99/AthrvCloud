//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum input string length
#define MAX_LENGTH 50

int main() {
    // Ask user to enter a sentence
    char sentence[MAX_LENGTH];
    printf("Please enter a sentence (up to %d characters): ", MAX_LENGTH);
    fgets(sentence, MAX_LENGTH, stdin);
    
    // Remove newline character from sentence
    int sentence_length = strlen(sentence);
    if (sentence[sentence_length - 1] == '\n') {
        sentence[sentence_length - 1] = '\0';
    }
    
    // Convert sentence to uppercase
    int i;
    for (i = 0; i < sentence_length; i++) {
        sentence[i] = toupper(sentence[i]);
    }
    
    // Identify longest word in sentence
    char* longest_word = strtok(sentence, " ");
    while (longest_word != NULL) {
        char* next_word = strtok(NULL, " ");
        if (next_word != NULL && strlen(next_word) > strlen(longest_word)) {
            longest_word = next_word;
        }
        longest_word = strtok(NULL, " ");
    }
    
    // Print sentence in reverse order
    printf("Reversed sentence: ");
    for (i = sentence_length - 1; i >= 0; i--) {
        printf("%c", sentence[i]);
    }
    printf("\n");
    
    // Print longest word in sentence
    printf("Longest word: %s\n", longest_word);
    
    return 0;
}