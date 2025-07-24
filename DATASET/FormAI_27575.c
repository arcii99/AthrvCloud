//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXELS 1024

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[MAX_PIXELS][MAX_PIXELS];
    int width, height;
} Image;

void read_image(char* filename, Image* image) {
    FILE* fp = fopen(filename, "r");
    char header[128];

    // Read the header
    fgets(header, 128, fp);
    fscanf(fp, "%d %d", &image->width, &image->height);

    // Skip any remaining header information
    while (fgetc(fp) != '\n');

    // Read the pixel data
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel;
            fscanf(fp, "%d %d %d", &pixel.r, &pixel.g, &pixel.b);
            image->pixels[i][j] = pixel;
        }
    }

    fclose(fp);
}

void write_image(char* filename, Image* image) {
    FILE* fp = fopen(filename, "w");

    // Write the header
    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", image->width, image->height);
    fprintf(fp, "255\n");

    // Write the pixel data
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[i][j];
            fprintf(fp, "%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void flip_image(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            Pixel temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->width - j - 1];
            image->pixels[i][image->width - j - 1] = temp;
        }
    }
}

void adjust_brightness(Image* image, int amount) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[i][j];
            pixel.r += amount;
            pixel.g += amount;
            pixel.b += amount;
            
            // Clamp pixel values to the range [0, 255]
            pixel.r = fmax(0, fmin(255, pixel.r));
            pixel.g = fmax(0, fmin(255, pixel.g));
            pixel.b = fmax(0, fmin(255, pixel.b));

            image->pixels[i][j] = pixel;
        }
    }
}

void adjust_contrast(Image* image, float amount) {
    float factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[i][j];
            pixel.r = fmax(0, fmin(255, (int)(factor * (pixel.r - 128) + 128)));
            pixel.g = fmax(0, fmin(255, (int)(factor * (pixel.g - 128) + 128)));
            pixel.b = fmax(0, fmin(255, (int)(factor * (pixel.b - 128) + 128)));
            image->pixels[i][j] = pixel;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    Image image;
    read_image(argv[1], &image);

    flip_image(&image);
    adjust_brightness(&image, 50);
    adjust_contrast(&image, 1.5);

    write_image(argv[2], &image);

    return 0;
}