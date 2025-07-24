//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    printf("\n****************************************\n");
    printf("** Welcome to the Text to Morse Program **\n");
    printf("****************************************\n");

    // Set up the Morse code conversion table
    char* morseTable[52] = {
        ".-", "-...", "-.-.", "-..", ".", 
        "..-.", "--.", "....", "..", ".---", 
        "-.-", ".-..", "--", "-.", "---", 
        ".--.", "--.-", ".-.", "...", "-", 
        "..-", "...-", ".--", "-..-", "-.--", 
        "--..", 
        ".----", "..---", "...--", "....-", ".....", 
        "-....", "--...", "---..", "----.", "-----",
        ".-.-.-", "--..--", "..--..", ".----.", "-.-.--",
        "-....-", "..--.-", ".-..-.", "---...", "-.--.", 
        "-.--.-", ".-.-.", "-..-.", "--...-", ".-..."
    };

    char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?'!/()&:;=+-_\"$@";
    char text[1000];
    char output[1000];
    int i, j, k;

    // Get user input text
    printf("\nEnter your text: ");
    fgets(text, 1000, stdin);

    // Convert text to uppercase for easier processing
    for (i = 0; i < strlen(text); i++) {
        text[i] = toupper(text[i]);
    }

    // Convert each character to Morse code
    for (i = 0; i < strlen(text); i++) {

        // Find the index of the character in the alphabet string
        for (j = 0; j < strlen(alphabet); j++) {
            if (text[i] == alphabet[j]) {
                break;
            }
        }

        // Build the Morse code string
        if (text[i] == ' ') {
            strcpy(output + strlen(output), "   ");
        } else if (j == strlen(alphabet)) {
            // Character not found in alphabet string
            printf("\nError: Invalid character '%c' in text.\n", text[i]);
            return 1;
        } else {
            strcpy(output + strlen(output), morseTable[j]);
            strcpy(output + strlen(output), " ");
        }
    }

    // Print the Morse code string
    printf("\nMorse code: %s\n", output);

    return 0;
}