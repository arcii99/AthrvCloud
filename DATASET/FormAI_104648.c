//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
// C Pixel Art Generator Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 30

// Define Pixel Structure
typedef struct {
    int r;
    int g;
    int b;
} Pixel;

// Define Array of Available Colors
Pixel colors[] = {
    {255, 0, 0},
    {0, 255, 0},
    {0, 0, 255},
    {255, 255, 0},
    {0, 255, 255},
    {255, 0, 255}
};

int main() {
    srand(time(NULL));
    
    // Generate Random Pixel Art
    Pixel art[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = rand() % (sizeof(colors) / sizeof(Pixel));
            art[y][x] = colors[index];
        }
    }
    
    // Print Pixel Art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Pixel pixel = art[y][x];
            printf("\x1b[48;2;%d;%d;%dm  \x1b[0m", pixel.r, pixel.g, pixel.b);
        }
        printf("\n");
    }
    
    return 0;
}