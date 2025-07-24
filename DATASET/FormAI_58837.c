//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random value within a given range
int randomValue(int min, int max){
    return rand() % (max - min + 1) + min;
}

int main(){
    // Set the canvas size
    int width = 30;
    int height = 30;

    // Initialize the canvas
    char pixelArt[height][width];

    // Initialize the random seed
    srand(time(NULL));

    // Generate the pixel art
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            // Generate a random value between 0 and 2
            int randVal = randomValue(0, 2);

            // Set the pixel color based on the random value
            if(randVal == 0){
                pixelArt[i][j] = ' ';
            } else if(randVal == 1){
                pixelArt[i][j] = '.';
            } else {
                pixelArt[i][j] = '#';
            }
        }
    }

    // Print the pixel art to the console
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}