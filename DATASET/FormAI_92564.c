//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
/*
 * Text to ASCII Art Generator
 * Written by: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the dimensions of the ASCII art output
#define ASCII_ART_WIDTH 80
#define ASCII_ART_HEIGHT 20

// Define the number of characters to skip each line
#define SKIP_CHARS_PER_LINE 4

// Define the maximum length of a user input string
#define MAX_INPUT_LENGTH 256

// Define the ASCII characters used to generate the art
#define ART_CHARS ".+-*=%#@"

// Define the total number of ASCII characters used
#define NUM_ART_CHARS strlen(ART_CHARS)

// Define the ASCII art buffer
char asciiArt[ASCII_ART_HEIGHT][ASCII_ART_WIDTH];

// Function to clear the ASCII art buffer
void clearAsciiArt() {
    for (int i = 0; i < ASCII_ART_HEIGHT; i++) {
        for (int j = 0; j < ASCII_ART_WIDTH; j++) {
            asciiArt[i][j] = ' ';
        }
    }
}

// Function to print the ASCII art buffer
void printAsciiArt() {
    for (int i = 0; i < ASCII_ART_HEIGHT; i++) {
        printf("%s\n", asciiArt[i]);
    }
}

// Main function that generates the ASCII art
int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text to convert to ASCII art:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove the trailing newline character from the input string
    input[strcspn(input, "\n")] = 0;

    int len = strlen(input);
    int charIndex = 0;
    int skipChars = 0;
    int numArtChars = 0;
    int artCharIndex = 0;

    clearAsciiArt();

    // Fill the ASCII art buffer with the input text
    for (int i = 0; i < ASCII_ART_HEIGHT; i++) {
        for (int j = 0; j < ASCII_ART_WIDTH; j++) {
            if (skipChars > 0) {
                skipChars--;
                continue;
            }

            if (charIndex >= len) {
                numArtChars = ASCII_ART_WIDTH - j;
                break;
            }

            char currentChar = input[charIndex];
            artCharIndex = currentChar % NUM_ART_CHARS;

            asciiArt[i][j] = ART_CHARS[artCharIndex];

            charIndex++;
            skipChars = SKIP_CHARS_PER_LINE - 1;
        }

        if (numArtChars > 0) {
            for (int j = 0; j < numArtChars; j++) {
                asciiArt[i][ASCII_ART_WIDTH - numArtChars + j] = ART_CHARS[artCharIndex];
            }
            break;
        }
    }

    // Print the ASCII art
    printAsciiArt();

    return 0;
}