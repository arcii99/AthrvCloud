//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

//Function to print the pixel art
void printPixelArt(char pixelArt[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", pixelArt[i][j]);
        }
        printf("\n");
    }
}

//Function to generate random pixel art
void generatePixelArt(char pixelArt[HEIGHT][WIDTH]) {
    srand(time(0));
    char pixels[] = {'*', '+', '-', '=', ':', '.', ' '};
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int index = rand() % 7;
            pixelArt[i][j] = pixels[index];
        }
    }
}

//Main function to execute the program
int main() {
    char pixelArt[HEIGHT][WIDTH];
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);
    return 0;
}