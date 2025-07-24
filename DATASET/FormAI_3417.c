//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>

// define the size of the canvas
#define WIDTH 10
#define HEIGHT 10

// define the pixel color options
#define BLACK 0
#define WHITE 1
#define RED 2
#define GREEN 3
#define BLUE 4

// define the pixel data structure
struct Pixel {
    int color;
};

// define the canvas data structure
struct Canvas {
    struct Pixel pixels[WIDTH][HEIGHT];
};

// function to set the color of a pixel at (x,y)
void setPixelColor(struct Canvas *canvas, int x, int y, int color) {
    canvas->pixels[x][y].color = color;
}

// function to print the canvas
void printCanvas(struct Canvas *canvas) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            switch (canvas->pixels[x][y].color) {
                case BLACK:
                    printf(" ");
                    break;
                case WHITE:
                    printf("O");
                    break;
                case RED:
                    printf("R");
                    break;
                case GREEN:
                    printf("G");
                    break;
                case BLUE:
                    printf("B");
                    break;
            }
        }
        printf("\n");
    }
}

int main() {
    // create a canvas
    struct Canvas canvas;

    // set some pixels to different colors
    setPixelColor(&canvas, 0, 0, BLACK);
    setPixelColor(&canvas, 1, 1, WHITE);
    setPixelColor(&canvas, 2, 2, RED);
    setPixelColor(&canvas, 3, 3, GREEN);
    setPixelColor(&canvas, 4, 4, BLUE);

    // print the canvas
    printCanvas(&canvas);

    return 0;
}