//FormAI DATASET v1.0 Category: Image Editor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000 // Maximum image width
#define MAX_HEIGHT 1000 // Maximum image height

typedef struct {
    unsigned char r, g, b; // RGB value
} pixel_t;

typedef struct {
    pixel_t pixels[MAX_WIDTH][MAX_HEIGHT]; // 2D array of pixels
    int width, height; // Dimensions of image
} image_t;

// Function to read image from file
void read_image(FILE *fp, image_t *img) {
    char format[3]; // PPM image format
    int maxval; // Maximum value of RGB component
    fscanf(fp, "%2s %d %d %d", format, &img->width, &img->height, &maxval);
    int r, g, b;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(fp, "%d %d %d", &r, &g, &b);
            img->pixels[i][j].r = r;
            img->pixels[i][j].g = g;
            img->pixels[i][j].b = b;
        }
    }
}

// Function to write image to file
void write_image(FILE *fp, image_t *img) {
    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d %d %d ", img->pixels[i][j].r, img->pixels[i][j].g, img->pixels[i][j].b);
        }
        fprintf(fp, "\n");
    }
}

// Function to invert the colors of the image
void invert_colors(image_t *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j].r = 255 - img->pixels[i][j].r;
            img->pixels[i][j].g = 255 - img->pixels[i][j].g;
            img->pixels[i][j].b = 255 - img->pixels[i][j].b;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input.ppm output.ppm\n", argv[0]);
        return 1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }
    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Error opening file %s\n", argv[2]);
        return 1;
    }
    image_t img;
    read_image(fin, &img); // Read image from file
    invert_colors(&img); // Invert colors of image
    write_image(fout, &img); // Write image to file
    fclose(fin);
    fclose(fout);
    return 0;
}