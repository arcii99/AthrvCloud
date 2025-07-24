//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 10
#define HEIGHT 10

// Function to print the pixel art
void print_pixel_art(int pixel_array[HEIGHT][WIDTH]) {
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("%d ", pixel_array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Random seed for the generator
    srand(time(NULL));
    
    // Initialize the pixel art array to 0
    int pixel_array[HEIGHT][WIDTH] = {0};
    
    // Generate random pixels
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            int random_num = rand() % 2;
            pixel_array[i][j] = random_num;
        }
    }
    
    // Print the pixel art array
    printf("Here's your unique pixel art:\n");
    print_pixel_art(pixel_array);
    
    return 0;
}