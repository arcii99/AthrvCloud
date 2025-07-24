//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character from input
    
    int ascii_art[10][40]; // the size of the ASCII art
    
    // initialize ascii art to all spaces
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 40; j++) {
            ascii_art[i][j] = ' ';
        }
    }
    
    // convert input text to ASCII art
    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            index += 4; // add 4 spaces for every space character
        } else if (input[i] >= 'A' && input[i] <= 'Z') { // for uppercase letters
            for (int j = 0; j < 10; j++) {
                ascii_art[j][index] = '-';
            }
            for (int j = 0; j < 5; j++) {
                ascii_art[j][index+8] = '|';
            }
            for (int j = 5; j < 10; j++) {
                ascii_art[j][index+8] = '|';
            }
            for (int j = 0; j < 10; j++) {
                ascii_art[j][index+16] = '-';
            }
            index += 18; // skip over the letter
        } else if (input[i] >= 'a' && input[i] <= 'z') { // for lowercase letters
            for (int j = 2; j < 10; j++) {
                ascii_art[j][index] = '\\';
            }
            ascii_art[1][index+1] = '/';
            ascii_art[0][index+2] = '_';
            ascii_art[0][index+3] = '_';
            ascii_art[1][index+3] = '|';
            ascii_art[2][index+3] = '_';
            ascii_art[3][index+3] = '|';
            ascii_art[4][index+2] = '_';
            ascii_art[5][index+3] = '\\';
            for (int j = 2; j < 10; j++) {
                ascii_art[j][index+4] = '/';
            }
            index += 6; // skip over the letter
        } else { // for all other characters
            printf("Character not supported: %c\n", input[i]);
        }
    }
    
    // print the ASCII art
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 40; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}