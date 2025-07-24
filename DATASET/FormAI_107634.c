//FormAI DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IMG_WIDTH 10
#define IMG_HEIGHT 10

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

void printImg(Pixel img[IMG_HEIGHT][IMG_WIDTH]);
void invertColors(Pixel img[IMG_HEIGHT][IMG_WIDTH]);
void shiftColorsLeft(Pixel img[IMG_HEIGHT][IMG_WIDTH]);
void shiftColorsRight(Pixel img[IMG_HEIGHT][IMG_WIDTH]);
void swapColors(Pixel* p1, Pixel* p2);
void psychedelicColors(Pixel img[IMG_HEIGHT][IMG_WIDTH]);
void randomizedColors(Pixel img[IMG_HEIGHT][IMG_WIDTH]);

int main() {
    Pixel img[IMG_HEIGHT][IMG_WIDTH];

    // Initialize the image with random colors
    randomizedColors(img);

    // Print the image before any modifications
    printf("Original Image:\n");
    printImg(img);

    // Negative Filter - Invert the colors
    printf("\nInverting Colors:\n");
    invertColors(img);
    printImg(img);

    // Shift Filter - Shift colors left
    printf("\nShifting Colors Left:\n");
    shiftColorsLeft(img);
    printImg(img);

    // Randomize Filter - Randomize the colors
    printf("\nRandomizing Colors:\n");
    randomizedColors(img);
    printImg(img);

    // Swap Filter - Swap the colors of two pixels
    printf("\nSwapping Colors:\n");
    swapColors(&img[0][0], &img[IMG_HEIGHT-1][IMG_WIDTH-1]);
    printImg(img);

    // Shift Filter - Shift the colors right
    printf("\nShifting Colors Right:\n");
    shiftColorsRight(img);
    printImg(img);

    // Psychedelic Filter - Modify the colors to create a surreal effect
    printf("\nCreating Psychedelic Effect:\n");
    psychedelicColors(img);
    printImg(img);

    printf("\nDone!");
    return 0;
}

void printImg(Pixel img[IMG_HEIGHT][IMG_WIDTH]) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            printf("(%d,%d,%d) ", img[i][j].r, img[i][j].g, img[i][j].b);
        }
        printf("\n");
    }
}

void invertColors(Pixel img[IMG_HEIGHT][IMG_WIDTH]) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            img[i][j].r = 255 - img[i][j].r;
            img[i][j].b = 255 - img[i][j].b;
            img[i][j].g = 255 - img[i][j].g;
        }
    }
}

void shiftColorsLeft(Pixel img[IMG_HEIGHT][IMG_WIDTH]) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        Pixel tmp = img[i][0];
        for (int j = 0; j < IMG_WIDTH-1; j++) {
            img[i][j] = img[i][j+1];
        }
        img[i][IMG_WIDTH-1] = tmp;
    }
}

void shiftColorsRight(Pixel img[IMG_HEIGHT][IMG_WIDTH]) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        Pixel tmp = img[i][IMG_WIDTH-1];
        for (int j = IMG_WIDTH-1; j > 0; j--) {
            img[i][j] = img[i][j-1];
        }
        img[i][0] = tmp;
    }
}

void swapColors(Pixel* p1, Pixel* p2) {
    Pixel tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void psychedelicColors(Pixel img[IMG_HEIGHT][IMG_WIDTH]) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            img[i][j].r = (img[i][j].r + img[i][j].g + img[i][j].b) / 3;
            img[i][j].g = (img[i][j].r + img[i][j].b) / 2;
            img[i][j].b = (img[i][j].g + img[i][j].b) / 2;
        }
    }
}

void randomizedColors(Pixel img[IMG_HEIGHT][IMG_WIDTH]) {
    for (int i = 0; i < IMG_HEIGHT; i++) {
        for (int j = 0; j < IMG_WIDTH; j++) {
            img[i][j].r = rand() % 256;
            img[i][j].g = rand() % 256;
            img[i][j].b = rand() % 256;
        }
    }
}