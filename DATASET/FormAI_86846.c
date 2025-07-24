//FormAI DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the image
#define MAX_SIZE 100

// Define a struct for the image
typedef struct {
    int width;
    int height;
    char pixels[MAX_SIZE][MAX_SIZE];
} Image;

int main() {
    // Initialize the image
    Image img;
    strcpy(img.pixels[0], "*************");
    strcpy(img.pixels[1], "*   *   *   *");
    strcpy(img.pixels[2], "*************");
    img.width = 15;
    img.height = 3;

    // Display the original image
    printf("Original Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%c", img.pixels[i][j]);
        }
        printf("\n");
    }

    // Apply the greyscale filter
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.pixels[i][j] = '.';
        }
    }

    // Display the greyscale image
    printf("\nGreyscale Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%c", img.pixels[i][j]);
        }
        printf("\n");
    }

    // Apply the blur filter
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            img.pixels[i][j] = 'o';
        }
    }

    // Display the blurred image
    printf("\nBlurred Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%c", img.pixels[i][j]);
        }
        printf("\n");
    }

    // Apply the edge detection filter
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            if (img.pixels[i][j] == '*') {
                img.pixels[i][j] = '#';
            } else {
                img.pixels[i][j] = '.';
            }
        }
    }

    // Display the edge detected image
    printf("\nEdge Detected Image:\n");
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%c", img.pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}