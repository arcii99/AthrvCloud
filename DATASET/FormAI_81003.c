//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the width and height of the ASCII art
#define WIDTH 50
#define HEIGHT 20

// function to convert character to ASCII art
char* convertToAscii(char);

int main() {
    // prompt user for input
    char input[50];
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, 50, stdin);

    // remove the newline character from input
    input[strcspn(input, "\n")] = 0;

    // define the ASCII art array
    char ascii[HEIGHT][WIDTH];

    // initialize all elements in the array to a space
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            ascii[i][j] = ' ';
        }
    }

    // iterate through the input string and add to the ASCII art array
    int xPos = 5; // starting x position
    int yPos = 3; // starting y position
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        char* asciiChar = convertToAscii(c);

        // copy the ASCII character to the ASCII art array
        for (int j = yPos, k = 0; j < yPos + 8; j++, k++) {
            for (int l = xPos, m = 0; l < xPos + 5; l++, m++) {
                ascii[j][l] = asciiChar[k * 5 + m];
            }
        }

        // update the x position for the next character
        xPos += 6;
    }

    // print the ASCII art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// function to convert character to ASCII art
char* convertToAscii(char c) {
    char* ascii;

    switch(c) {
        case 'A':
            ascii = "  /\\   \n /  \\  \n/    \\ \n\\/\\/\\/\n      \n";
            break;
        case 'B':
            ascii = "|||| \n|  | \n|||  \n|  | \n|||| \n";
            break;
        // add more cases for other characters...
        default:
            ascii = "     \n     \n     \n     \n     \n";
            break;
    }

    return ascii;
}