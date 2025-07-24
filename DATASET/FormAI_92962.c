//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 32

char pixels[HEIGHT][WIDTH];

void generate_pixel_art(int number_of_pixels) {
    int i;

    for(i = 0; i < number_of_pixels; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        char* pixel = &pixels[y][x];
        *pixel = rand() % 2 == 0 ? 'X' : 'O';
    }
}

void print_pixel_art() {
    int x, y;

    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            putchar(pixels[y][x]);
        }
        putchar('\n');
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));

    generate_pixel_art(WIDTH * HEIGHT / 4);
    print_pixel_art();

    return 0;
}