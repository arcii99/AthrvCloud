//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate binary representation of decimal number
void decimalToBinary(int decimalNum, int binaryArr[]) {
    int index = 0;
    while (decimalNum != 0) {
        binaryArr[index] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        index++;
    }
}

// Function to get decimal number from binary array
int binaryToDecimal(int binaryArr[]) {
    int decimalNum = 0;
    int power = 1;
    for (int i = 0; i < 8; i++) {
        decimalNum += binaryArr[i] * power;
        power *= 2;
    }
    return decimalNum;
}

// Function to add digital watermark to image
void addWatermark(unsigned char image[][8], int watermarkBits[], int watermarkLength) {
    int watermarkIndex = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int binaryArr[8] = {0};
            decimalToBinary(image[i][j], binaryArr);
            if (watermarkIndex < watermarkLength) {
                binaryArr[7] = watermarkBits[watermarkIndex];
                watermarkIndex++;
            }
            image[i][j] = binaryToDecimal(binaryArr);
        }
    }
}

// Function to extract digital watermark from image
void extractWatermark(unsigned char image[][8], int watermarkBits[], int watermarkLength) {
    int watermarkIndex = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int binaryArr[8] = {0};
            decimalToBinary(image[i][j], binaryArr);
            if (watermarkIndex < watermarkLength) {
                watermarkBits[watermarkIndex] = binaryArr[7];
                watermarkIndex++;
            }
        }
    }
}

int main() {
    // Initialize image
    unsigned char image[8][8] = {
        { 225,  83,  71,   3,  52,  67, 213, 244 },
        { 221,  46,  97, 209, 251, 234,  36, 246 },
        { 150,  30, 201,  31,  77,  46,  47,  36 },
        { 168, 217, 173, 144,  50, 181, 251, 126 },
        { 209, 253,  79,  73, 215, 111, 118,  29 },
        {  34, 106,  12, 103, 205, 108,  38,  14 },
        { 139, 217,  94,  60,  55, 113,  68, 160 },
        { 156, 121,  57,  21,  44, 132,   6, 131 }
    };

    // Initialize watermark
    int watermarkLength = 32;
    int watermarkBits[32] = {1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0};
    
    // Add digital watermark
    addWatermark(image, watermarkBits, watermarkLength);

    // Extract digital watermark
    int extractedWatermark[32] = {0};
    extractWatermark(image, extractedWatermark, watermarkLength);

    // Check if extracted watermark is the same as the original watermark
    for (int i = 0; i < watermarkLength; i++) {
        if (watermarkBits[i] != extractedWatermark[i]) {
            printf("Error! Watermark not extracted correctly.\n");
            return 1;
        }
    }

    printf("Digital watermark added and extracted successfully.\n");

    return 0;
}