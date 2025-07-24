//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_HEIGHT 500
#define IMG_WIDTH 500

// Function for flipping an image horizontally
void flip_image_horizontal(unsigned char image[IMG_HEIGHT][IMG_WIDTH], unsigned char flipped_image[IMG_HEIGHT][IMG_WIDTH]) {
    int i, j;
    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            flipped_image[i][j] = image[i][IMG_WIDTH - 1 - j];
        }
    }
}

// Function for changing brightness of an image
void change_brightness(unsigned char image[IMG_HEIGHT][IMG_WIDTH], unsigned char bright_image[IMG_HEIGHT][IMG_WIDTH], int brightness) {
    int i, j;

    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            int new_pixel = (int)image[i][j] + brightness;
            if (new_pixel < 0) {
                new_pixel = 0;
            } else if (new_pixel > 255) {
                new_pixel = 255;
            }
            bright_image[i][j] = (unsigned char)new_pixel;
        }
    }
}

// Function for changing contrast of an image
void change_contrast(unsigned char image[IMG_HEIGHT][IMG_WIDTH], unsigned char contrast_image[IMG_HEIGHT][IMG_WIDTH], float contrast) {
    int i, j;

    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            float new_pixel = (((float)image[i][j] - 127.5) * contrast) + 127.5;
            if (new_pixel < 0) {
                new_pixel = 0;
            } else if (new_pixel > 255) {
                new_pixel = 255;
            }
            contrast_image[i][j] = (unsigned char)new_pixel;
        }
    }
}

int main() {
    // Initialize the image
    unsigned char image[IMG_HEIGHT][IMG_WIDTH];

    int i, j;
    for (i = 0; i < IMG_HEIGHT; i++) {
        for (j = 0; j < IMG_WIDTH; j++) {
            // Make a checkerboard pattern
            if ((i / 50 + j / 50) % 2 == 0) {
                image[i][j] = 255;
            } else {
                image[i][j] = 0;
            }
        }
    }

    // Flip the image horizontally
    unsigned char flipped_image[IMG_HEIGHT][IMG_WIDTH];
    flip_image_horizontal(image, flipped_image);

    // Change the brightness of the image
    unsigned char bright_image[IMG_HEIGHT][IMG_WIDTH];
    change_brightness(image, bright_image, 50);

    // Change the contrast of the image
    unsigned char contrast_image[IMG_HEIGHT][IMG_WIDTH];
    change_contrast(image, contrast_image, 1.5);

    // Write the images to files
    FILE *fp;

    fp = fopen("original.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    fwrite(image, sizeof(unsigned char), IMG_HEIGHT * IMG_WIDTH, fp);
    fclose(fp);

    fp = fopen("flipped.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    fwrite(flipped_image, sizeof(unsigned char), IMG_HEIGHT * IMG_WIDTH, fp);
    fclose(fp);

    fp = fopen("bright.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    fwrite(bright_image, sizeof(unsigned char), IMG_HEIGHT * IMG_WIDTH, fp);
    fclose(fp);

    fp = fopen("contrast.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n255\n", IMG_WIDTH, IMG_HEIGHT);
    fwrite(contrast_image, sizeof(unsigned char), IMG_HEIGHT * IMG_WIDTH, fp);
    fclose(fp);

    printf("Done!\n");

    return 0;
}