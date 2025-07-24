//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 8
#define HEIGHT 8

void generatePixelArt(int arr[WIDTH][HEIGHT]);

int main(void) {
    int pixelArt[WIDTH][HEIGHT];
    srand(time(NULL));
    generatePixelArt(pixelArt);
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%d ", pixelArt[j][i]);
        }
        printf("\n");
    }
    return 0;
}

void generatePixelArt(int arr[WIDTH][HEIGHT]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            arr[j][i] = rand() % 2;
        }
    }
}