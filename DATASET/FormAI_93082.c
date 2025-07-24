//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void flip_image(int cols, int rows, unsigned char* image) {
    unsigned char temp[3];  // temporary array to store RGB values
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols / 2; j++) {
            // swap pixels on opposite sides of the horizontal center line
            int idx1 = (i * cols + j) * 3;
            int idx2 = (i * cols + cols - j - 1) * 3;
            temp[0] = image[idx1];  // swap red component
            image[idx1] = image[idx2];
            image[idx2] = temp[0];
            temp[1] = image[idx1 + 1];  // swap green component
            image[idx1 + 1] = image[idx2 + 1];
            image[idx2 + 1] = temp[1];
            temp[2] = image[idx1 + 2];  // swap blue component
            image[idx1 + 2] = image[idx2 + 2];
            image[idx2 + 2] = temp[2];
        }
    }
}

void adjust_brightness_contrast(int cols, int rows, unsigned char* image, float brightness, float contrast) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int idx = (i * cols + j) * 3;
            // apply brightness adjustment
            image[idx] += brightness * 255.0;
            image[idx + 1] += brightness * 255.0;
            image[idx + 2] += brightness * 255.0;
            // apply contrast adjustment
            image[idx] = (image[idx] - 127.5) * contrast + 127.5;
            image[idx + 1] = (image[idx + 1] - 127.5) * contrast + 127.5;
            image[idx + 2] = (image[idx + 2] - 127.5) * contrast + 127.5;
        }
    }
}

int main() {
    int cols = 640;  // image width
    int rows = 480;  // image height
    unsigned char image[cols * rows * 3];  // RGB image array (8-bit per channel)
    int i, j;

    // initialize image with gradient pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int idx = (i * cols + j) * 3;
            image[idx] = j * 255 / cols;  // red component
            image[idx + 1] = i * 255 / rows;  // green component
            image[idx + 2] = 128;  // blue component
        }
    }

    // flip image horizontally
    flip_image(cols, rows, image);

    // adjust image brightness and contrast
    adjust_brightness_contrast(cols, rows, image, 0.2, 1.5);

    // save image to file in PPM format
    FILE* fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", cols, rows);
    fwrite(image, sizeof(unsigned char), cols * rows * 3, fp);
    fclose(fp);

    return 0;
}