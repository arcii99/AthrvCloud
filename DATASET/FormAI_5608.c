//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void print_pixel_art(char art[ROWS][COLS]) {
    // Clear screen before printing
    system("cls");

    // Print pixel art row by row
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define pixel art
    char pixel_art[ROWS][COLS] = {
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', '*'},
        {'*', ' ', '*', ' ', '*', ' ', '*', ' ', '*', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*'},
        {'*', ' ', '*', '*', '*', '*', '*', ' ', ' ', '*'},
        {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*'}
    };

    // Print pixel art
    print_pixel_art(pixel_art);

    return 0;
}