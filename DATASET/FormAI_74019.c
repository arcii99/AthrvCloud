//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40

void setFractalPixel(char pixels[HEIGHT][WIDTH], int x, int y, char value) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }
    pixels[y][x] = value;
}

void generateFractal(char pixels[HEIGHT][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // initialize all pixels to black
            pixels[y][x] = ' ';
        }
    }
    
    // set the center point to white
    setFractalPixel(pixels, WIDTH/2, HEIGHT/2, '#');
    
    // generate fractal pattern
    int i;
    int step = WIDTH/2;
    while (step > 0) {
        for (y = step; y < HEIGHT; y += step * 2) {
            for (x = step; x < WIDTH; x += step * 2) {
                // set diamond points to white
                setFractalPixel(pixels, x, y, '#');
            }
        }
        
        for (y = 0; y < HEIGHT; y += step * 2) {
            for (x = step; x < WIDTH; x += step * 2) {
                // set square points to white
                setFractalPixel(pixels, x, y, '#');
            }
        }
        
        step /= 2;
    }
}

void printFractal(char pixels[HEIGHT][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", pixels[y][x]);
        }
        printf("\n");
    }
}

int main() {
    char pixels[HEIGHT][WIDTH];
    generateFractal(pixels);
    printFractal(pixels);
    return 0;
}