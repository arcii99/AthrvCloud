//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    char textInput[100];
    char morseCode[100][10]; // Maximum of 10 dots/dashes per letter
    int i, j;
    
    // Define morse code lookup table
    char *morseTable[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A to I
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J to R
                            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // S to Z
    
    // Prompt user for input
    printf("Enter text to convert to Morse code:\n");
    fgets(textInput, 100, stdin);
    textInput[strcspn(textInput, "\n")] = 0; // Remove trailing newline character
    
    // Loop through each character in input string
    for (i = 0; i < strlen(textInput); i++) {
        int asciiValue = (int)textInput[i]; // Convert character to ASCII value
        
        // Check if character is a letter
        if (asciiValue >= 65 && asciiValue <= 90) { // Upper case
            strcpy(morseCode[i], morseTable[asciiValue - 65]);
        }
        else if (asciiValue >= 97 && asciiValue <= 122) { // Lower case
            strcpy(morseCode[i], morseTable[asciiValue - 97]);
        }
        else { // Non-letter character
            strcpy(morseCode[i], ""); // Store empty string
        }
    }
    
    // Print Morse code output
    printf("\nMorse Code Output:\n");
    for (i = 0; i < strlen(textInput); i++) {
        if (strcmp(morseCode[i], "") != 0) { // Print only if not empty string
            for (j = 0; j < strlen(morseCode[i]); j++) {
                printf("%c ", morseCode[i][j]); // Print dot/dash with space separator
            }
            printf("/ "); // Print slash between letters
        }
    }
    printf("\n");
    
    return 0; // Exit program
}