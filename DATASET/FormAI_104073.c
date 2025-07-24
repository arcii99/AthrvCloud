//FormAI DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <string.h>

int main(void) {
    char inputString[100];                    // Initialize variable to store user input
    int wordCount = 0;                        // Initialize word count to zero
    
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);   // Get user input from keyboard
        
    for (int i = 0; i < strlen(inputString); i++) {    // Loop through each character in string
        if (inputString[i] == ' ' || inputString[i] == '\n' || inputString[i] == '\r') {
            wordCount++;                             // Count a word when a space, newline, or return character is found
        }
    }
    
    printf("Total words in string: %d\n", wordCount);  // Output the total word count
    
    return 0;
}