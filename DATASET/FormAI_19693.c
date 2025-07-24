//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: dynamic
#include <stdio.h>

char ascii_art[10][50];

void char_to_ascii(char character) {
    int ascii_value = (int) character;
    int row = (ascii_value / 10) - 3;
    int column = ascii_value % 10;
    sprintf(ascii_art[row] + (column * 5), "  _  ");
    sprintf(ascii_art[row + 1] + (column * 5), " / \\ ");
    sprintf(ascii_art[row + 2] + (column * 5), "(   )");
    sprintf(ascii_art[row + 3] + (column * 5), " \\_/ ");
}

void generate_ascii_art(char* text) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            ascii_art[i][j] = ' ';
        }
    }
    for (int i = 0; text[i]; i++) {
        char_to_ascii(text[i]);
    }
    for (int i = 0; i < 10; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

int main() {
    generate_ascii_art("ASCII ART");
    return 0;
}