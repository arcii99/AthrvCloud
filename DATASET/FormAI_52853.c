//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fIn = fopen("inputImage.pgm", "rb"); //input image file in binary mode
    FILE *fOut = fopen("outputImage.pgm", "wb"); //output image file in binary mode
    int rows, cols, maxColor;
    fscanf(fIn, "%*s %d %d %d", &cols, &rows, &maxColor);
    fprintf(fOut, "P5\n%d %d\n%d\n", cols, rows, maxColor);

    unsigned char *image = malloc(sizeof(unsigned char) * rows * cols);
    fread(image, sizeof(unsigned char), rows * cols, fIn); //reading input image

    // flip the image horizontally
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            unsigned char temp = image[i * cols + j];
            image[i * cols + j] = image[i * cols + cols - 1 - j];
            image[i * cols + cols - 1 - j] = temp;
        }
    }

    fwrite(image, sizeof(unsigned char), rows * cols, fOut); //writing output image
    free(image);
    fclose(fIn);
    fclose(fOut);
    return 0;
}