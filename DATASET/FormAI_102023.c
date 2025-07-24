//FormAI DATASET v1.0 Category: Image Editor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel pixels[WIDTH][HEIGHT];
} Image;

void load_image(const char* filename, Image* img) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    if (strcmp(buffer, "P3\n") != 0) {
        printf("Error: Invalid file format\n");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "%d %d", &img->width, &img->height);

    fgets(buffer, sizeof(buffer), fp);
    // discard maximum color value

    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width; ++j) {
            Pixel* pix = &img->pixels[i][j];
            fread(&pix->red, sizeof(unsigned char), 1, fp);
            fread(&pix->green, sizeof(unsigned char), 1, fp);
            fread(&pix->blue, sizeof(unsigned char), 1, fp);
        }
    }

    fclose(fp);
}

void save_image(const char* filename, const Image* img) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);

    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width; ++j) {
            const Pixel* pix = &img->pixels[i][j];
            fprintf(fp, "%d %d %d ", pix->red, pix->green, pix->blue);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void invert_colors(Image* img) {
    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < img->width; ++j) {
            Pixel* pix = &img->pixels[i][j];
            pix->red = 255 - pix->red;
            pix->green = 255 - pix->green;
            pix->blue = 255 - pix->blue;
        }
    }
}

int main(void) {
    Image img;
    load_image("input.ppm", &img);

    // Apply some filters here
    invert_colors(&img);

    save_image("output.ppm", &img);

    return 0;
}