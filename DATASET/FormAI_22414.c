//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel canvas[WIDTH][HEIGHT];

void generatePixelArt() {
    // generate random color values for each pixel
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            canvas[i][j].r = rand() % 256;   // generate random value between 0 and 255
            canvas[i][j].g = rand() % 256;
            canvas[i][j].b = rand() % 256;
        }
    }
}

void printPixelArt() {
    // print the canvas
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            printf("\033[48;2;%d;%d;%dm ", canvas[i][j].r, canvas[i][j].g, canvas[i][j].b);   // change console background color
        }
        printf("\033[0m\n");   // reset console color to default
    }
}

int main() {
    generatePixelArt();
    printPixelArt();
    return 0;
}