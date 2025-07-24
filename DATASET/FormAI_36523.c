//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 256

unsigned char image[MAX][MAX];

// function prototypes
void loadImage(const char* filename);
void saveImage(const char* filename);
void flipImage();
void adjustBrightness(int delta);
void adjustContrast(double factor);

int main()
{
    const char* filename = "image.raw";
    const char* outputFilename = "output.raw";

    loadImage(filename);

    // flip the image
    flipImage();

    // adjust the brightness and contrast
    adjustBrightness(50);
    adjustContrast(1.5);

    // save the modified image
    saveImage(outputFilename);

    return 0;
}

void loadImage(const char* filename)
{
    FILE* fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    fread(image, sizeof(unsigned char), MAX*MAX, fp);
    fclose(fp);
}

void saveImage(const char* filename)
{
    FILE* fp = fopen(filename, "wb");

    if(fp == NULL) {
        printf("Error: Unable to save image!\n");
        exit(1);
    }

    fwrite(image, sizeof(unsigned char), MAX*MAX, fp);
    fclose(fp);
}

void flipImage()
{
    unsigned char temp;
    int row, column;

    for(row = 0; row < MAX; row++) {
        for(column = 0; column < MAX/2; column++) {
            temp = image[row][column];
            image[row][column] = image[row][MAX-1-column];
            image[row][MAX-1-column] = temp;
        }
    }
}

void adjustBrightness(int delta)
{
    int row, column;

    for(row = 0; row < MAX; row++) {
        for(column = 0; column < MAX; column++) {
            int newPixel = image[row][column] + delta;

            if(newPixel < 0) {
                image[row][column] = 0;
            }
            else if(newPixel > 255) {
                image[row][column] = 255;
            }
            else {
                image[row][column] = newPixel;
            }
        }
    }
}

void adjustContrast(double factor)
{
    int row, column;

    for(row = 0; row < MAX; row++) {
        for(column = 0; column < MAX; column++) {
            int newPixel = (int)(factor * (image[row][column] - 127) + 127);

            if(newPixel < 0) {
                image[row][column] = 0;
            }
            else if(newPixel > 255) {
                image[row][column] = 255;
            }
            else {
                image[row][column] = newPixel;
            }
        }
    }
}