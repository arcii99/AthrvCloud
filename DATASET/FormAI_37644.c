//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15
#define HEIGHT 10

void set_pixel(char img[HEIGHT][WIDTH], int row, int col, char color) {
    img[row][col] = color;
}

void generate_pixel_art(char img[HEIGHT][WIDTH]) {
    int i, j;
    char colors[] = {'r', 'g', 'b', 'y'};
    srand(time(0)); // initialize random seed

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            // get a random pixel color
            int rand_idx = rand() % 4;
            char color = colors[rand_idx];
            set_pixel(img, i, j, color);
        }
    }
}

void print_pixel_art(char img[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c ", img[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixel_art[HEIGHT][WIDTH];
    generate_pixel_art(pixel_art);
    print_pixel_art(pixel_art);
    return 0;
}