//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_MORSE_LENGTH 200

// Define Morse Code symbols and their corresponding Alpha-numeric characters
const char* MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
    "---..", "----."
};

const char* ALPHA_NUMERIC[] = {
    // Characters A-Z and digits 0-9
   "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
};

// Function to convert an Alpha-numeric character to Morse Code string
char* alpha_numeric_to_morse(char alpha_char) {
    int i;

    // Lookup index of the input Alpha-numeric character
    for (i = 0; i < sizeof(ALPHA_NUMERIC[0]); ++i) {
        if (alpha_char == ALPHA_NUMERIC[0][i]) {
            // Return the Morse Code symbol at the same index
            return MORSE_CODE[i];
        }
    }

    // Otherwise return NULL as the character does not exist in the lookup table
    return NULL;
}

// Function to convert an input string to Morse Code
void text_to_morse(char* input_text, char* output_morse) {
    int i;
    int j = 0;

    // Iterate over each character in the input string
    for (i = 0; i < strlen(input_text); ++i) {
        char* morse_symbol = alpha_numeric_to_morse(input_text[i]);

        // If the current character exists in the lookup table, append its Morse code symbol to the output string
        if (morse_symbol != NULL) {
            int k;

            for (k = 0; k < strlen(morse_symbol); ++k) {
                output_morse[j++] = morse_symbol[k];
            }

            output_morse[j++] = ' '; // Separate morse code for each character with a space
        }
    }

    output_morse[j] = '\0'; // Null terminate the output string
}

int main() {
    char input_text[MAX_INPUT_LENGTH];
    char output_morse[MAX_MORSE_LENGTH];

    // Read user input
    printf("Enter text to be converted to Morse Code: ");
    fgets(input_text, MAX_INPUT_LENGTH, stdin);

    // Convert input to Morse Code
    text_to_morse(input_text, output_morse);

    // Print the output
    printf("Morse Code for the entered text: %s\n", output_morse);

    return 0;
}