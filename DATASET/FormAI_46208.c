//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000

typedef enum { FLIP_HORIZONTAL, FLIP_VERTICAL } flip_type;

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE][3];
} image;

// function prototypes
void process_image(image *img);
void flip_image(image *img, flip_type flip);
void change_brightness(image *img, float brightness_factor);
void change_contrast(image *img, float contrast_factor);

int main() {
    image img;
    char filename[100];
    printf("Enter the filename of the image: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char format[3];
    int width, height, maxval;
    fscanf(fp, "%s\n%d %d\n%d\n", format, &width, &height, &maxval);
    if (strcmp(format, "P6") != 0) {
        printf("Error: Invalid file format.\n");
        return 1;
    }
    if (width > MAX_IMAGE_SIZE || height > MAX_IMAGE_SIZE) {
        printf("Error: Image too large.\n");
        return 1;
    }
    img.width = width;
    img.height = height;
    fread(img.pixels, sizeof(unsigned char), width*height*3, fp);
    fclose(fp);
    process_image(&img);
    return 0;
}

void process_image(image *img) {
    int choice, flip;
    float brightness, contrast;
    printf("Enter the choice of operation to perform:\n");
    printf("1. Flip horizontally\n");
    printf("2. Flip vertically\n");
    printf("3. Change brightness\n");
    printf("4. Change contrast\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            flip_image(img, FLIP_HORIZONTAL);
            break;
        case 2:
            flip_image(img, FLIP_VERTICAL);
            break;
        case 3:
            printf("Enter the brightness factor: ");
            scanf("%f", &brightness);
            change_brightness(img, brightness);
            break;
        case 4:
            printf("Enter the contrast factor: ");
            scanf("%f", &contrast);
            change_contrast(img, contrast);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    printf("Enter 1 to continue or 0 to quit: ");
    int cont;
    scanf("%d", &cont);
    if (cont) {
        process_image(img);
    }
}

void flip_image(image *img, flip_type flip) {
    int i, j, k;
    image tmp = *img;
    for (i = 0; i < tmp.width; i++) {
        for (j = 0; j < tmp.height; j++) {
            for (k = 0; k < 3; k++) {
                if (flip == FLIP_HORIZONTAL) {
                    img->pixels[i][j][k] = tmp.pixels[tmp.width - i - 1][j][k];
                } else if (flip == FLIP_VERTICAL) {
                    img->pixels[i][j][k] = tmp.pixels[i][tmp.height - j - 1][k];
                }
            }
        }
    }
}

void change_brightness(image *img, float brightness_factor) {
    int i, j, k;
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            for (k = 0; k < 3; k++) {
                int pixel_value = (int)img->pixels[i][j][k] * brightness_factor;
                if (pixel_value > 255) {
                    pixel_value = 255;
                }
                img->pixels[i][j][k] = (unsigned char)pixel_value;
            }
        }
    }
}

void change_contrast(image *img, float contrast_factor) {
    int i, j, k;
    float mean = 0;
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            for (k = 0; k < 3; k++) {
                mean += img->pixels[i][j][k];
            }
        }
    }
    mean /= (float)(img->width * img->height * 3);
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            for (k = 0; k < 3; k++) {
                int pixel_value = (int)(contrast_factor * (img->pixels[i][j][k] - mean) + mean);
                if (pixel_value > 255) {
                    pixel_value = 255;
                } else if (pixel_value < 0) {
                    pixel_value = 0;
                }
                img->pixels[i][j][k] = (unsigned char)pixel_value;
            }
        }
    }
}