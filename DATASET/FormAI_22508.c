//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: statistical
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char *input) {
    // Morse code lookup table
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    // Loop through each character in the input string
    for (int i=0; i<strlen(input); i++) {
        // If character is a space, print a new line
        if (input[i] == ' ') {
            printf("\n");
        }
        // If character is not a space, convert to Morse code and print
        else {
            printf("%s ", morseCode[(int)input[i]-97]);
        }
    }
}

int main() {
    // Prompt user for input
    char input[100];
    printf("Enter text to convert to Morse code: ");
    fgets(input, 100, stdin);
    // Remove newline character at end of input string
    input[strcspn(input, "\n")] = 0;
    // Convert input to lowercase
    for (int i=0; i<strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
    // Call textToMorse function to convert input to Morse code
    textToMorse(input);
    return 0;
}