//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

// Global array of ASCII characters to represent the final image
char art[MAX_HEIGHT][MAX_WIDTH];

// Function to clear the art array
void clear_art() {
    memset(art, ' ', sizeof(char) * MAX_HEIGHT * MAX_WIDTH);
}

// Function to print the final ASCII art
void print_art() {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            putchar(art[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    // Clear the art array to start with a blank canvas
    clear_art();

    // Example text to convert to ASCII art
    char text[] = "Hello, world!";

    // Set some constants for the ASCII styles
    const char* HORIZONTAL = "-";
    const char* VERTICAL = "|";
    const char* CORNER = "+";

    // Loop through the characters in the text string
    int text_len = strlen(text);
    int xpos = (MAX_WIDTH - text_len) / 2; // Center the text horizontally
    int ypos = MAX_HEIGHT / 2; // Center the text vertically
    for (int i = 0; i < text_len; i++) {
        // Add the character to the art array
        art[ypos][xpos + i] = text[i];

        // Draw a box around the character
        art[ypos - 1][xpos + i] = HORIZONTAL[0];
        art[ypos + 1][xpos + i] = HORIZONTAL[0];
        art[ypos][xpos + i - 1] = VERTICAL[0];
        art[ypos][xpos + i + 1] = VERTICAL[0];
        art[ypos - 1][xpos + i - 1] = CORNER[0];
        art[ypos - 1][xpos + i + 1] = CORNER[0];
        art[ypos + 1][xpos + i - 1] = CORNER[0];
        art[ypos + 1][xpos + i + 1] = CORNER[0];
    }

    // Print the final ASCII art
    print_art();

    return 0;
}