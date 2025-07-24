//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void print_pixel(char pixel) {
    if (pixel == 0) {
        printf(" ");
    } else if (pixel == 1) {
        printf("*");
    } else {
        printf("?");
    }
}

void generate_pixel(char *pixel) {
    int rand_num = rand() % 2;
    *pixel = rand_num;
}

void generate_image(char image[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            generate_pixel(&image[i][j]);
        }
    }
}

void print_image(char image[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        printf("|");
        for (j = 0; j < WIDTH; j++) {
            print_pixel(image[i][j]);
        }
        printf("|\n");
    }
}

int main() {
    srand(time(NULL));
    char image[HEIGHT][WIDTH];

    generate_image(image);
    print_image(image);

    return 0;
}