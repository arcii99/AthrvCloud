//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2000 /* Change this value if your image's size is different */

struct Image {
    int width;
    int height;
    unsigned char pixels[MAX_SIZE][MAX_SIZE][3];
};

/* Function to read a PPM image file */
struct Image readPPM(const char *filename) {
    FILE *file;
    struct Image newImage;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Read image format */
    char format[3];
    fscanf(file, "%s", format);

    /* Read image dimensions */
    fscanf(file, "%d %d", &newImage.width, &newImage.height);

    /* Read maximum color value */
    int maxVal;
    fscanf(file, "%d", &maxVal);

    /* Read pixel values */
    int row, col;
    for (row = 0; row < newImage.height; row++) {
        for (col = 0; col < newImage.width; col++) {
            int r, g, b;
            fscanf(file, "%d %d %d", &r, &g, &b);
            newImage.pixels[row][col][0] = (unsigned char)r;
            newImage.pixels[row][col][1] = (unsigned char)g;
            newImage.pixels[row][col][2] = (unsigned char)b;
        }
    }

    fclose(file);
    return newImage;
}

/* Function to write a PPM image file */
void writePPM(const char *filename, struct Image img) {
    FILE *file;
    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Write image format */
    fprintf(file, "P3\n");

    /* Write image dimensions */
    fprintf(file, "%d %d\n", img.width, img.height);

    /* Write maximum color value */
    fprintf(file, "255\n");

    /* Write pixel values */
    int row, col;
    for (row = 0; row < img.height; row++) {
        for (col = 0; col < img.width; col++) {
            fprintf(file, "%d %d %d ", img.pixels[row][col][0], img.pixels[row][col][1], img.pixels[row][col][2]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

/* Function to flip an image horizontally */
void flipImageHorizontally(struct Image *img) {
    int row, col;
    for (row = 0; row < img->height; row++) {
        for (col = 0; col < img->width / 2; col++) {
            unsigned char tempR = img->pixels[row][col][0];
            unsigned char tempG = img->pixels[row][col][1];
            unsigned char tempB = img->pixels[row][col][2];

            img->pixels[row][col][0] = img->pixels[row][img->width - 1 - col][0];
            img->pixels[row][col][1] = img->pixels[row][img->width - 1 - col][1];
            img->pixels[row][col][2] = img->pixels[row][img->width - 1 - col][2];

            img->pixels[row][img->width - 1 - col][0] = tempR;
            img->pixels[row][img->width - 1 - col][1] = tempG;
            img->pixels[row][img->width - 1 - col][2] = tempB;
        }
    }
}

/* Function to change the brightness of an image */
void changeBrightness(struct Image *img, int brightness) {
    int row, col;
    for (row = 0; row < img->height; row++) {
        for (col = 0; col < img->width; col++) {
            img->pixels[row][col][0] += brightness;
            img->pixels[row][col][1] += brightness;
            img->pixels[row][col][2] += brightness;

            /* Make sure pixel values are within [0, 255] */ 
            if (img->pixels[row][col][0] < 0) {
                img->pixels[row][col][0] = 0;
            }
            if (img->pixels[row][col][1] < 0) {
                img->pixels[row][col][1] = 0;
            }
            if (img->pixels[row][col][2] < 0) {
                img->pixels[row][col][2] = 0;
            }
            if (img->pixels[row][col][0] > 255) {
                img->pixels[row][col][0] = 255;
            }
            if (img->pixels[row][col][1] > 255) {
                img->pixels[row][col][1] = 255;
            }
            if (img->pixels[row][col][2] > 255) {
                img->pixels[row][col][2] = 255;
            }
        }
    }
}

/* Function to change the contrast of an image */
void changeContrast(struct Image *img, int contrast) {
    /* Convert contrast value to a multiplier between [0, 2] */
    double multiplier = (double)contrast / 128.0 + 1.0;

    int row, col;
    for (row = 0; row < img->height; row++) {
        for (col = 0; col < img->width; col++) {
            img->pixels[row][col][0] = (unsigned char)((img->pixels[row][col][0] - 128) * multiplier + 128);
            img->pixels[row][col][1] = (unsigned char)((img->pixels[row][col][1] - 128) * multiplier + 128);
            img->pixels[row][col][2] = (unsigned char)((img->pixels[row][col][2] - 128) * multiplier + 128);

            /* Make sure pixel values are within [0, 255] */ 
            if (img->pixels[row][col][0] < 0) {
                img->pixels[row][col][0] = 0;
            }
            if (img->pixels[row][col][1] < 0) {
                img->pixels[row][col][1] = 0;
            }
            if (img->pixels[row][col][2] < 0) {
                img->pixels[row][col][2] = 0;
            }
            if (img->pixels[row][col][0] > 255) {
                img->pixels[row][col][0] = 255;
            }
            if (img->pixels[row][col][1] > 255) {
                img->pixels[row][col][1] = 255;
            }
            if (img->pixels[row][col][2] > 255) {
                img->pixels[row][col][2] = 255;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    /* Check command line arguments */
    if (argc != 5) {
        printf("Usage: %s [input PPM file] [output PPM file] [brightness value] [contrast value]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Read input image */
    struct Image inputImage = readPPM(argv[1]);

    /* Flip image horizontally */
    flipImageHorizontally(&inputImage);

    /* Change brightness */
    int brightness = atoi(argv[3]);
    changeBrightness(&inputImage, brightness);

    /* Change contrast */
    int contrast = atoi(argv[4]);
    changeContrast(&inputImage, contrast);

    /* Write output image */
    writePPM(argv[2], inputImage);

    return 0;
}