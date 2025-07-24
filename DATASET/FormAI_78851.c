//FormAI DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Define the pixel structure
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Define the image structure
typedef struct {
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
    int width;
    int height;
} Image;

// Function to read an image from a file
void read_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: unable to open file '%s'\n", filename);
        exit(1);
    }
    // Read the width and height of the image
    fscanf(fp, "%d %d\n", &image->width, &image->height);
    // Read the pixel data
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {    
            fscanf(fp, "%hhu %hhu %hhu ", &image->pixels[x][y].red, &image->pixels[x][y].green, &image->pixels[x][y].blue);
        }
    }
    fclose(fp);
}

// Function to write an image to a file
void write_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: unable to open file '%s'\n", filename);
        exit(1);
    }
    // Write the width and height of the image
    fprintf(fp, "%d %d\n", image->width, image->height);
    // Write the pixel data
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(fp, "%hhu %hhu %hhu ", image->pixels[x][y].red, image->pixels[x][y].green, image->pixels[x][y].blue);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Function to invert an image
void invert_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->pixels[x][y].red = 255 - image->pixels[x][y].red;
            image->pixels[x][y].green = 255 - image->pixels[x][y].green;
            image->pixels[x][y].blue = 255 - image->pixels[x][y].blue;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }
    Image image;
    read_image(&image, argv[1]);
    invert_image(&image);
    write_image(&image, argv[2]);
    return 0;
}