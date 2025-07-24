//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// define image dimensions
#define ROWS 5
#define COLS 5

// define image struct
typedef struct {
    int pixels[ROWS][COLS];
} Image;

// define functions for image processing
void flip(Image *img) {
    int temp;
    for (int i = 0; i < ROWS / 2; i++) {
        for (int j = 0; j < COLS; j++) {
            temp = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[ROWS - 1 - i][j];
            img->pixels[ROWS - 1 - i][j] = temp;
        }
    }
}

void changeBrightness(Image *img, int brightness) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            img->pixels[i][j] += brightness;
            if (img->pixels[i][j] < 0) {
                img->pixels[i][j] = 0;
            } else if (img->pixels[i][j] > 255) {
                img->pixels[i][j] = 255;
            }
        }
    }
}

void changeContrast(Image *img, int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double pixel = img->pixels[i][j];
            img->pixels[i][j] = factor * (pixel - 128.0) + 128.0;
            if (img->pixels[i][j] < 0) {
                img->pixels[i][j] = 0;
            } else if (img->pixels[i][j] > 255) {
                img->pixels[i][j] = 255;
            }
        }
    }
}

int main() {
    // initialize image
    Image img = {
        {{255, 20, 150, 180, 100},
         {200, 120, 50, 255, 0},
         {50, 255, 0, 100, 220},
         {180, 100, 200, 120, 255},
         {100, 255, 80, 40, 150}}
    };
    
    // flip image horizontally
    flip(&img);
    
    // change brightness of image
    changeBrightness(&img, 50);
    
    // change contrast of image
    changeContrast(&img, 50);
    
    // print modified image
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", img.pixels[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}