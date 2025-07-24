//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// function to flip an image horizontally
void flip_horizontally(int image[][3], int width, int height) {
    int tmp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
}

// function to change the brightness of an image
void change_brightness(int image[][3], int width, int height, int factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = image[i][j] + factor;
            
            if (image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if (image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

// function to change the contrast of an image
void change_contrast(int image[][3], int width, int height, float factor) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = (int)((image[i][j] - 128) * factor + 128);
            
            if (image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if (image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

int main() {
    // initialize image
    int image[5][3] = {{50, 100, 150},
                       {200, 50, 100},
                       {150, 200, 50},
                       {100, 150, 200},
                       {50, 100, 150}};

    int width = 3;
    int height = 5;

    // flip image horizontally
    flip_horizontally(image, width, height);

    // print flipped image
    printf("Flipped Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%2d ", image[i][j]);
        }
        printf("\n");
    }

    // change brightness of image
    change_brightness(image, width, height, 50);

    // print brightened image
    printf("\nBrightened Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }

    // change contrast of image
    change_contrast(image, width, height, 1.5);

    // print contrast-enhanced image
    printf("\nContrast-Enhanced Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}