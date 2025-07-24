//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define COLOR_NUM 3

// Define structure for pixels
typedef struct {
    int x;
    int y;
    int color;
} Pixel;

// Declare function prototypes
void printPixelArt(Pixel *);
void generatePixelArt(Pixel *);

int main() {
    Pixel pixel_art[WIDTH * HEIGHT]; // Declare array of pixels
    srand(time(NULL)); // Seed random number generator

    generatePixelArt(pixel_art); // Generate random pixel art
    printPixelArt(pixel_art); // Print pixel art to console

    return 0;
}

// Function to print pixel art to console
void printPixelArt(Pixel *pixel_art) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            switch(pixel_art[y * WIDTH + x].color) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("#");
                    break;
                case 2:
                    printf("X");
                    break;
                default:
                    printf("?"); // If invalid color is used
            }
        }
        printf("\n");
    }
}

// Function to generate random pixel art
void generatePixelArt(Pixel *pixel_art) {
    for(int i = 0; i < WIDTH * HEIGHT; i++) {
        pixel_art[i].x = i % WIDTH;
        pixel_art[i].y = i / WIDTH;
        pixel_art[i].color = rand() % COLOR_NUM; // Generate random color
    }
}