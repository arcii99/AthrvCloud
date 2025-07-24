//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Define the size of the artwork
    int width = 16;
    int height = 16;
    int pixels[height][width];

    // Seed the rand function based on current time
    srand(time(NULL));

    // Generate the pixel art
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            int random = rand() % 3;
            if(random == 0) pixels[row][col] = 0;   // black pixel
            else if(random == 1) pixels[row][col] = 1;  // white pixel
            else pixels[row][col] = 2;  //red pixel
        }
    }

    // Print the pixel art
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            if(pixels[row][col] == 0) printf("█");  // black pixel
            else if(pixels[row][col] == 1) printf("░");  // white pixel
            else printf("▒");  //red pixel
        }
        printf("\n");
    }

    return 0;
}