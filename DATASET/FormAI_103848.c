//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

void print_char(char c, int num_spaces, int num_chars) {
    for (int i = 0; i < num_spaces; i++) { // Printing leading spaces
        printf(" ");
    }
    for (int i = 0; i < num_chars; i++) { // Printing the character
        printf("%c", c);
    }
    printf("\n"); // End of line
}

int main() {
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 26; i++) {
        char c = alphabet[i];
        int num_spaces = 25 - i;
        int num_chars = (i * 2) + 1;
        print_char(c, num_spaces, num_chars);
    }
    for (int i = 24; i >= 0; i--) {
        char c = alphabet[i];
        int num_spaces = 25 - i;
        int num_chars = (i * 2) + 1;
        print_char(c, num_spaces, num_chars);
    }
    return 0;
}