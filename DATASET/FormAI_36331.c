//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_LINE_WIDTH 80
#define MAX_CHAR_HEIGHT 8

char ascii_chars[][9] = {
    "        ",
    "   XX   ",
    "  XXXX  ",
    " XX  XX ",
    "XXXXXXXX",
    "X      X",
    "X X  X X",
    "X  XX  X",
    "X      X",
    "        "
};

void print_char_row(char c, int row) {
    int index = c - '0';
    printf("%s\n", ascii_chars[index] + (row * 2));
}

void print_string_row(char *str, int row) {
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++) {
        print_char_row(str[i], row);
    }
    printf("\n");
}

int main() {
    char text[MAX_LINE_WIDTH + 1];
    int length, height;
    
    printf("Enter text: ");
    fgets(text, MAX_LINE_WIDTH + 1, stdin);
    length = strlen(text);
    
    height = MAX_CHAR_HEIGHT;
    
    for (int i = 0; i < height; i++) {
        print_string_row(text, i);
    }
    
    return 0;
}