//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>

#define HEIGHT 10
#define WIDTH 10

void flip_image(int img[HEIGHT][WIDTH]) {
    int temp_row[WIDTH];
    for(int i=0; i<HEIGHT/2; i++) {
        // Copy top row to temporary buffer
        for(int j=0; j<WIDTH; j++) {
            temp_row[j] = img[i][j];
        }
        // Copy bottom row to top row
        for(int j=0; j<WIDTH; j++) {
            img[i][j] = img[HEIGHT-i-1][j];
        }
        // Copy temporary buffer to bottom row
        for(int j=0; j<WIDTH; j++) {
            img[HEIGHT-i-1][j] = temp_row[j];
        }
    }
}

void adjust_brightness_contrast(int img[HEIGHT][WIDTH], int brightness, int contrast) {
    // Adjust brightness
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            img[i][j] += brightness;
        }
    }
    // Adjust contrast
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            img[i][j] = (int)(factor * (img[i][j] - 128) + 128);
        }
    }
}

int main() {
    // Initialize image
    int img[HEIGHT][WIDTH];
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            img[i][j] = i * WIDTH + j;
        }
    }
    // Flip image
    flip_image(img);
    // Adjust brightness and contrast
    adjust_brightness_contrast(img, -50, 100);
    // Print image
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%3d ", img[i][j]);
        }
        printf("\n");
    }
    return 0;
}