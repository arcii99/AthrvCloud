//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// function to print image to console
void printImage(int image[WIDTH][HEIGHT]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// function to generate random image
void generateImage(int image[WIDTH][HEIGHT]) {
    srand(time(NULL)); // seed the random generator
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 2; // generate either 0 or 1
        }
    }
}

int main() {
    int image[WIDTH][HEIGHT];
    generateImage(image); // generate the image
    printImage(image); // print the image to console
    return 0;
}