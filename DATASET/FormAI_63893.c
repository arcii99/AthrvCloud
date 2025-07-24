//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 1000

const int asciiWidth = 80; // Width of the ASCII art
const int asciiHeight = 45; // Height of the ASCII art
const int charWidth = 6; // Width of each character in the ASCII art
const int charHeight = 10; // Height of each character in the ASCII art

// Function to return the ASCII representation of a given character
char** ascii(char c) {

    // Initialize 2D array of characters to represent the ASCII art of the character
    char** arr = (char**) malloc(charHeight * sizeof(char*));
    for(int i = 0; i < charHeight; i++) {
        arr[i] = (char*) malloc(charWidth * sizeof(char));
    }

    // ASCII art of a space
    if(c == ' ') {
        for(int i = 0; i < charHeight; i++) {
            for(int j = 0; j < charWidth; j++) {
                arr[i][j] = ' ';
            }
        }
    }

    // ASCII art of an exclamation mark
    else if(c == '!') {
        for(int i = 0; i < charHeight; i++) {
            for(int j = 0; j < charWidth; j++) {
                if(j == 2 && i < 5) {
                    arr[i][j] = '-';
                } else if(j == 3 && i < 5) {
                    arr[i][j] = '-';
                } else if(j == 2 && i > 5) {
                    arr[i][j] = '-';
                } else if(j == 3 && i > 5) {
                    arr[i][j] = '-';
                } else if(j == 1 && i == 6) {
                    arr[i][j] = '-';
                } else if(j == 4 && i == 6) {
                    arr[i][j] = '-';
                } else {
                    arr[i][j] = ' ';
                }
            }
        }
    }

    // Add more ASCII art of characters here...

    return arr;
}

// Function to print ASCII art of a given string
void printASCII(char* str) {
    
    // Initialize 2D array of characters to represent the ASCII art of the string
    char** arr = (char**) malloc(asciiHeight * sizeof(char*));    
    for(int i = 0; i < asciiHeight; i++) {
        arr[i] = (char*) malloc(asciiWidth * sizeof(char));
    }

    // Add the ASCII art of each character in the string to the 2D array
    int x = 0;
    for(int i = 0; i < STR_LEN && str[i] != '\0'; i++) {
        char** asciiChar = ascii(str[i]);
        for(int j = 0; j < charHeight; j++) {
            for(int k = 0; k < charWidth; k++) {
                arr[j][x + k] = asciiChar[j][k];
            }
        }
        x += charWidth;
        for(int j = 0; j < charHeight; j++) {
            free(asciiChar[j]); // Free the memory allocated for the ASCII art of the character
        }
        free(asciiChar);
    }

    // Print the 2D array of characters as ASCII art
    for(int i = 0; i < asciiHeight; i++) {
        for(int j = 0; j < asciiWidth; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the 2D array of characters
    for(int i = 0; i < asciiHeight; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {

    // Example usage
    char str[STR_LEN] = "EXAMPLE"; // Change this to the string you want to generate ASCII art of
    printASCII(str);

    return 0;
}