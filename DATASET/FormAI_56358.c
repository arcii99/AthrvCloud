//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include <stdio.h>
#include <string.h>

char asciiArt[8][80];

void printAscii(char* input) {
    int len = strlen(input);
    int i, j;
    char row1[] = "  ## ";
    char row2[] = " #  #";
    char row3[] = "#    #";
    char row4[] = "######";
    char row5[] = "#    #";
    char row6[] = "#    #";
    char space[] = "     ";

    // fill up the asciiArt buffer with spaces
    memset(asciiArt, ' ', sizeof(char) * 8 * 80);

    // loop through each character in input
    for (i = 0; i < len; i++) {
        char c = input[i];

        // calculate the offset that the character should be placed at
        int offset = i * 6;

        // switch case statement to generate the appropriate ascii art for the character
        switch(c) {
            case 'A':
                strncpy(&asciiArt[0][offset], row1, 6);
                strncpy(&asciiArt[1][offset], row2, 6);
                strncpy(&asciiArt[2][offset], row3, 6);
                strncpy(&asciiArt[3][offset], row4, 6);
                strncpy(&asciiArt[4][offset], row5, 6);
                strncpy(&asciiArt[5][offset], row6, 6);
                break;
            case 'B':
                // generate ascii art for 'B'
                break;
            case 'C':
                // generate ascii art for 'C'
                break;
            // add more cases for other characters
        }
    }

    // loop through the asciiArt buffer and print out the result
    for (i = 0; i < 8; i++) {
        for (j = 0; j < len * 6; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char input[] = "HELLO WORLD";
    printAscii(input);
    return 0;
}