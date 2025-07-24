//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char pixel_art[HEIGHT][WIDTH];

void generate_art() {
    srand(time(NULL));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int probability = rand() % 100;
            if (probability < 10) {
                pixel_art[y][x] = '#';
            } else {
                pixel_art[y][x] = ' ';
            }
        }
    }
}

void print_art() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", pixel_art[y][x]);
        }
        printf("\n");
    }
}

int main() {
    generate_art();
    print_art();
    return 0;
}