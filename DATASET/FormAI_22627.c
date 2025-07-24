//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_PIXEL_VALUE 255

typedef struct {
    unsigned char data[MAX_WIDTH][MAX_HEIGHT];
    int width;
    int height;
} Image;

void read_image(char* filename, Image* img) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // read header information
    char magic_number[3];
    int max_value;
    fscanf(file, "%s\n%d %d\n%d\n", magic_number, &img->width, &img->height, &max_value);

    // check if image is in PGM format
    if (strcmp(magic_number, "P5") != 0 || max_value != MAX_PIXEL_VALUE) {
        printf("Error: Invalid PGM file format or max value");
        exit(1);
    }

    // read image data
    for (int y = 0; y < img->height; y++) {
        fread(img->data[y], sizeof(unsigned char), img->width, file);
    }
    
    fclose(file);
}

void write_image(char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // write header information
    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, MAX_PIXEL_VALUE);

    // write image data
    for (int y = 0; y < img->height; y++) {
        fwrite(img->data[y], sizeof(unsigned char), img->width, file);
    }
    
    fclose(file);
}

void flip_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            unsigned char temp = img->data[y][x];
            img->data[y][x] = img->data[y][img->width - 1 - x];
            img->data[y][img->width - 1 - x] = temp;
        }
    }
}

void adjust_brightness(Image* img, int brightness) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int new_brightness = img->data[y][x] + brightness;
            if (new_brightness < 0) {
                new_brightness = 0;
            } else if (new_brightness > MAX_PIXEL_VALUE) {
                new_brightness = MAX_PIXEL_VALUE;
            }
            img->data[y][x] = (unsigned char)new_brightness;
        }
    }
}

void adjust_contrast(Image* img, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int new_brightness = factor * (img->data[y][x] - 128) + 128;
            if (new_brightness < 0) {
                new_brightness = 0;
            } else if (new_brightness > MAX_PIXEL_VALUE) {
                new_brightness = MAX_PIXEL_VALUE;
            }
            img->data[y][x] = (unsigned char)new_brightness;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: image_processing <input_file> <output_file> <flip|bright|contrast> [value]\n");
        exit(1);
    }

    // read input image file
    Image img;
    read_image(argv[1], &img);

    // perform selected image processing technique
    if (strcmp(argv[3], "flip") == 0) {
        flip_image(&img);
    } else if (strcmp(argv[3], "bright") == 0) {
        if (argc < 5) {
            printf("Usage: image_processing <input_file> <output_file> bright <brightness_value>\n");
            exit(1);
        }
        int brightness = atoi(argv[4]);
        adjust_brightness(&img, brightness);
    } else if (strcmp(argv[3], "contrast") == 0) {
        if (argc < 5) {
            printf("Usage: image_processing <input_file> <output_file> contrast <contrast_value>\n");
            exit(1);
        }
        float contrast = atof(argv[4]);
        adjust_contrast(&img, contrast);
    } else {
        printf("Invalid image processing technique\n");
        exit(1);
    }

    // write output image file
    write_image(argv[2], &img);

    return 0;
}