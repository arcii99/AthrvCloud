//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate pixel art
void generatePixelArt(int pixelSize) {
    int rows = 20; // set number of rows
    int cols = 20; // set number of columns
    
    // loop through each row
    for (int i = 0; i < rows; i++) {
        // loop through each column
        for (int j = 0; j < cols; j++) {
            // generate random color value for pixel
            int red = rand() % 256;
            int green = rand() % 256;
            int blue = rand() % 256;
            
            // print pixel to console
            printf("\x1b[48;2;%d;%d;%dm", red, green, blue);
            for (int k = 0; k < pixelSize; k++) {
                printf("  ");
            }
            printf("\x1b[0m"); // reset console color
        }
        printf("\n"); // start new row
    }
}

// main function
int main() {
    srand(time(NULL)); // seed random number generator
    
    printf("Welcome to the Pixel Art Generator!\n\n");
    
    // get user input for pixel size
    int pixelSize;
    printf("Enter the desired pixel size (in pixels per side): ");
    scanf("%d", &pixelSize);
    
    printf("\nGenerating pixel art...\n\n");
    
    generatePixelArt(pixelSize); // generate pixel art
    
    printf("\n\nThanks for using the Pixel Art Generator!\n");
    
    return 0;
}