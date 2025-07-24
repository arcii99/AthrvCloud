//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 15

void generate_ascii(char c) {
    int ascii[ROWS][COLS] = {0};
    int i, j;

    // Fill the ascii array based on the input character
    switch(c) {
        case 'A':
            ascii[0][4] = 1; ascii[0][10] = 1;
            ascii[1][3] = 1; ascii[1][5] = 1; ascii[1][9] = 1; ascii[1][11] = 1;
            ascii[2][2] = 1; ascii[2][5] = 1; ascii[2][7] = 1; ascii[2][9] = 1; ascii[2][12] = 1;
            ascii[3][1] = 1; ascii[3][5] = 1; ascii[3][13] = 1;
            ascii[4][0] = 1; ascii[4][6] = 1; ascii[4][8] = 1; ascii[4][14] = 1;
            break;
        case 'B':
            ascii[0][0] = 1; ascii[0][1] = 1; ascii[0][2] = 1; ascii[0][3] = 1; ascii[0][4] = 1; ascii[0][5] = 1; ascii[0][6] = 1; ascii[0][7] = 1; ascii[0][8] = 1; ascii[0][9] = 1; ascii[0][10] = 1;
            ascii[1][0] = 1; ascii[1][5] = 1; ascii[1][11] = 1;
            ascii[2][0] = 1; ascii[2][5] = 1; ascii[2][11] = 1;
            ascii[3][0] = 1; ascii[3][5] = 1; ascii[3][10] = 1;
            ascii[4][1] = 1; ascii[4][2] = 1; ascii[4][3] = 1; ascii[4][4] = 1; ascii[4][6] = 1; ascii[4][7] = 1; ascii[4][8] = 1; ascii[4][9] = 1; ascii[4][12] = 1; ascii[4][13] = 1; ascii[4][14] = 1;
            break;
        case 'C':
            ascii[0][2] = 1; ascii[0][3] = 1; ascii[0][4] = 1; ascii[0][5] = 1; ascii[0][6] = 1; ascii[0][7] = 1;
            ascii[1][1] = 1; ascii[1][8] = 1;
            ascii[2][0] = 1; ascii[2][9] = 1;
            ascii[3][1] = 1; ascii[3][8] = 1;
            ascii[4][2] = 1; ascii[4][3] = 1; ascii[4][4] = 1; ascii[4][5] = 1; ascii[4][6] = 1; ascii[4][7] = 1;
            break;
        default:
            printf("No ascii art available for input: %c\n", c);
            return;
    }

    // Print the generated ascii art
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (ascii[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[50];

    printf("Enter a string:\n");
    fgets(input, 50, stdin);

    int len = strlen(input);

    printf("The ASCII art generated from the input string:\n");

    int i;
    for (i = 0; i < len; i++) {
        generate_ascii(input[i]);
        printf("\n");
    }

    return 0;
}