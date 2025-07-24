//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50 // Width of art in pixels
#define HEIGHT 20 // Height of art in pixels

int main() {
    srand(time(NULL)); // Seed the rand function with current time
    
    // Create a 2D array for the art
    int pixels[HEIGHT][WIDTH];
    
    // Generate random values for each pixel
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int randNum = rand() % 2;
            pixels[i][j] = randNum;
        }
    }
    
    // Print the art to the console
    printf("Here's your unique C Pixel Art:\n\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", pixels[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    
    return 0;
}