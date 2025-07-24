//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to generate random numbers within a certain range
int random_range(int min, int max) {
    return ((rand() % (max - min + 1)) + min);
}

int main() {
    // initialize variables
    int width, height, color_depth;
    char filename[50];
    
    printf("Welcome to the C Pixel Art Generator!\n");
    
    // get user input for image dimensions and color depth
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    
    printf("Enter the color depth of the image (1-8): ");
    scanf("%d", &color_depth);
    
    // create filename from user input
    sprintf(filename, "pixelart_%dx%d_%dcolors.ppm", width, height, color_depth);
    
    // open file for writing
    FILE *fp = fopen(filename, "w");
    
    // write P3 header to file
    fprintf(fp, "P3\n%d %d\n%d\n", width, height, (int) pow(2, color_depth) - 1);
    
    // seed rand() with current time
    srand(time(NULL));
    
    // loop through rows and columns of image
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // generate random RGB values based on color depth
            int red = random_range(0, (int) pow(2, color_depth) - 1);
            int green = random_range(0, (int) pow(2, color_depth) - 1);
            int blue = random_range(0, (int) pow(2, color_depth) - 1);
            
            // write pixel to file in correct format
            fprintf(fp, "%d %d %d ", red, green, blue);
        }
        fprintf(fp, "\n");
    }
    
    // close file
    fclose(fp);
    
    printf("Pixel art generated successfully!\n");
    
    return 0;
}