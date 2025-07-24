//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_ASCII_WIDTH 200
#define MAX_ASCII_HEIGHT 200
#define ASCII_BLOCK '#'

void print_char_as_ascii(char c) {
    printf("%c\n", c);
    int ascii_code = (int)(c);
    printf("%d\n", ascii_code);

    int binary_num[8] = { 0 };
    int index = 0;
    while (ascii_code > 0) {
        binary_num[index] = ascii_code % 2;
        ascii_code = ascii_code / 2;
        index++;
    }
    for (int i = 7; i >= 0; i--) {
        printf("%d", binary_num[i]);
    }
}

void print_text_as_ascii(char text[]) {
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++) {
        print_char_as_ascii(text[i]);
    }
}

void generate_ascii_art(char text[], char ascii_art[MAX_ASCII_HEIGHT][MAX_ASCII_WIDTH]) {
    int text_length = strlen(text);
    int ascii_width = text_length * 6; // each character is 6 blocks wide
    int ascii_height = 5;

    for (int i = 0; i < ascii_height; i++) {
        for (int j = 0; j < ascii_width; j++) {
            ascii_art[i][j] = ASCII_BLOCK;
        }
    }

    for (int i = 0; i < text_length; i++) {
        int ascii_code = (int)(text[i]);
        int binary_num[8] = { 0 };
        int index = 0;
        while (ascii_code > 0) {
            binary_num[index] = ascii_code % 2;
            ascii_code = ascii_code / 2;
            index++;
        }
        for (int j = 0; j < 8; j++) {
            if (binary_num[j] == 1) {
                int col = (i * 6) + (7 - j);
                ascii_art[1][col] = ' ';
                ascii_art[2][col] = ' ';
                ascii_art[3][col] = ' ';
            }
        }
    }
}

int main() {
    char input_text[MAX_LINE_LENGTH];
    printf("Enter text to convert to ASCII art:\n");
    fgets(input_text, MAX_LINE_LENGTH, stdin);
    input_text[strcspn(input_text, "\n")] = '\0'; // remove newline character from input

    char ascii_art[MAX_ASCII_HEIGHT][MAX_ASCII_WIDTH];
    generate_ascii_art(input_text, ascii_art);

    int ascii_width = strlen(input_text) * 6;
    for (int i = 0; i < MAX_ASCII_HEIGHT; i++) {
        for (int j = 0; j < ascii_width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}