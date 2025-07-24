//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>

#define WIDTH  640
#define HEIGHT 480

unsigned char image[HEIGHT][WIDTH];

void flip(unsigned char img[HEIGHT][WIDTH]) {
    for(int y = 0; y < HEIGHT/2; y++) {
        for(int x = 0; x < WIDTH; x++) {
            unsigned char temp = img[y][x];
            img[y][x] = img[HEIGHT-1-y][x];
            img[HEIGHT-1-y][x] = temp;
        }
    }
}

void adjustBrightness(unsigned char img[HEIGHT][WIDTH], int level) {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            int pixel = img[y][x] + level;
            if(pixel < 0) {
                pixel = 0;
            } else if(pixel > 255) {
                pixel = 255;
            }
            img[y][x] = (unsigned char) pixel;
        }
    }
}

void adjustContrast(unsigned char img[HEIGHT][WIDTH], double factor) {
    double avg = 0;
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            avg += img[y][x];
        }
    }
    avg /= HEIGHT * WIDTH;
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            int pixel = (int) ((img[y][x] - avg) * factor + avg + 0.5);
            if(pixel < 0) {
                pixel = 0;
            } else if(pixel > 255) {
                pixel = 255;
            }
            img[y][x] = (unsigned char) pixel;
        }
    }
}

int main() {
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            image[y][x] = (unsigned char) (y % 256);
        }
    }
    flip(image);
    adjustBrightness(image, -50);
    adjustContrast(image, 1.5);
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%u ", image[y][x]);
        }
        printf("\n");
    }
    return 0;
}