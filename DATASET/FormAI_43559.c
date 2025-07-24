//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void setWatermark(int **image, int **watermark, int wmRows, int wmCols, int xPos, int yPos);
void printImage(int **image);

int main() {
    int image[ROWS][COLS];
    int *imagePtr[ROWS];
    for(int i = 0; i < ROWS; i++) {
        imagePtr[i] = image[i];
    }

    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            image[i][j] = rand() % 256;
        }
    }

    printf("Original Image:\n");
    printImage(imagePtr);

    int watermark[3][3] = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };
    int *watermarkPtr[3];
    for(int i = 0; i < 3; i++) {
        watermarkPtr[i] = watermark[i];
    }

    int xPos = rand() % 8;
    int yPos = rand() % 8;

    setWatermark(imagePtr, watermarkPtr, 3, 3, xPos, yPos);

    printf("\nWatermarked Image:\n");
    printImage(imagePtr);

    return 0;
}

void setWatermark(int **image, int **watermark, int wmRows, int wmCols, int xPos, int yPos) {
    for(int i = 0; i < wmRows; i++) {
        for(int j = 0; j < wmCols; j++) {
            image[xPos+i][yPos+j] += watermark[i][j];
        }
    }
}

void printImage(int **image) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }
}