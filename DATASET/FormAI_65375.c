//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_ITERATIONS 1000
#define BAILOUT 16.0

float getRandom() {
    return ((float)rand()) / RAND_MAX;
}

int mandelbrot(float cx, float cy) {
    float zx = 0.0, zy = 0.0;
    int i = 0;

    while (i < MAX_ITERATIONS && zx * zx + zy * zy < BAILOUT * BAILOUT) {
        float xtemp = zx * zx - zy * zy + cx;
        zy = 2.0 * zx * zy + cy;
        zx = xtemp;
        i++;
    }

    if (i == MAX_ITERATIONS) {
        return 0;
    }
    else {
        return i;
    }
}

void generateFractal(char* filename) {
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    srand(time(NULL));

    float centerX = getRandom() * 3.0 - 2.0;
    float centerY = getRandom() * 3.0 - 2.0;
    float scale = getRandom() * 0.1 + 0.1;

    unsigned char header[] = {
        0x42, 0x4D, 0x36, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00
    };

    fwrite(header, sizeof(unsigned char), sizeof(header), file);

    unsigned char* imageData = calloc(WIDTH * HEIGHT * 3, sizeof(unsigned char));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            float cx = centerX + ((float)x - WIDTH / 2) / scale / WIDTH;
            float cy = centerY + ((float)y - HEIGHT / 2) / scale / HEIGHT;

            int value = mandelbrot(cx, cy);

            if (value == 0) {
                imageData[(y * WIDTH + x) * 3] = 255;
                imageData[(y * WIDTH + x) * 3 + 1] = 255;
                imageData[(y * WIDTH + x) * 3 + 2] = 255;
            }
            else {
                float r = getRandom();
                float g = getRandom();
                float b = getRandom();

                imageData[(y * WIDTH + x) * 3] = value % 2 == 0 ? (int)(r * 255) : 0;
                imageData[(y * WIDTH + x) * 3 + 1] = value % 2 == 0 ? (int)(g * 255) : 0;
                imageData[(y * WIDTH + x) * 3 + 2] = value % 2 == 0 ? (int)(b * 255) : 0;
            }
        }
    }

    fwrite(imageData, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);

    fclose(file);

    printf("Fractal generated successfully!\n");
}

int main() {
    generateFractal("fractal.bmp");
    return 0;
}