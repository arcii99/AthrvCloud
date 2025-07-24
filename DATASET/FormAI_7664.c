//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int wordCount = 0, charCount = 0;
    
    // Prompts the user to enter a sentence and read it into the 'sentence' variable
    printf("Enter a sentence:\n");
    fgets(sentence, 1000, stdin); 
    
    // Gets the length of the input sentence
    int sentenceLength = strlen(sentence); 
    
    // Loops through each character in the sentence and determines if it's the end of a word
    for (int i = 0; i < sentenceLength; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') { // Checks if the current character is a space, newline, or tab
            wordCount++; // Increments the word count since the space indicates the end of a word
        } else {
            charCount++; // Increments the character count since this character is not a space, newline, or tab
        }
    }
    
    // If there are still characters not counted as words at the end of the sentence, increment the word count
    if (charCount > 0) {
        wordCount++;
    }
    
    // Prints out the word count
    printf("Word count: %d\n", wordCount);
    
    return 0;
}