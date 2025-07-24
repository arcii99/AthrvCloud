//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 64

typedef unsigned char byte;

// Define your color palette here
byte palette[] = {
    0x00, 0x00, 0x00, // Black
    0xFF, 0xFF, 0xFF, // White
    0x00, 0x7F, 0xFF, // Blue
    0xFF, 0x00, 0x00, // Red
    0xFF, 0xFF, 0x00, // Yellow
    0x00, 0xFF, 0x00, // Green
    0xFF, 0x00, 0xFF, // Magenta
    0x00, 0xFF, 0xFF, // Cyan
};

// Define the size of the palette
int palette_size = sizeof(palette) / sizeof(byte) / 3;

byte image[WIDTH][HEIGHT];
int x, y;

int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random image
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            image[x][y] = rand() % palette_size;
        }
    }

    // Print the image to the console
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            byte color = image[x][y];
            printf("\033[48;2;%d;%d;%dm  ", 
                palette[color*3], palette[color*3+1], palette[color*3+2]);
            printf("\033[0m");
        }
        printf("\n");
    }

    return 0;
}