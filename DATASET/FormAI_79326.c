//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10  // width of image in pixels
#define HEIGHT 10 // height of image in pixels
#define MAX_COLOR 255 // maximum color value

// struct to represent a pixel
typedef struct Pixel {
    int r; // red color value
    int g; // green color value
    int b; // blue color value
} Pixel;

// function to generate a random pixel
Pixel randomPixel() {
    Pixel p;
    p.r = rand() % (MAX_COLOR + 1); // generate random value for red color component
    p.g = rand() % (MAX_COLOR + 1); // generate random value for green color component
    p.b = rand() % (MAX_COLOR + 1); // generate random value for blue color component
    return p;
}

// function to print the color pixel values in the image
void printImage(Pixel image[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("(%d,%d,%d) ", image[i][j].r, image[i][j].g, image[i][j].b);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // initialize random number generator
    Pixel image[WIDTH][HEIGHT]; // initialize an array to hold the image data
    
    // generate a random image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = randomPixel();
        }
    }
    
    printImage(image); // print the randomly generated image
    
    return 0;
}