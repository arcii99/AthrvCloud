//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000]; // buffer to hold user input
    int ascii[8][100]; // 2D array to hold ascii art

    printf("Enter your text: ");
    fgets(input, sizeof(input), stdin); // read the input from user

    int len = strlen(input);
    int idx = 0; // index to loop through input

    // loop through each character of the input
    while (idx < len) {
        // convert the character to its ascii representation
        int ascii_value = (int) input[idx];

        // skip over whitespace characters
        if (isspace(input[idx])) {
            idx++;
            continue;
        }

        // loop through each row of the 2D array
        for (int i = 0; i < 8; i++) {
            // loop through each column of the current row
            for (int j = 0; j < 8; j++) {
                if (ascii_value & (1 << (7 - j))) {
                    ascii[i][j + idx*9] = 1; // set the bit to 1
                } else {
                    ascii[i][j + idx*9] = 0; // set the bit to 0
                }
            }
        }

        idx++; // move to the next character
    }

    // loop through each row of the 2D array
    for (int i = 0; i < 8; i++) {
        // loop through each column of the 2D array
        for (int j = 0; j < idx*9; j++) {
            if (ascii[i][j]) {
                printf("*"); // print an asterisk for a 1 bit
            } else {
                printf(" "); // print a space for a 0 bit
            }
        }
        printf("\n"); // move to the next line
    }

    return 0;
}