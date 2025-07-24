//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int pixel_art[HEIGHT][WIDTH];

void generate_pixel_art() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            pixel_art[i][j] = rand() % 2;
        }
    }
}

void print_pixel_art() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(pixel_art[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_pixel_art();
    print_pixel_art();
    return 0;
}