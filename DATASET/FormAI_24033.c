//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: systematic
#include <stdio.h>
#include <string.h>

void convertToMorse(char text[]);
// Function declaration for converting text to Morse code

int main() {
    char input[100];
    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin); // Take user input
    
    // Remove newline character from input, if present
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    convertToMorse(input); // Call function to convert text to Morse code
    
    return 0;
}

void convertToMorse(char text[]) {
    char morse[36][10] = {"-----", ".----", "..---", "...--", "....-", ".....",
                          "-....", "--...", "---..", "----.", ".-", "-...",
                          "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                          "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                          "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
    char morseText[100] = ""; // Initialize Morse code text to empty string
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            strcat(morseText, "/ "); // Add slash separator for spaces
        } else {
            strcat(morseText, morse[toupper(text[i]) - 48]); // Convert each letter to Morse code
            strcat(morseText, " "); // Add space separator between letters
        }
    }
    printf("Morse code: %s", morseText); // Print converted Morse code text
}