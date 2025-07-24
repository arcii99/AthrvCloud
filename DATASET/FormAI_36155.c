//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scalable
#include <stdio.h>

#define CHAR_WIDTH 8 // width of each ASCII art character
#define CHAR_HEIGHT 8 // height of each ASCII art character
#define MAX_LINE_LENGTH 100 // maximum length of input line

const char ascii_art[96][CHAR_HEIGHT][CHAR_WIDTH+1] = {
    // ASCII art characters from 32 to 127 (excluding control characters)
    // each character is represented as a 2D array of characters
    // for example, ascii_art[0] contains the " " (space) character
  {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
  },
  {
    "  _     ",
    " / \\  ",
    "(   )",
    " \\ /  ",
    "  v     ",
    "        ",
    "        ",
    "        "
  },
  //... rest of the ASCII art characters
};

void print_ascii_art(char* line) {
    // this function prints the ASCII art representation of the input line
  
    int line_length = strlen(line);
  
    for (int row = 0; row < CHAR_HEIGHT; row++) {
        for (int i = 0; i < line_length; i++) {
            char c = line[i];
            if (c >= 32 && c <= 127) {
                int index = c - 32;
                printf("%s", ascii_art[index][row]);
                // print a space between characters for better readability
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    printf("Enter a string: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    print_ascii_art(line);
    return 0;
}