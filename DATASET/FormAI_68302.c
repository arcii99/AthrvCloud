//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter your text below:\n");
    
    char text[1000];
    fgets(text, 1000, stdin); // read the input text
    
    int wordCount = 0;
    int charCount = 0;
    int index = 0;
    int isLastCharWhite = 1; // flag to check for whitespace
    
    while (text[index] != '\0') {
        char currChar = text[index];
        if (isalpha(currChar)) { // check if it's a letter
            charCount++;
            if (isLastCharWhite) {
                wordCount++;
            }
            isLastCharWhite = 0;
        } else if (isspace(currChar)) { // check for whitespace
            isLastCharWhite = 1;
        }
        index++;
    }
    
    // print the word and character counts
    printf("Word Count: %d\nCharacter Count: %d\n", wordCount, charCount);
    
    return 0;
}