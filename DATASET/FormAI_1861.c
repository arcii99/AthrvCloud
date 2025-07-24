//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: irregular
#include <stdio.h>
#include <stdlib.h>


#define MAX_IMAGE_SIZE 1024
#define MAX_PIXEL_SIZE 255


typedef struct {
    int height;
    int width;
    int pixel[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;


void flipImageHorizontally(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            int temp = img->pixel[i][j];
            img->pixel[i][j] = img->pixel[i][img->width - j - 1];
            img->pixel[i][img->width - j - 1] = temp;
        }
    }
}


void flipImageVertically(Image* img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            int temp = img->pixel[i][j];
            img->pixel[i][j] = img->pixel[img->height - i - 1][j];
            img->pixel[img->height - i - 1][j] = temp;
        }
    }
}


void changeBrightness(Image* img, int brightness) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixel[i][j] += brightness;
            if (img->pixel[i][j] > MAX_PIXEL_SIZE) {
                img->pixel[i][j] = MAX_PIXEL_SIZE;
            } else if (img->pixel[i][j] < 0) {
                img->pixel[i][j] = 0;
            }
        }
    }
}


void changeContrast(Image* img, float contrast) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixel[i][j] = (int)((img->pixel[i][j] - 128) * contrast + 128);
            if (img->pixel[i][j] > MAX_PIXEL_SIZE) {
                img->pixel[i][j] = MAX_PIXEL_SIZE;
            } else if (img->pixel[i][j] < 0) {
                img->pixel[i][j] = 0;
            }
        }
    }
}


void printImage(Image img) {
    printf("Height: %d, Width: %d\n", img.height, img.width);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            printf("%3d ", img.pixel[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int brightness = 50;
    float contrast = 1.5;

    Image img;
    img.height = 3;
    img.width = 4;
    img.pixel[0][0] = 40;
    img.pixel[0][1] = 80;
    img.pixel[0][2] = 120;
    img.pixel[0][3] = 160;
    img.pixel[1][0] = 200;
    img.pixel[1][1] = 180;
    img.pixel[1][2] = 140;
    img.pixel[1][3] = 100;
    img.pixel[2][0] = 60;
    img.pixel[2][1] = 100;
    img.pixel[2][2] = 140;
    img.pixel[2][3] = 180;

    printf("Original image:\n");
    printImage(img);

    printf("\nFlipped horizontally:\n");
    flipImageHorizontally(&img);
    printImage(img);

    printf("\nFlipped vertically:\n");
    flipImageVertically(&img);
    printImage(img);

    printf("\nIncreased brightness by %d:\n", brightness);
    changeBrightness(&img, brightness);
    printImage(img);

    printf("\nIncreased contrast by %.2f:\n", contrast);
    changeContrast(&img, contrast);
    printImage(img);

    return 0;
}