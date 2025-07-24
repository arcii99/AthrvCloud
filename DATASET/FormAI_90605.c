//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANVAS_SIZE 10

// A single pixel
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

// A canvas of pixels
typedef struct {
    Pixel pixels[CANVAS_SIZE][CANVAS_SIZE];
} Canvas;

// Generate a random pixel
Pixel random_pixel() {
    Pixel pixel;
    pixel.red = rand() % 256;
    pixel.green = rand() % 256;
    pixel.blue = rand() % 256;
    return pixel;
}

// Clear the canvas
void clear_canvas(Canvas *canvas) {
    for (int i = 0; i < CANVAS_SIZE; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            canvas->pixels[i][j].red = 0;
            canvas->pixels[i][j].green = 0;
            canvas->pixels[i][j].blue = 0;
        }
    }
}

// Draw a pixel on the canvas
void draw_pixel(Canvas *canvas, int x, int y, Pixel pixel) {
    canvas->pixels[x][y] = pixel;
}

// Print the canvas
void print_canvas(Canvas *canvas) {
    for (int i = 0; i < CANVAS_SIZE; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            printf("(%d, %d, %d) ", canvas->pixels[i][j].red, canvas->pixels[i][j].green, canvas->pixels[i][j].blue);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    
    Canvas canvas;
    clear_canvas(&canvas);
    
    for (int i = 0; i < CANVAS_SIZE; i++) {
        for (int j = 0; j < CANVAS_SIZE; j++) {
            draw_pixel(&canvas, i, j, random_pixel());
        }
    }
    
    print_canvas(&canvas);
    
    return 0;
}