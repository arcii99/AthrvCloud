//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>

int main() {
    char letters[27] = { // 26 letters in the alphabet plus a space character
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '
    };
    int ascii_letters[27] = { // corresponding decimal ASCII values for each letter plus space
        65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 32
    };
    char text[100]; // array to hold user input
    printf("Enter a string of text (max 100 characters): ");
    fgets(text, 100, stdin); // get user input of maximum length 100 characters
    int length = 0;
    // determine length of user input
    for (int i = 0; i < 100; i++) {
        if (text[i] == '\n') {
            text[i] = '\0'; // removes newline character added by fgets
            break;
        }
        length++;
    }
    printf("\n");
    int n = length; // number of characters in user input
    int num_rows = 8; // number of rows for each ASCII art character
    for (int i = 0; i < n; i++) { // loop through each character in user input
        char c = text[i];
        if (c == ' ') { // handle space character
            for (int j = 0; j < num_rows; j++) {
                printf("   \n"); // print three spaces for each row
            }
        } else {
            // find index of letter in letters array
            int index = 0;
            while (letters[index] != c) {
                index++;
            }
            // find decimal ASCII value of letter
            int ascii_value = ascii_letters[index];
            // print ascii art representation of letter
            for (int j = 0; j < num_rows; j++) {
                for (int k = 0; k < 8; k++) { // each ASCII character has 8 columns
                    if (ascii_value & (1 << (7 - k))) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n"); // add space between each ASCII letter
        }
    }
    return 0;
}