//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include <stdio.h>

//Function to generate random pixel art
void generatePixelArt(int width, int height) {
    //Array to store pixel values
    int pixelArray[width][height];
    
    //Loop through each element in the array and generate random pixel value
    for(int i=0; i<width; i++) {
        for(int j=0; j<height; j++) {
            pixelArray[i][j] = rand() % 2;
        }
    }
    
    //Loop through each element in the array and print the corresponding pixel character
    for(int i=0; i<width; i++) {
        for(int j=0; j<height; j++) {
            if(pixelArray[i][j] == 0) {
                printf(" ");
            } else {
                printf("█");
            }
        }
        printf("\n");
    }
}

int main() {
    //Call the generatePixelArt function with width of 10 and height of 10
    generatePixelArt(10, 10);

    return 0;
}