//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the ASCII art
#define WIDTH   80
#define HEIGHT  20

// Define the maximum length of the input text
#define MAX_TEXT_LENGTH  100

// Define the ASCII art characters
char ASCII_CHARS[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Define the number of ASCII characters
int NUM_ASCII_CHARS = sizeof(ASCII_CHARS) / sizeof(char);

// Define a helper function to convert a character to an ASCII art character
char char2Ascii(char c) {
    int index = c % NUM_ASCII_CHARS; // Use modulo to wrap around the array
    return ASCII_CHARS[index];
}

// Define a helper function to print the ASCII art
void printAsciiArt(char asciiArt[][WIDTH]) {
    printf("\n"); // Ensure there's a newline before the ASCII art
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s\n", asciiArt[i]); // Print each row of the ASCII art
    }
    printf("\n"); // Ensure there's a newline after the ASCII art
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter some text (up to %d characters):\n", MAX_TEXT_LENGTH);
    fgets(text, MAX_TEXT_LENGTH, stdin); // Read the input text from the user
    
    int asciiArtWidth = strlen(text) * 6; // Each character is represented by a 5x5 block plus a space
    char asciiArt[HEIGHT][asciiArtWidth]; // Define the ASCII art array
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < asciiArtWidth; j++) {
            asciiArt[i][j] = ' '; // Initialize the ASCII art with spaces
        }
    }
    
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        int asciiArtStart = i * 6; // Each character is represented by a 5x5 block plus a space
        for (int j = 0; j < 5; j++) { // Each row of the 5x5 block
            for (int k = 0; k < 5; k++) { // Each column of the 5x5 block
                char asciiChar = char2Ascii(c); // Convert the character to an ASCII art character
                asciiArt[j+5][asciiArtStart+k] = asciiChar; // Place the ASCII art character at the appropriate position
            }
        }
        asciiArt[2][asciiArtStart+2] = c; // Place the actual character in the center position
    }
    
    printAsciiArt(asciiArt); // Print the final ASCII art
    
    return 0;
}