//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // initialize random seed with current time
    int numPixels = 50;
    
    // set color palette for Cyberpunk style
    char colors[5][10] = {"#00ff00", "#00ffff", "#ff00ff", "#ff0000", "#ffffff"};
    
    // create pixel array
    char pixels[numPixels][numPixels][10];
    
    // fill pixel array with random colors from palette
    int i, j;
    for (i = 0; i < numPixels; i++) {
        for (j = 0; j < numPixels; j++) {
            int randIndex = rand() % 5;  // generate random index for color palette
            strcpy(pixels[i][j], colors[randIndex]);  // copy color into pixel array
        }
    }
    
    // print pixel art
    for (i = 0; i < numPixels; i++) {
        for (j = 0; j < numPixels; j++) {
            printf("%s ", pixels[i][j]);  // print pixel color with space between pixels
        }
        printf("\n");  // new line for each row of pixels
    }
    
    return 0;
}