//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
/*
* ASCII Art Generator:
* This program converts text input into ASCII art.
* It uses various characters to create the illusion of a picture.
*
* Author: [Your Name Here]
*/

#include <stdio.h>

/* Define ASCII characters for art */
char white = '.', black = '#', gray = '+';

int main() {
    char input[1000];
    int i, j, k, l;
    int length;

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    length = strlen(input);

    /* Loop through each row of the art */
    for (i = 0; i < 7; i++) {

        /* Loop through each character of the input text */
        for (j = 0; j < length; j++) {

            char c = input[j];

            /* Choose a character based on the ASCII value of the input */
            if (c >= '0' && c <= '9') {
                if ((i == 0 && c == '1') ||
                    (i == 1 && (c == '4' || c == '5')) ||
                    (i == 2 && (c == '0' || c == '8' || c == '9')) ||
                    (i == 3 && (c == '0' || c == '6' || c == '8')) ||
                    (i == 4 && (c == '0' || c == '6' || c == '9')) ||
                    (i == 5 && (c == '1' || c == '2' || c == '3' || c == '4' || c == '7' || c == '8' || c == '9')) ||
                    (i == 6 && (c == '0' || c == '4' || c == '5' || c == '6' || c == '8'))) {
                    printf("%c%c%c", white, black, white);
                } else {
                    printf("%c%c%c", gray, gray, gray);
                }
            } else if (c >= 'a' && c <= 'z') {
                if ((i == 0 && (c == 'a' || c == 'k' || c == 'q' || c == 'x')) ||
                    (i == 1 && (c == 'b' || c == 'l' || c == 'r' || c == 'y')) ||
                    (i == 2 && (c == 'c' || c == 'm' || c == 's' || c == 'z')) ||
                    (i == 3 && (c == 'd' || c == 'n' || c == 't')) ||
                    (i == 4 && (c == 'e' || c == 'o' || c == 'u')) ||
                    (i == 5 && (c == 'f' || c == 'p' || c == 'v' || c == 'w')) ||
                    (i == 6 && (c == 'g' || c == 'h' || c == 'i' || c == 'j')) ||
                    (i == 7 && (c == ' '))) {
                    printf("%c%c%c%c", white, white, black, white);
                } else {
                    printf("%c%c%c%c", gray, gray, gray, gray);
                }
            } else if (c >= 'A' && c <= 'Z') {
                if ((i == 0 && (c == 'A' || c == 'K' || c == 'Q' || c == 'X')) ||
                    (i == 1 && (c == 'B' || c == 'L' || c == 'R' || c == 'Y')) ||
                    (i == 2 && (c == 'C' || c == 'M' || c == 'S' || c == 'Z')) ||
                    (i == 3 && (c == 'D' || c == 'N' || c == 'T')) ||
                    (i == 4 && (c == 'E' || c == 'O' || c == 'U')) ||
                    (i == 5 && (c == 'F' || c == 'P' || c == 'V' || c == 'W')) ||
                    (i == 6 && (c == 'G' || c == 'H' || c == 'I' || c == 'J')) ||
                    (i == 7 && (c == ' '))) {
                    printf("%c%c%c%c", white, white, black, white);
                } else {
                    printf("%c%c%c%c", gray, gray, gray, gray);
                }
            } else if (c == ' ') {
                printf("%c%c%c%c", gray, gray, gray, gray);
            } else {
                printf("%c%c%c%c", black, black, black, black);
            }
        }

        printf("\n");
    }

    return 0;
}