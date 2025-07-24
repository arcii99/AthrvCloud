//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel pixel[MAX_SIZE][MAX_SIZE];
} Image;

void flip_horizontal(Image *image) {
    int i, j;
    Pixel temp;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            temp = image->pixel[i][j];
            image->pixel[i][j] = image->pixel[i][image->width - j - 1];
            image->pixel[i][image->width - j - 1] = temp;
        }
    }
}

void flip_vertical(Image *image) {
    int i, j;
    Pixel temp;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            temp = image->pixel[i][j];
            image->pixel[i][j] = image->pixel[image->height - i - 1][j];
            image->pixel[image->height - i - 1][j] = temp;
        }
    }
}

void adjust_brightness(Image *image, int level) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int r = image->pixel[i][j].red + level;
            int g = image->pixel[i][j].green + level;
            int b = image->pixel[i][j].blue + level;
            if (r < 0) { r = 0; }
            if (g < 0) { g = 0; }
            if (b < 0) { b = 0; }
            if (r > 255) { r = 255; }
            if (g > 255) { g = 255; }
            if (b > 255) { b = 255; }
            image->pixel[i][j].red = r;
            image->pixel[i][j].green = g;
            image->pixel[i][j].blue = b;
        }
    }
}

void adjust_contrast(Image *image, float factor) {
    int i, j;
    float r, g, b;
    float avg;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            r = image->pixel[i][j].red / 255.0;
            g = image->pixel[i][j].green / 255.0;
            b = image->pixel[i][j].blue / 255.0;
            avg = (r + g + b) / 3.0;
            r = (r - avg) * factor + avg;
            g = (g - avg) * factor + avg;
            b = (b - avg) * factor + avg;
            if (r < 0) { r = 0; }
            if (g < 0) { g = 0; }
            if (b < 0) { b = 0; }
            if (r > 1) { r = 1; }
            if (g > 1) { g = 1; }
            if (b > 1) { b = 1; }
            image->pixel[i][j].red = r * 255;
            image->pixel[i][j].green = g * 255;
            image->pixel[i][j].blue = b * 255;
        }
    }
}

int main() {
    FILE *f_in, *f_out;
    Image image;
    int i, j;
    char type[3];
    int brightness;
    float contrast;

    // read input image
    f_in = fopen("input.ppm", "rb");
    if (!f_in) {
        fprintf(stderr, "Cannot open file: input.ppm\n");
        exit(1);
    }
    fscanf(f_in, "%s\n", type);
    if (type[0] != 'P' || type[1] != '6') {
        fprintf(stderr, "Invalid file format\n");
        exit(1);
    }
    fscanf(f_in, "%d %d\n", &image.width, &image.height);
    fscanf(f_in, "255\n");
    for (i = 0; i < image.height; i++) {
        for (j = 0; j < image.width; j++) {
            image.pixel[i][j].red = fgetc(f_in);
            image.pixel[i][j].green = fgetc(f_in);
            image.pixel[i][j].blue = fgetc(f_in);
        }
    }
    fclose(f_in);

    // flip horizontally
    flip_horizontal(&image);

    // flip vertically
    flip_vertical(&image);

    // adjust brightness
    printf("Enter brightness level (-255 to 255): ");
    scanf("%d", &brightness);
    adjust_brightness(&image, brightness);

    // adjust contrast
    printf("Enter contrast level (0.1 to 10.0): ");
    scanf("%f", &contrast);
    adjust_contrast(&image, contrast);

    // write output image
    f_out = fopen("output.ppm", "wb");
    if (!f_out) {
        fprintf(stderr, "Cannot create file: output.ppm\n");
        exit(1);
    }
    fprintf(f_out, "P6\n");
    fprintf(f_out, "%d %d\n", image.width, image.height);
    fprintf(f_out, "255\n");
    for (i = 0; i < image.height; i++) {
        for (j = 0; j < image.width; j++) {
            fputc(image.pixel[i][j].red, f_out);
            fputc(image.pixel[i][j].green, f_out);
            fputc(image.pixel[i][j].blue, f_out);
        }
    }
    fclose(f_out);

    printf("Image processing complete!\n");
    return 0;
}