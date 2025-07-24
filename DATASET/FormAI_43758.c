//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 500 
#define HEIGHT 500
#define NUM_COLORS 4 

// Define the pixel struct
typedef struct {
    unsigned char r, g, b;
} pixel_t;

// Define the canvas
pixel_t canvas[WIDTH][HEIGHT];

// Define the color palette
pixel_t palette[NUM_COLORS] = {
    {255, 255, 255}, // white
    {0, 0, 0},       // black
    {255, 0, 0},     // red
    {0, 255, 0}      // green
};

// Define function to fill canvas with specific color
void fill_canvas(pixel_t color) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            canvas[y][x] = color;
        }
    }
}

// Define function to draw a rectangle
void draw_rectangle(int x1, int y1, int x2, int y2, pixel_t color) {
    int x, y;
    for (y = y1; y < y2; y++) {
        for (x = x1; x < x2; x++) {
            canvas[y][x] = color;
        }
    }
}

int main() {
    // Fill the canvas with white color
    fill_canvas(palette[0]);

    // Draw a black rectangle using four colors
    draw_rectangle(50, 50, 200, 200, palette[1]);
    draw_rectangle(60, 60, 190, 190, palette[2]);
    draw_rectangle(70, 70, 180, 180, palette[3]);
    draw_rectangle(80, 80, 170, 170, palette[1]);

    // Save output as PPM format
    FILE* fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fwrite(&canvas[y][x], 1, 3, fp);
        }
    }

    fclose(fp);

    return 0;
}