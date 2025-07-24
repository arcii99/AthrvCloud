//FormAI DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>

#define WIDTH 512
#define HEIGHT 512

/* Function to apply grayscale effect to image */
void grayscale(unsigned char *image) {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            int index = (i * WIDTH + j) * 3;
            unsigned char r = image[index];
            unsigned char g = image[index + 1];
            unsigned char b = image[index + 2];

            unsigned char gray = (r + g + b) / 3;

            image[index] = gray;
            image[index + 1] = gray;
            image[index + 2] = gray;
        }
    }
}

/* Function to apply invert effect to image */
void invert(unsigned char *image) {
    int i, j;

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            int index = (i * WIDTH + j) * 3;
            unsigned char r = image[index];
            unsigned char g = image[index + 1];
            unsigned char b = image[index + 2];

            image[index] = 255 - r;
            image[index + 1] = 255 - g;
            image[index + 2] = 255 - b;
        }
    }
}

/* Function to write image data to file */
void writeImage(unsigned char *image, const char *filename) {
    FILE *fp;
    int filesize = 54 + 3 * WIDTH * HEIGHT;

    unsigned char header[54] = {
        0x42, 0x4d, 0x36, 0x00, 0x0c, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, (WIDTH & 0xff), (WIDTH >> 8 & 0xff), (WIDTH >> 16 & 0xff), (WIDTH >> 24 & 0xff),
        (HEIGHT & 0xff), (HEIGHT >> 8 & 0xff), (HEIGHT >> 16 & 0xff), (HEIGHT >> 24 & 0xff),
        0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x0c, 0x00, 0x13, 0x0b, 0x00, 0x00,
        0x13, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    fp = fopen(filename, "wb");

    fwrite(header, sizeof(unsigned char), 54, fp);
    fwrite(image, sizeof(unsigned char), 3 * WIDTH * HEIGHT, fp);

    fclose(fp);
}

int main() {
    unsigned char image[WIDTH * HEIGHT * 3];

    /* Load image data from file */
    FILE *fp;
    fp = fopen("input.bmp", "rb");
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    /* Apply image effects */
    grayscale(image);
    writeImage(image, "grayscale.bmp");

    invert(image);
    writeImage(image, "invert.bmp");

    return 0;
}