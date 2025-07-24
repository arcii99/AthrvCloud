//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: expert-level
#include <stdio.h> 

int main() {

    // Define the text to convert to ASCII art
    char text[] = "ASCII Art is Fun!";

    // Array to store the ASCII art 
    char art[7][128];

    // Fill the ASCII art array with spaces
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 128; j++) {
            art[i][j] = ' ';
        }
    }

    // Loop through the text and convert each character to ASCII art
    int x = 0; // x position in the ASCII art
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        switch(c) {
            case 'A': 
                art[0][x+1] = '_';
                art[1][x] = '/';
                art[1][x+2] = '\\';
                art[2][x] = '|';
                art[2][x+1] = 'A';
                art[2][x+2] = '|';
                art[3][x] = '|';
                art[3][x+1] = '|';
                art[3][x+2] = '|';
                art[4][x] = '|';
                art[4][x+1] = '|';
                art[4][x+2] = '|';
                art[5][x] = '|';
                art[5][x+1] = '_';
                art[5][x+2] = '|';
                x += 4;
                break;
            case ' ': 
                x += 3;
                break;
            case 'S': 
                art[0][x+1] = '_';
                art[0][x+2] = '_';
                art[1][x] = '/';
                art[2][x] = '|';
                art[2][x+2] = '_';
                art[3][x+2] = '/';
                art[4][x] = '\\';
                art[5][x] = '_';
                art[5][x+1] = '_';
                x += 4;
                break;
            case 'C': 
                art[0][x+1] = '_';
                art[0][x+2] = '_';
                art[1][x] = '/';
                art[2][x] = '|';
                art[3][x] = '|';
                art[4][x] = '\\';
                art[5][x+1] = '_';
                art[5][x+2] = '_';
                x += 4;
                break;
            case '!': 
                art[1][x+1] = '|';
                art[2][x+1] = '|';
                art[3][x+1] = '|';
                art[4][x+1] = '|';
                x += 2;
                break;
            default:
                x += 3;
                break;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 128; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}