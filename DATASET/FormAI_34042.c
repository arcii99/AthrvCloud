//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Function to convert a letter to its Morse code equivalent
char* letterToMorse(char letter) {
    // Array of Morse code equivalents for each letter
    static char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    // Convert the letter to its ASCII value, and subtract 97
    // to get the corresponding Morse code index (a = 0, b = 1, etc.)
    int index = (int) letter - 97;
    
    // Return the Morse code equivalent for the letter
    return morseCode[index];
}

int main() {
    char input[100]; // Array to hold user input
    printf("Enter a string to convert to Morse code: ");
    scanf("%[^\n]", input); // Read input until newline character
    
    // Loop through each character in the string
    for (int i=0; i<strlen(input); i++) {
        // If the character is a space, print a newline character
        if (input[i] == ' ') {
            printf("\n");
        }
        // Otherwise, print the Morse code equivalent for the character
        else {
            printf("%s ", letterToMorse(input[i]));
        }
    }
    return 0;
}