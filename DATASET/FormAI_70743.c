//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 32
#define HEIGHT 16

void generatePixelArt(char pixels[][WIDTH]);
void printPixelArt(char pixels[][WIDTH]);

int main() {
    char pixels[HEIGHT][WIDTH];
    generatePixelArt(pixels);
    printPixelArt(pixels);
    
    return 0;
}

void generatePixelArt(char pixels[][WIDTH]) {
    srand(time(0)); // seed random number generator
    
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            int r = rand() % 2;
            pixels[y][x] = r ? '#' : '.'; // set pixel to either '#' or '.'
        }
    }
}

void printPixelArt(char pixels[][WIDTH]) {
    printf("\n");
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            printf("%c", pixels[y][x]);
        }
        printf("\n");
    }
}