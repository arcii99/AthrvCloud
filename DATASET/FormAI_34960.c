//FormAI DATASET v1.0 Category: Image Editor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel img[WIDTH][HEIGHT];

void randomNoise() {
    srand(time(NULL));
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            img[i][j].r = rand() % 255;
            img[i][j].g = rand() % 255;
            img[i][j].b = rand() % 255;
        }
    }
}

void grayscale() {
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            unsigned char gray = (img[i][j].r + img[i][j].g + img[i][j].b) / 3;
            img[i][j].r = gray;
            img[i][j].g = gray;
            img[i][j].b = gray;
        }
    }
}

void saveImage() {
    FILE *fp;
    fp = fopen("output.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<HEIGHT; j++) {
            fprintf(fp, "%d %d %d ", img[i][j].r, img[i][j].g, img[i][j].b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main() {
    randomNoise();
    grayscale();
    saveImage();
    return 0;
}