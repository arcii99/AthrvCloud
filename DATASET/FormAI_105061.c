//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8 // define the size of the pixel art grid

// function to generate a random color between 0 and 255
int randomColor(){
    return rand() % 256;
}

// function to print a single pixel with a given color
void pixel(int r, int g, int b){
    printf("\033[38;2;%d;%d;%dm█\033[0m", r, g, b);
}

// function to generate the pixel art
void generatePixelArt(){
    int pixelArt[SIZE][SIZE][3]; // 3D array to store color values of each pixel
    
    // initialize random seed
    srand(time(NULL));
    
    // fill the array with random colors
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            pixelArt[i][j][0] = randomColor(); // red component
            pixelArt[i][j][1] = randomColor(); // green component
            pixelArt[i][j][2] = randomColor(); // blue component
        }
    }
    
    // print the pixel art grid
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            pixel(pixelArt[i][j][0], pixelArt[i][j][1], pixelArt[i][j][2]);
        }
        printf("\n");
    }
}

// main function
int main(){
    generatePixelArt(); // call the function to generate the pixel art
    return 0;
}