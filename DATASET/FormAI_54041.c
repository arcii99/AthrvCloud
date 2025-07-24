//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char inputBuffer[100]; // User input buffer for the string
    char wordBuffer[100]; // Buffer to hold each word as we isolate them
    int wordCount = 0; // A count of the number of words found
    int i, j, isWord, wordLength;

    printf("Please enter a string of text to count the words: ");
    fgets(inputBuffer, 100, stdin); // Get input from user

    for(i=0; i<strlen(inputBuffer); i++) {

        isWord = 0;
        wordLength = 0;

        // Check if the current character is part of a word
        if(isalnum(inputBuffer[i])) {
            isWord = 1; // Set flag indicating that we are at the beginning of a word
            wordBuffer[wordLength++] = tolower(inputBuffer[i]); // Add the character to the word buffer array
        }

        // If the current character is not part of a word, but the previous character was, then we have found a complete word.
        if(isWord == 0 && i > 0 && isalnum(inputBuffer[i-1])) {
            wordBuffer[wordLength] = '\0'; // Make sure to terminate the string we just built
            wordCount++; // Increment the word count
            printf("Found word #%d: %s\n", wordCount, wordBuffer); // Print the word we just found
        }
    }

    // Print out the final word count
    printf("\n\nTotal number of words found: %d\n", wordCount);
    return 0;
}