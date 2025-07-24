//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void read_image(Image* img, char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &img->width, &img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(f, "%c", &img->pixels[i][j]);
        }
    }

    fclose(f);
}

void write_image(Image* img, char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    fprintf(f, "%d %d\n", img->width, img->height);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(f, "%c", img->pixels[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

void flip_image(Image* img) {
    unsigned char temp_pixel;
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            temp_pixel = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[i][img->width - j - 1];
            img->pixels[i][img->width - j - 1] = temp_pixel;
        }
    }
}

void adjust_brightness(Image* img, int increment) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if (img->pixels[i][j] + increment < 0) {
                img->pixels[i][j] = 0;
            } else if (img->pixels[i][j] + increment > 255) {
                img->pixels[i][j] = 255;
            } else {
                img->pixels[i][j] += increment;
            }
        }
    }
}

void adjust_contrast(Image* img, float factor) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            float new_pixel = factor * (img->pixels[i][j] - 127.5) + 127.5;
            if (new_pixel < 0) {
                img->pixels[i][j] = 0;
            } else if (new_pixel > 255) {
                img->pixels[i][j] = 255;
            } else {
                img->pixels[i][j] = (unsigned char) new_pixel;
            }
        }
    }
}

int main() {
    char file_in[] = "input_image.txt";
    char file_out[] = "output_image.txt";
    Image img;
    read_image(&img, file_in);
    flip_image(&img);
    adjust_brightness(&img, 50);
    adjust_contrast(&img, 2.0);
    write_image(&img, file_out);
    return 0;
}