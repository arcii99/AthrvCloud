//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define ASCII art characters
#define ROWS 8
#define COLS 8
const char font[128][ROWS][COLS+1] = {
    // Space
    { "        ",
      "        ",
      "        ",
      "        ",
      "        ",
      "        ",
      "        ",
      "        ", },

    // Letters A-Z
    { "  ##### ",
      " #     #",
      "#       #",
      "#       #",
      "#########",
      "#       #",
      "#       #",
      "#       #", },
    /* ... */

    // Symbols
    { "        ",
      "        ",
      "  ##### ",
      "  ##### ",
      "  ##### ",
      "        ",
      "        ",
      "        ", },

    // Error character
    { " ###### ",
      "#      #",
      "     ###",
      "    ### ",
      "   ###  ",
      "  ###   ",
      " ###    ",
      "######  ", },
};

// Converts a character to its ASCII art representation
void char_to_ascii(char input) {
    if(input < 32 || input > 127) {
        input = 127; // Use error character
    }
    const char (*character)[ROWS][COLS+1];
    character = &font[input];
    for(int i=0; i<ROWS; i++) {
        printf("%s\n", (*character)[i]);
    }
}

int main() {
    // ASCII art text generator
    char input[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, 100, stdin);
    printf("\n");
    for(int i=0; i<strlen(input); i++) {
        char_to_ascii(input[i]);
        if(input[i] != '\n') {
            printf("\n");
        }
    }
    return 0;
}