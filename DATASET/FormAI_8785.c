//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define CELL_SIZE 3

void draw_pixel(char symbol) {
    int i, j;
    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            printf("%c", symbol);
        }
    }
}

void clear_screen() {
    system("clear || cls"); // clear the screen
}

void draw_art(char art[HEIGHT][WIDTH]) {
    int x, y;
    clear_screen();
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (art[y][x] == 'X') {
                draw_pixel('#');
            } else {
                draw_pixel(' ');
            }
        }
        printf("\n"); // move to the next line
    }
}

void generate_art(char art[HEIGHT][WIDTH]) {
    int x, y;
    srand(time(NULL)); // seed the random number generator
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (rand() % 2 == 0) {
                art[y][x] = 'X';
            } else {
                art[y][x] = ' ';
            }
        }
    }
}

int main() {
    char art[HEIGHT][WIDTH];
    generate_art(art);
    draw_art(art);
    return 0;
}