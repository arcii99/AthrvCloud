//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to convert a character to Morse code
void charToMorse(char c) {
    // Define the Morse code for each character
    char *morseCodes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", 
        "--.", "....", "..", ".---", "-.-", ".-..", 
        "--", "-.", "---", ".--.", "--.-", ".-.", 
        "...", "-", "..-", "...-", ".--", "-..-", 
        "-.--", "--.."
    };
    
    // Get the index of the character in the alphabet
    int index = (int) (c - 'a');

    // If the character is not in the alphabet, print a space
    if (index < 0 || index > 25) {
        printf(" ");
        return;
    }

    // Print the Morse code for the character
    printf("%s ", morseCodes[index]);
}

int main() {
    // Get the text to convert to Morse code
    char text[100];
    printf("Enter text to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin);

    // Strip the newline character from the end of the input
    text[strcspn(text, "\n")] = 0;

    // Convert each character to Morse code
    for (int i = 0; i < strlen(text); i++) {
        charToMorse(text[i]);
    }

    printf("\n");

    return 0;
}