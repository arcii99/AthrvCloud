//FormAI DATASET v1.0 Category: Image Editor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 320
#define HEIGHT 240

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    char header[54];
    Pixel pixels[WIDTH * HEIGHT];
} BMPImage;

void readFile(const char* filename, BMPImage* image);
void writeFile(const char* filename, BMPImage* image);
void negativeEffect(BMPImage* image);
void noiseEffect(BMPImage* image);
void retroEffect(BMPImage* image);
void grayscaleEffect(BMPImage* image);

int main()
{
    BMPImage image;

    printf("Loading image...\n");
    readFile("image.bmp", &image);

    printf("Applying retro effect...\n");
    retroEffect(&image);

    printf("Applying grayscale effect...\n");
    grayscaleEffect(&image);

    printf("Applying negative effect...\n");
    negativeEffect(&image);

    printf("Applying noise effect...\n");
    noiseEffect(&image);

    printf("Saving image...\n");
    writeFile("new_image.bmp", &image);

    printf("Done!\n");
    return 0;
}

void readFile(const char* filename, BMPImage* image)
{
    FILE* file = fopen(filename, "rb");

    if (!file) {
        printf("Error: Could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    fread(image, sizeof(BMPImage), 1, file);
    fclose(file);
}

void writeFile(const char* filename, BMPImage* image)
{
    FILE* file = fopen(filename, "wb");

    if (!file) {
        printf("Error: Could not open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(image, sizeof(BMPImage), 1, file);
    fclose(file);
}

void negativeEffect(BMPImage* image)
{
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image->pixels[i].r = 255 - image->pixels[i].r;
        image->pixels[i].g = 255 - image->pixels[i].g;
        image->pixels[i].b = 255 - image->pixels[i].b;
    }
}

void noiseEffect(BMPImage* image)
{
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int random = rand() % 2;
        if (random == 1) {
            image->pixels[i].r = 0;
            image->pixels[i].g = 0;
            image->pixels[i].b = 0;
        }
    }
}

void retroEffect(BMPImage* image)
{
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image->pixels[i].r = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].g = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].b = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
    }
}

void grayscaleEffect(BMPImage* image)
{
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].r = gray;
        image->pixels[i].g = gray;
        image->pixels[i].b = gray;
    }
}