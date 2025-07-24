//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Linus Torvalds
#include <stdio.h>

#define ROWS 10
#define COLUMNS 10

void print_ascii_art(char ascii_art[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char ascii_art[ROWS][COLUMNS] = {
        {' ', ' ', ' ', ' ', ' ', '_', '_', '_', ' ', ' '},
        {' ', ' ', ' ', ' ', '/', ' ', ' ', ' ', '\\', ' '},
        {' ', ' ', ' ', '/', ' ', ' ', ' ', ' ', ' ', '\\'},
        {' ', ' ', '(', ' ', ' ', 'o', ' ', 'o', ' ', ')'},
        {' ', ' ', ' ', '\\', '_', '_', '/', ' ', ' ', '/'},
        {' ', ' ', ' ', ' ', ' ', '/', ' ', '\\', '_', '/'},
        {' ', ' ', ' ', ' ', '(', '_', '_', '_', '|', ')'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '/', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '(', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '_', ' '}
    };
    
    print_ascii_art(ascii_art);
    
    return 0;
}