//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 10          // Size of each pixel block
#define ART_WIDTH 100          // Width of the pixel grid in pixels
#define ART_HEIGHT 100         // Height of the pixel grid in pixels
#define NUM_COLORS 4           // Number of colors for the art

int main() {
    int art[ART_WIDTH][ART_HEIGHT];     // Pixel grid for the art
    int i, j;
    
    // Seed the randomizer
    srand(time(NULL));
    
    // Initialize the grid with random numbers between 0 and NUM_COLORS - 1
    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            art[i][j] = rand() % NUM_COLORS;
        }
    }
    
    // Print the art to the console
    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            switch (art[i][j]) {
                case 0:
                    printf("\033[41;37m  \033[0m");     // Red background, white foreground
                    break;
                case 1:
                    printf("\033[42;37m  \033[0m");     // Green background, white foreground
                    break;
                case 2:
                    printf("\033[43;37m  \033[0m");     // Yellow background, white foreground
                    break;
                case 3:
                    printf("\033[44;37m  \033[0m");     // Blue background, white foreground
                    break;
            }
        }
        printf("\n");
    }
    
    return 0;
}