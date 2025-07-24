//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <string.h>

void print_char(char c, int times) {
    for (int i = 0; i < times; i++) {
        putchar(c);
    }
}

void print_row(char* str, int len, int row) {
    if (row >= len) {
        return;
    }
    int spaces = (len - row - 1) * 2; // calculate number of spaces needed
    print_char(' ', spaces);
    printf("%c\n", str[row]); // print the character on the row
    print_row(str, len, row + 1); // recurse for the next row
}

void text_to_ascii_art(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        print_row(str, len, i);
    }
}

int main() {
    printf("Enter a string: ");
    char str[100];
    fgets(str, 100, stdin);
    text_to_ascii_art(str);
    return 0;
}