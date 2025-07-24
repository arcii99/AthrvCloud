//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum word length supported by the tool

int main() {
    char word[MAX_WORD_LENGTH+1]; // Declare a char array to store the word read from the input stream
    int ch, wordCount = 0, charCount = 0; // Declare and initialize variables to track word count and character count
    // Loop through all characters in the input stream until EOF is encountered
    while ((ch = getchar()) != EOF) {
        if (isspace(ch) || ispunct(ch)) { // Check if the character is a space or punctuation mark
            if (charCount > 0) { // If there was a word before the current character, increment word count
                wordCount++;
                printf("Word %d: %s\n", wordCount, word); // Print the word that was just read
                charCount = 0; // Reset character count for the next word
            }
        } 
        else { // If the character is not a space or punctuation mark, add it to the current word
            if (charCount < MAX_WORD_LENGTH) { // Check if the word length limit has been reached
                word[charCount] = tolower(ch); // Convert character to lowercase and add to the word
                charCount++; // Increment character count for the current word
            }
        }
    }
    // Print word count and character count for the last word (if there was one)
    if (charCount > 0) {
        wordCount++;
        printf("Word %d: %s\n", wordCount, word);
    }
    printf("Total number of words: %d\n", wordCount);
    return 0; // Exit the program
}