//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80 // width of the screen
#define HEIGHT 40 // height of the screen
#define MAX_ITERATIONS 1000 // maximum number of iterations
#define PIXEL_SIZE 2 // size of each pixel in the image
#define MAX_COLORS 256 // maximum number of colors

// function to generate a random color
int random_color() {
    return rand() % MAX_COLORS;
}

// function to draw a pixel in the image
void draw_pixel(int x, int y, int color, char image[HEIGHT][WIDTH]) {
    for (int i = 0; i < PIXEL_SIZE; i++) {
        for (int j = 0; j < PIXEL_SIZE; j++) {
            image[y * PIXEL_SIZE + i][x * PIXEL_SIZE + j] = color;
        }
    }
}

// function to check if a point is inside the Mandelbrot set
bool in_mandelbrot(double x0, double y0, int iterations) {
    double x = 0.0;
    double y = 0.0;
    for (int i = 0; i < iterations; i++) {
        double x_temp = x;
        x = x * x - y * y + x0;
        y = 2 * x_temp * y + y0;
        if (x * x + y * y > 4) {
            return false;
        }
    }
    return true;
}

int main() {
    char image[HEIGHT][WIDTH];
    srand(time(NULL));
    // loop through all pixels
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double x0 = (double)(x - WIDTH/2) / (double)WIDTH * 4.0;
            double y0 = (double)(y - HEIGHT/2) / (double)HEIGHT * 4.0;
            if (in_mandelbrot(x0, y0, MAX_ITERATIONS)) { // if the point is inside the Mandelbrot set
                draw_pixel(x, y, 0, image); // draw a black pixel
            }
            else { // if the point is outside the Mandelbrot set
                draw_pixel(x, y, random_color(), image); // draw a random colored pixel
            }
        }
    }
    // print the image to the console
    for (int y = 0; y < HEIGHT*PIXEL_SIZE; y++) {
        for (int x = 0; x < WIDTH*PIXEL_SIZE; x++) {
            if (image[y][x] == 0) {
                printf(" ");
            }
            else {
                printf("\033[48;5;%dm ", image[y][x]);
            }
        }
        printf("\n");
    }
    return 0;
}