//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

int main() {
    int img[WIDTH][HEIGHT];
    //initialize the random number generator
    srand(time(NULL));
    
    //fill the image with random pixel values
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            img[x][y] = rand() % 2;
        }
    }

    //output the image as ASCII pixel art
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            if(img[x][y] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}