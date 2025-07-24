//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20 //width of image
#define HEIGHT 10 //height of image

//function to generate random pixel (r, g, b) values
void generatePixel(int *r, int *g, int *b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

int main() {
    int pixels[HEIGHT][WIDTH][3]; //3D array to hold r, g, b values for each pixel

    srand(time(NULL)); //initialize random seed using current time
    
    //generate random pixel values for each pixel in image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            generatePixel(&pixels[i][j][0], &pixels[i][j][1], &pixels[i][j][2]);
        }
    }

    //print out pixel values in PPM format
    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d %d %d ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }
        printf("\n");
    }
    
    return 0;
}