//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32
#define PIXEL_SIZE 4

// Define the colors
enum color {
    BLACK = 0,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    CYAN,
    WHITE,
    NUM_COLORS
};

// Define color values in RGB format
const int COLOR_VALUES[NUM_COLORS][3] = {
    {0, 0, 0},       // black
    {255, 0, 0},     // red
    {0, 255, 0},     // green
    {0, 0, 255},     // blue
    {255, 255, 0},   // yellow
    {255, 0, 255},   // magenta
    {0, 255, 255},   // cyan
    {255, 255, 255}  // white
};

// Define the pixel struct
typedef struct {
    int x;
    int y;
    enum color color;
} pixel;

// Generate a random pixel
pixel generate_pixel() {
    pixel p;
    p.x = rand() % WIDTH;
    p.y = rand() % HEIGHT;
    p.color = rand() % NUM_COLORS;
    return p;
}

// Generate a random pixel art image
void generate_image(pixel pixels[], int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        pixels[i] = generate_pixel();
    }
}

// Print the pixel art to the terminal
void print_image(pixel pixels[], int num_pixels) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char color_code[7];
            int color_index = -1;
            for (int k = 0; k < num_pixels; k++) {
                if (pixels[k].x == j && pixels[k].y == i) {
                    color_index = pixels[k].color;
                    break;
                }
            }
            if (color_index == -1) {
                sprintf(color_code, "\033[0m");
            } else {
                sprintf(color_code, "\033[48;2;%d;%d;%dm", COLOR_VALUES[color_index][0], COLOR_VALUES[color_index][1], COLOR_VALUES[color_index][2]);
            }
            printf("%s ", color_code);
        }
        printf("\033[0m\n");
    }
}

// Main function to generate pixel art
int main() {
    int num_pixels = (WIDTH * HEIGHT) / PIXEL_SIZE;
    pixel pixels[num_pixels];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the pixel art image
    generate_image(pixels, num_pixels);
    
    // Print the pixel art image
    print_image(pixels, num_pixels);
    
    return 0;
}