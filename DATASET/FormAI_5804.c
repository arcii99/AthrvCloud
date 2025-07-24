//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PIXEL_SIZE 10
#define WIDTH 60
#define HEIGHT 30

void generate_pixel_art() {
    int pixels[WIDTH][HEIGHT];
    srand(time(NULL));
    for(int x=0; x<WIDTH; x++) {
        for(int y=0; y<HEIGHT; y++) {
            pixels[x][y] = rand() % 2;
        }
    }
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            if(pixels[x][y] == 1) {
                printf("\033[48;2;255;255;255m  ");
            } else {
                printf("\033[48;2;0;0;0m  ");
            }
        }
        printf("\033[0m\n");
    }
}

int main() {
    generate_pixel_art();
    return 0;
}