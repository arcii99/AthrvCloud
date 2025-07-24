//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Pixel Art Generator!\n");
    
    // initialize random seed
    srand(time(NULL));
    
    // get user input for canvas size
    int width, height;
    printf("Enter width of canvas (between 1 and 100): ");
    scanf("%d", &width);
    printf("Enter height of canvas (between 1 and 100): ");
    scanf("%d", &height);
    
    // create 2D array to hold pixel art
    int canvas[height][width];
    
    // loop through each pixel in the canvas, randomly assign a color (0-255) to each pixel 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = rand() % 256;
        }
    }
    
    // print out the pixel art
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (canvas[i][j] < 128) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    
    return 0;
}