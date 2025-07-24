//FormAI DATASET v1.0 Category: Image compression ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 255

// Function to compress an image
void compressImage(int image[WIDTH][HEIGHT]) {
    int compressed[WIDTH/2][HEIGHT/2];
    for (int i = 0; i < WIDTH; i += 2) {
        for (int j = 0; j < HEIGHT; j += 2) {
            int sum = image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1];
            compressed[i/2][j/2] = sum / 4; // average the 4 values
        }
    }
    // print the compressed image
    printf("Compressed image:\n");
    for (int i = 0; i < WIDTH/2; i++) {
        for (int j = 0; j < HEIGHT/2; j++) {
            printf("%d ", compressed[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // generate random image
    int image[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = rand() % (MAX_COLOR+1);
        }
    }
    // print original image
    printf("Original image:\n");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    // compress image and print
    compressImage(image);
    return 0;
}