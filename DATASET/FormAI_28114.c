//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 80
#define MAX_ART_SIZE 1000

void generateArt(char* text);

int main() {
    char inputText[MAX_LINE_LENGTH];
    printf("Enter text to convert to ASCII art:\n");
    fgets(inputText, sizeof(inputText), stdin);
    generateArt(inputText);
    return 0;
}

void generateArt(char* text) {
    char art[MAX_ART_SIZE] = "";
    char* ASCII_art[8][8];  // Array to store ASCII art characters

    // Initialize ASCII art array with blank spaces
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ASCII_art[i][j] = "   ";
        }
    }

    // Map each character in text to ASCII art characters
    for (int i = 0; i < strlen(text); i++) {
        int asciiVal = (int)text[i];
        int row = (asciiVal / 32) % 8;
        int col = asciiVal % 32;

        // Adjust for special characters
        if (col >= 0 && col <= 7) {
            col += 32;
        } else if (col >= 8 && col <= 15) {
            col -= 8;
        } else if (col >= 16 && col <= 23) {
            col += 16;
        } else if (col >= 24 && col <= 31) {
            col -= 24;
        }

        // Get ASCII art character for given row and column
        ASCII_art[row][col] = "###";
    }

    // Build ASCII art string from array
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            strcat(art, ASCII_art[i][j]);  // Append ASCII art character to string
        }
        strcat(art, "\n");  // Add newline character after each row
    }

    printf("%s", art);
}