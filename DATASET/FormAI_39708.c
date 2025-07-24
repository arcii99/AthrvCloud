//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print ASCII art
void printAsciiArt(char *text) {
    int len = strlen(text);
    char asciiArt[7][100]; // Array to store ASCII art

    // Filling the array with ASCII art of each character 
    asciiArt[0][0] = ' ';
    asciiArt[0][1] = '_';
    asciiArt[0][2] = ' ';
    asciiArt[0][3] = ' ';
    asciiArt[0][4] = '|';
    asciiArt[0][5] = '_';
    asciiArt[0][6] = '|';

    asciiArt[1][0] = '|';
    asciiArt[1][1] = ' ';
    asciiArt[1][2] = '/';
    asciiArt[1][3] = '/';
    asciiArt[1][4] = '|';
    asciiArt[1][5] = ' ';
    asciiArt[1][6] = ' ';

    asciiArt[2][0] = '|';
    asciiArt[2][1] = '_';
    asciiArt[2][2] = ' ';
    asciiArt[2][3] = ' ';
    asciiArt[2][4] = '|';
    asciiArt[2][5] = '_';
    asciiArt[2][6] = '|';

    asciiArt[3][0] = '|';
    asciiArt[3][1] = ' ';
    asciiArt[3][2] = '\\';
    asciiArt[3][3] = '\\';
    asciiArt[3][4] = '|';
    asciiArt[3][5] = ' ';
    asciiArt[3][6] = ' ';

    asciiArt[4][0] = '|';
    asciiArt[4][1] = '_';
    asciiArt[4][2] = ' ';
    asciiArt[4][3] = ' ';
    asciiArt[4][4] = '|';
    asciiArt[4][5] = '_';
    asciiArt[4][6] = '|';

    // Printing the ASCII art for each character in the given text
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < len; j++) {
            char c = text[j];
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A'; // Converting all characters to uppercase
            }
            int index = c - 'A';
            if (index < 0 || index > 25) {
                index = 26; // If character is not a letter, use the 27th ASCII art
            }
            printf("%c", asciiArt[i][index]);
        }
        printf("\n");
    }
}

int main() {
    char text[100];

    // Getting input from user
    printf("Enter some text:\n");
    fgets(text, 100, stdin);

    // Calling the function to print ASCII art of the text
    printAsciiArt(text);
    
    return 0;
}