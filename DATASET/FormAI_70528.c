//FormAI DATASET v1.0 Category: Image compression ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    Pixel pixels[MAX_HEIGHT][MAX_WIDTH];
    int height;
    int width;
} Image;

/* Function to compress an image */
void compressImage(Image *originalImage, Image *compressedImage) {
    int i, j;
    Pixel currentPixel, previousPixel;
    int count;

    compressedImage->height = originalImage->height;
    compressedImage->width = originalImage->width;

    for (i = 0; i < originalImage->height; i++) {
        for (j = 0; j < originalImage->width; j++) {
            currentPixel = originalImage->pixels[i][j];

            if (j == 0) {
                compressedImage->pixels[i][0] = currentPixel;
            }
            else {
                previousPixel = originalImage->pixels[i][j-1];

                if (currentPixel.red == previousPixel.red &&
                    currentPixel.green == previousPixel.green &&
                    currentPixel.blue == previousPixel.blue) {
                    /* Pixel is the same as previous pixel, increment count */
                    count++;
                }
                else {
                    /* Pixel is different than previous pixel, store previous pixel and count */
                    compressedImage->pixels[i][j-count] = previousPixel;
                    compressedImage->pixels[i][j-count+1].red = count;
                    compressedImage->pixels[i][j-count+1].green = count;
                    compressedImage->pixels[i][j-count+1].blue = count;
                    compressedImage->pixels[i][j-count+2] = currentPixel;
                    count = 0;
                }
            }
        }

        /* End of row, store last pixel and count */
        if (count > 0) {
            compressedImage->pixels[i][j-count] = previousPixel;
            compressedImage->pixels[i][j-count+1].red = count;
            compressedImage->pixels[i][j-count+1].green = count;
            compressedImage->pixels[i][j-count+1].blue = count;
        }
        else {
            compressedImage->pixels[i][j-1] = currentPixel;
        }

        /* Reset count for next row */
        count = 0;
    }
}

int main() {
    Image originalImage;
    Image compressedImage;
    int i, j;

    /* Fill original image with random pixel values */
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            originalImage.pixels[i][j].red = rand() % (MAX_PIXEL_VALUE + 1);
            originalImage.pixels[i][j].green = rand() % (MAX_PIXEL_VALUE + 1);
            originalImage.pixels[i][j].blue = rand() % (MAX_PIXEL_VALUE + 1);
        }
    }
    originalImage.height = MAX_HEIGHT;
    originalImage.width = MAX_WIDTH;

    /* Compress the image */
    compressImage(&originalImage, &compressedImage);

    /* Display original image */
    printf("Original Image:\n");
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            printf("(%d, %d, %d) ", originalImage.pixels[i][j].red,
                originalImage.pixels[i][j].green, originalImage.pixels[i][j].blue);
        }
        printf("\n");
    }

    /* Display compressed image */
    printf("\nCompressed Image:\n");
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            if (compressedImage.pixels[i][j].red == 0 &&
                compressedImage.pixels[i][j].green == 0 &&
                compressedImage.pixels[i][j].blue == 0) {
                /* End of row, break line */
                printf("\n");
                break;
            }
            else if (compressedImage.pixels[i][j].red == compressedImage.pixels[i][j].green &&
                compressedImage.pixels[i][j].green == compressedImage.pixels[i][j].blue) {
                /* Same pixel as previous pixel, print count */
                printf("%dx (%d, %d, %d) ", compressedImage.pixels[i][j].red,
                    compressedImage.pixels[i][j+1].red, compressedImage.pixels[i][j+1].green,
                    compressedImage.pixels[i][j+1].blue);
                j++;
            }
            else {
                /* Different pixel than previous pixel, print pixel */
                printf("(%d, %d, %d) ", compressedImage.pixels[i][j].red,
                    compressedImage.pixels[i][j].green, compressedImage.pixels[i][j].blue);
            }
        }
    }

    return 0;
}