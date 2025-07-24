//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 20

int main(void) {
    char text[ROWS][COLUMNS];
    int i, j;

    // Set all characters in the array to spaces
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            text[i][j] = ' ';
        }
    }

    // Ask user for input text
    printf("Enter text to convert to ASCII art (up to 10 characters): ");
    scanf("%s", &text[0]);

    // Convert each character in input text to ASCII art and store in array
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            switch(text[i][j]) {
                case 'A':
                    text[i][j] = ' /\\  ';
                    break;
                case 'B':
                    text[i][j] = '/_\\  ';
                    break;
                case 'C':
                    text[i][j] = '/    ';
                    break;
                case 'D':
                    text[i][j] = '/\\   ';
                    break;
                case 'E':
                    text[i][j] = '/___ ';
                    break;
                case 'F':
                    text[i][j] = '/___ ';
                    break;
                case 'G':
                    text[i][j] = '/ __ ';
                    break;
                case 'H':
                    text[i][j] = '/\\/\\ ';
                    break;
                case 'I':
                    text[i][j] = '  /  ';
                    break;
                case 'J':
                    text[i][j] = '   /\\';
                    break;
                case 'K':
                    text[i][j] = '/\\ / /';
                    break;
                case 'L':
                    text[i][j] = '/    ';
                    break;
                case 'M':
                    text[i][j] = '/\\/\\/\\';
                    break;
                case 'N':
                    text[i][j] = '/\\  /\\';
                    break;
                case 'O':
                    text[i][j] = '/\\/\\ ';
                    break;
                case 'P':
                    text[i][j] = '/__\\ ';
                    break;
                case 'Q':
                    text[i][j] = '/\\/\\ ';
                    break;
                case 'R':
                    text[i][j] = '/_\\ \\';
                    break;
                case 'S':
                    text[i][j] = '\\__/ ';
                    break;
                case 'T':
                    text[i][j] = ' /\\  ';
                    break;
                case 'U':
                    text[i][j] = '/  \\ ';
                    break;
                case 'V':
                    text[i][j] = '\\/\\/ ';
                    break;
                case 'W':
                    text[i][j] = '/\\/\\/\\';
                    break;
                case 'X':
                    text[i][j] = '\\/\\/ ';
                    break;
                case 'Y':
                    text[i][j] = ' \\/  ';
                    break;
                case 'Z':
                    text[i][j] = '/___ ';
                    break;
                case ' ':
                    text[i][j] = '     ';
                    break;
                default:
                    printf("\nInvalid character in input text.\n");
                    return 1;
            }
        }
    }

    // Print out ASCII art
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            printf("%c", text[i][j]);
        }
        printf("\n");
    }
    return 0;
}