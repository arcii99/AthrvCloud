//FormAI DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256   // image width
#define HEIGHT 256  // image height

// function to read image from file
void read_image(unsigned char img[][WIDTH], char *filename) {
    FILE *fptr;
    if ((fptr = fopen(filename,"rb")) == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }
    fread(img, sizeof(unsigned char), WIDTH*HEIGHT, fptr);
    fclose(fptr);
}

// function to write image to file
void write_image(unsigned char img[][WIDTH], char *filename) {
    FILE *fptr;
    if ((fptr = fopen(filename,"wb")) == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }
    fwrite(img, sizeof(unsigned char), WIDTH*HEIGHT, fptr);
    fclose(fptr);
}

// function to invert colors of the image
void invert_colors(unsigned char img[][WIDTH]) {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            img[i][j] = 255 - img[i][j];   // subtract each pixel value from 255
        }
    }
}

// function to grayscale the image
void grayscale(unsigned char img[][WIDTH]) {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            // calculate the grayscale value as the average of the RGB values
            unsigned char r = img[i][j];
            unsigned char g = img[i][j+1];
            unsigned char b = img[i][j+2];
            img[i][j] = img[i][j+1] = img[i][j+2] = (unsigned char)((r+g+b)/3);
        }
    }
}

// function to add a border to the image
void add_border(unsigned char img[][WIDTH], unsigned char border_color, int border_size) {
    int i, j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            if (i<border_size || i>(HEIGHT-border_size-1) || j<border_size || j>(WIDTH-border_size-1)) {
                img[i][j] = border_color;
            }
        }
    }
}

int main() {
    unsigned char img[HEIGHT][WIDTH];
    read_image(img, "input_image.bin");   // read image from file

    invert_colors(img);   // invert colors of the image
    write_image(img, "output_image_inverted.bin");   // write inverted image to file

    grayscale(img);   // grayscale the image
    write_image(img, "output_image_grayscale.bin");   // write grayscale image to file

    add_border(img, 128, 16);   // add a border to the image
    write_image(img, "output_image_with_border.bin");   // write bordered image to file

    return 0;
}