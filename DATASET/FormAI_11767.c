//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int width, height;
    printf("Welcome to the Pixel Art Generator! \n");
    printf("Enter the width of your art: ");
    scanf("%d", &width);
    printf("Enter the height of your art: ");
    scanf("%d", &height);
    
    // Let's create a random grid of color values for each pixel in the image
    int grid[height][width];
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            grid[i][j] = rand() % 256; // random color value between 0 and 255
        }
    }
    
    // Now let's print out the grid, pixel by pixel!
    printf("Here is your pixel art:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(grid[i][j] < 128) {
                printf("."); // print a dark pixel
            } else {
                printf("#"); // print a light pixel
            }
        }
        printf("\n"); // move to the next row
    }
    
    printf("Thank you for using the Pixel Art Generator!\n");
    return 0;
}