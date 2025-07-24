//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define image dimensions */
#define ROWS 512
#define COLS 512

/* Declare image matrix */
unsigned char image[ROWS][COLS];

/* Function to read image from file */
void read_image(char *filename) {
    FILE *file;
    int i, j;

    /* Open image file in read binary mode */
    if ((file = fopen(filename, "rb")) == NULL) {
        printf("Error: can't open %s\n", filename);
        exit(1);
    }

    /* Read image pixel values */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            image[i][j] = (unsigned char)fgetc(file);
        }
    }

    /* Close image file */
    fclose(file);
}

/* Function to write image to file */
void write_image(char *filename) {
    FILE *file;
    int i, j;

    /* Open output image file in write binary mode */
    if ((file = fopen(filename, "wb")) == NULL) {
        printf("Error: can't create %s\n", filename);
        exit(1);
    }

    /* Write image pixel values */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            fputc(image[i][j], file);
        }
    }

    /* Close output image file */
    fclose(file);
}

/* Function to flip image horizontally */
void flip_image_horizontally() {
    int i, j;
    unsigned char tmp;

    /* Swap columns from left to right */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS/2; j++) {
            tmp = image[i][j];
            image[i][j] = image[i][COLS-j-1];
            image[i][COLS-j-1] = tmp;
        }
    }
}

/* Function to adjust contrast of image */
void adjust_contrast(int contrast) {
    int i, j;

    /* Loop over image pixels */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            /* Apply contrast adjustment formula */
            image[i][j] = 128 + contrast*(image[i][j] - 128)/128;
        }
    }
}

/* Function to adjust brightness of image */
void adjust_brightness(int brightness) {
    int i, j;

    /* Loop over image pixels */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            /* Apply brightness adjustment formula */
            image[i][j] = image[i][j] + brightness;
        }
    }
}

/* Main function */
int main(int argc, char **argv) {
    /* Read input image filename from command line arguments */
    if (argc != 2) {
        printf("Usage: %s inputimage.raw\n", argv[0]);
        exit(1);
    }
    char *inputfile = argv[1];

    /* Read image from file */
    read_image(inputfile);

    /* Flip image horizontally */
    flip_image_horizontally();

    /* Adjust contrast and brightness */
    adjust_contrast(50);
    adjust_brightness(30);

    /* Write output image to file */
    char *outputfile = "output.raw";
    write_image(outputfile);

    return 0;
}