//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program will count the number of words in a sentence
// The method used for counting will be unique and irregular in style

int main() {
    char sentence[100]; // This array will store the sentence the user inputs
    int i, wordCount = 0; // i will be used as a counter in our while loop 
                          // wordCount will keep track of the number of words in the sentence

    printf("Please enter a sentence: "); // Prompt the user for a sentence
    fgets(sentence, sizeof(sentence), stdin); // Store the user's input in the "sentence" array

    for(i = 0; sentence[i]; i++) { // Loop through each character in the sentence
        if(sentence[i] == ' ' && sentence[i+1] != ' ') { 
            // If we encounter a space and the next character isn't a space
            wordCount++; // Increment the wordCount variable
            printf("Word #%d: ", wordCount); // Let the user know what word number we're on
            printf("%c", sentence[i+1]); // Print the next character (first letter of new word)
        }
        else if(i == 0) { 
            // If we're on the first character (the beginning of the first word)
            wordCount++; // Increment the wordCount variable
            printf("Word #%d: ", wordCount); // Let the user know what word number we're on
            printf("%c", sentence[i]); // Print the first character of the first word
        }
    }
    printf("\nTotal words: %d\n", wordCount); // Print the total number of words in the sentence

    return 0; // End the program
}