//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void flip_image(int image[][COLS]) {
    int temp;
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS/2; c++) {
            temp = image[r][c];
            image[r][c] = image[r][COLS-c-1];
            image[r][COLS-c-1] = temp;
        }
    }
}

void adjust_brightness_contrast(int image[][COLS], int brightness, int contrast) {
    int temp;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            temp = factor * (image[r][c] - 128) + 128 + brightness;
            if(temp < 0) {
                temp = 0;
            } else if(temp > 255) {
                temp = 255;
            }
            image[r][c] = temp;
        }
    }
}

int main() {
    int image[ROWS][COLS] = {
        {100, 120, 255},
        {50, 80, 160},
        {70, 90, 200}
    };
    
    printf("Original Image:\n");
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%d ", image[r][c]);
        }
        printf("\n");
    }
    
    flip_image(image);
    
    printf("\nFlipped Image:\n");
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%d ", image[r][c]);
        }
        printf("\n");
    }
    
    adjust_brightness_contrast(image, 50, 50);
    
    printf("\nAdjusted Image:\n");
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%d ", image[r][c]);
        }
        printf("\n");
    }

    return 0;
}