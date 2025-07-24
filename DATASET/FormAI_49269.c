//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 8
#define COLUMNS 80
#define MAX_LENGTH 100

// ASCII art character array
char art[ROWS][COLUMNS];

// Function to initialize the art array
void initializeArtArray() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            art[i][j] = ' ';
        }
    }
}

// Function to print the ASCII art
void printArt() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

// Function to convert input string to ASCII art
void convertToArt(char input[]) {
    int i, j, k, length, position;

    // Determine length of input string
    length = strlen(input);

    // Calculate position of string within art array
    position = (COLUMNS - length) / 2;

    // Loop through each row of art array
    for (i = 0; i < ROWS; i++) {
        // Check if we are in the middle row
        if (i == ROWS / 2) {
            // Loop through the columns for our string
            for (j = position; j < position + length; j++) {
                // Set the character in the art array to the corresponding character in our input string
                art[i][j] = input[j - position];
            }
        } else {
            // Determine symbol to use for this row
            char symbol;
            if (i < ROWS / 2) {
                symbol = '\\';
            } else {
                symbol = '/';
            }

            // Determine how many spaces we need to add before the symbol
            int spaces = (COLUMNS - (2 * i + length)) / 2;

            // Loop through the columns for this row
            for (k = 0; k < COLUMNS; k++) {
                // Check if we need to add spaces or the symbol
                if (k < spaces || k >= COLUMNS - spaces) {
                    art[i][k] = ' ';
                } else {
                    art[i][k] = symbol;
                }
            }
        }
    }
}

int main() {
    // Initialize the ASCII art array
    initializeArtArray();

    // Read in user input
    char input[MAX_LENGTH];
    printf("Enter text to convert to ASCII art:\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Convert input to ASCII art
    convertToArt(input);

    // Print the ASCII art
    printArt();

    return 0;
}