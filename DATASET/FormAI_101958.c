//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

// Function to print the pixel art
void printPixelArt(char pixelArt[][WIDTH]){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            printf("%c ",pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Define the characters used in pixel art
    char pixelChars[] = {'#', '@', 'O', '*', '='};

    // Define the 2D array to store the pixel art
    char pixelArt[HEIGHT][WIDTH];

    // Set the seed for random function
    srand(time(NULL));

    // Generate random pixel art
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            int pixelIndex = rand() % sizeof(pixelChars);
            pixelArt[i][j] = pixelChars[pixelIndex];
        }
    }

    // Print the generated pixel art
    printPixelArt(pixelArt);

    return 0;
}