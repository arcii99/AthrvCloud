//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
// C Image Editor - safe example program

#include <stdio.h>
#include <stdlib.h>

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

void grayscale(struct Pixel *image, int width, int height) {
    struct Pixel *pixel;
    int i, j, r, g, b;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = image + i * width + j;
            r = pixel->red;
            g = pixel->green;
            b = pixel->blue;
            pixel->red = (unsigned char)(0.2989 * r + 0.5870 * g + 0.1140 * b);
            pixel->green = pixel->red;
            pixel->blue = pixel->red;
        }
    }
}

void mirror_horizontal(struct Pixel *image, int width, int height) {
    struct Pixel temp;
    struct Pixel *left_pixel, *right_pixel;
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width/2; j++) {
            left_pixel = image + i * width + j;
            right_pixel = image + (i + 1) * width - j - 1;
            temp = *left_pixel;
            *left_pixel = *right_pixel;
            *right_pixel = temp;
        }
    }
}

void flip_vertical(struct Pixel *image, int width, int height) {
    struct Pixel temp;
    struct Pixel *top_pixel, *bottom_pixel;
    int i, j;
    for (i = 0; i < height/2; i++) {
        for (j = 0; j < width; j++) {
            top_pixel = image + i * width + j;
            bottom_pixel = image + (height - i - 1) * width + j;
            temp = *top_pixel;
            *top_pixel = *bottom_pixel;
            *bottom_pixel = temp;
        }
    }
}

int main() {
    // Load image data from file
    FILE *image_file = fopen("image.raw", "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(EXIT_FAILURE);
    }
    int width, height;
    struct Pixel *image;
    fread(&width, sizeof(int), 1, image_file);
    fread(&height, sizeof(int), 1, image_file);
    image = (struct Pixel *)malloc(sizeof(struct Pixel) * width * height);
    fread(image, sizeof(struct Pixel), width * height, image_file);
    fclose(image_file);

    // Edit image
    grayscale(image, width, height);
    flip_vertical(image, width, height);
    mirror_horizontal(image, width, height);

    // Save edited image data to file
    FILE *edited_file = fopen("edited_image.raw", "wb");
    if (edited_file == NULL) {
        printf("Error: Could not open edited image file.\n");
        exit(EXIT_FAILURE);
    }
    fwrite(&width, sizeof(int), 1, edited_file);
    fwrite(&height, sizeof(int), 1, edited_file);
    fwrite(image, sizeof(struct Pixel), width * height, edited_file);
    fclose(edited_file);

    // Free memory
    free(image);

    return 0;
}