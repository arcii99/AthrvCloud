//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the Morse Code lookup table
char *morseCodeTable[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
                           ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
                           "...-", ".--", "-..-", "-.--", "--.." };

// Define the corresponding alphabetical character table
char *alphabetTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to convert input text to Morse code and print the output
void convertToMorseCode(char *input) {
    int i,j,k;
    bool space = false;
    for(i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {   // If there is a space, print a blank line 
            printf("\n");
            space = true;
        } else {
            // Search for the indexed letter of the input string within the alphabet table to get its Morse code symbol
            for(j = 0; j < strlen(alphabetTable); j++) {
                if(toupper(input[i]) == alphabetTable[j]) {
                    space = false;
                    for(k = 0; k < strlen(morseCodeTable[j]); k++) {
                        // Print each Morse code symbol with a space in between
                        printf("%c ", morseCodeTable[j][k]);
                    }
                    printf("  "); // Add 2 spaces between each letter
                    break; 
                }
            }
        }
    }
    if(space == true) { // If the last character is a space, print another blank line
        printf("\n");
    }
}

// Driver function to test the program
int main() {
    char input[100];
    printf("Enter a string to convert to Morse Code: ");
    fgets(input, 100, stdin);
    printf("\nMorse Code Output:\n");
    convertToMorseCode(input);
    return 0;
}