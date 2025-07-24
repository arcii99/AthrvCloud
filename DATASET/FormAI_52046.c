//FormAI DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} PIXEL;

PIXEL image[WIDTH][HEIGHT];

void drawRectangle(int x, int y, int width, int height, PIXEL color) {
    int i, j;
    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            image[i][j] = color;
        }
    }
}

void drawCircle(int x, int y, int radius, PIXEL color) {
    int i, j;
    for (i = x - radius; i < x + radius; i++) {
        for (j = y - radius; j < y + radius; j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
                image[i][j] = color;
            }
        }
    }
}

void invertColors() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image[i][j].r = 255 - image[i][j].r;
            image[i][j].g = 255 - image[i][j].g;
            image[i][j].b = 255 - image[i][j].b;
        }
    }
}

int main() {
    int i, j;
    PIXEL backgroundColor = {255, 255, 255};
    PIXEL redColor = {255, 0, 0};
    PIXEL greenColor = {0, 255, 0};
    PIXEL blueColor = {0, 0, 255};

    // Initialization of the image with white background
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            image[i][j] = backgroundColor;
        }
    }

    drawRectangle(50, 50, 100, 150, redColor);
    drawRectangle(200, 100, 75, 75, greenColor);
    drawCircle(400, 300, 50, blueColor);

    invertColors();

    // Writing the image to a file
    FILE *fp;
    fp = fopen("output.ppm", "wb");
    fprintf(fp, "P6 %d %d 255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(image), 1, fp);
    fclose(fp);

    return 0;
}