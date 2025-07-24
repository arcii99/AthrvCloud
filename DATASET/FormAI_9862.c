//FormAI DATASET v1.0 Category: Image Editor ; Style: excited
// Wow! This C Image Editor program is going to rock your socks off!

#include <stdio.h>
#include <stdlib.h>

// Let's define some constants for image size and color range
#define WIDTH 640
#define HEIGHT 480
#define COLOR_RANGE 255

// Here we declare the image array as a global variable
unsigned char image[HEIGHT][WIDTH];

// This function fills the image with random gray values
void createRandomImage() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % COLOR_RANGE;
        }
    }
}

// This function prints the image to the console
void printImage() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }
}

// This function inverts the colors of the image
void invertColors() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = COLOR_RANGE - 1 - image[i][j];
        }
    }
}

// This function flips the image horizontally
void flipHorizontal() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][WIDTH - 1 - j];
            image[i][WIDTH - 1 - j] = temp;
        }
    }
}

// This function rotates the image 90 degrees clockwise
void rotateClockwise() {
    unsigned char tempImage[WIDTH][HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            tempImage[j][HEIGHT - 1 - i] = image[i][j];
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = tempImage[i][j];
        }
    }
}

// This is the main function, where all the magic happens
int main() {
    // First, let's create a random image
    createRandomImage();
    printf("Original Image:\n");
    printImage();

    // Now, let's invert the colors of the image and print it again
    invertColors();
    printf("Inverted Colors:\n");
    printImage();

    // Next, let's flip the image horizontally and print it again
    flipHorizontal();
    printf("Horizontally Flipped:\n");
    printImage();

    // Finally, let's rotate the image clockwise and print it one last time
    rotateClockwise();
    printf("Clockwise Rotated:\n");
    printImage();

    // That's it! We've created a unique and awesome C Image Editor program!
    return 0;
}