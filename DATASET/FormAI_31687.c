//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

const int WIDTH = 32;
const int HEIGHT = 32;

void drawPixel(Pixel pixel) {
    printf("\033[38;2;%d;%d;%dm█\033[0m", pixel.red, pixel.green, pixel.blue);
}

int main() {
    Pixel pixels[HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            pixels[i][j].red = i;
            pixels[i][j].green = j;
            pixels[i][j].blue = i*j;
        }
    }

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            drawPixel(pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}