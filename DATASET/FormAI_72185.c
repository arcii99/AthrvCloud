//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 16
#define HEIGHT 16

int pixels[WIDTH][HEIGHT];

void generate_pixels() {
    int i, j;
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            pixels[i][j] = rand() % 2;
        }
    }
}

void print_pixels() {
    int i, j;
    for(i=0; i<WIDTH; i++) {
        for(j=0; j<HEIGHT; j++) {
            if(pixels[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    generate_pixels();
    print_pixels();
    return 0;
}