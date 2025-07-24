//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HEIGHT 16
#define WIDTH 16

int main(void) {
    // Use time as a seed for random numbers
    srand(time(NULL));
    
    // Initialize 2D array for pixel art
    int art[HEIGHT][WIDTH] = {0};
    
    // Generate random pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int rand_num = rand() % 2;
            art[i][j] = rand_num;
        }
    }
    
    // Print out the pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (art[i][j] == 0) {
                printf("-");
            } else {
                printf("@");
            }
        }
        printf("\n");
    }
    
    return 0;
}