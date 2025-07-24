//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Function to embed the watermark in the image
void embedWatermark(int img[][COLS], int watermark[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (watermark[i][j] == 1) {
                img[i][j] |= 1; // bitwise OR operator to set the LSB to 1
            } else {
                img[i][j] &= ~1; // bitwise AND operator with NOT operator to set the LSB to 0
            }
        }
    }
}

// Function to extract the watermark from the image
void extractWatermark(int img[][COLS], int watermark[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            watermark[i][j] = img[i][j] & 1; // bitwise AND operator to extract the LSB
        }
    }
}

int main() {
    int img[ROWS][COLS] = {{0, 1, 2, 3, 4},
                           {5, 6, 7, 8, 9},
                           {10, 11, 12, 13, 14},
                           {15, 16, 17, 18, 19},
                           {20, 21, 22, 23, 24}};
    int watermark[ROWS][COLS] = {{1, 0, 1, 0, 1},
                                 {0, 1, 0, 1, 0},
                                 {1, 0, 1, 0, 1},
                                 {0, 1, 0, 1, 0},
                                 {1, 0, 1, 0, 1}};
                                 
    // Print original image
    printf("Original Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
    
    // Embed watermark in the image
    embedWatermark(img, watermark);
    
    // Print watermarked image
    printf("Watermarked Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
    
    // Extract watermark from the watermarked image
    int extractedWatermark[ROWS][COLS];
    extractWatermark(img, extractedWatermark);
    
    // Print extracted watermark
    printf("Extracted Watermark:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", extractedWatermark[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}