//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LEN 1000

// Function to compute the hash value of a block of data
uint32_t computeHashValue(uint8_t* data, uint32_t len) {
    uint32_t hashValue = 0;
    for (uint32_t i = 0; i < len; i++) {
        hashValue += data[i] * (i+1);
    }
    return hashValue;
}

// Function to embed a watermark in an image using LSB method
void embedWatermark(uint8_t* image, uint32_t imageSize, uint8_t* watermark, uint32_t watermarkSize) {
    uint32_t imageIndex = 0, watermarkIndex = 0;
    while (watermarkIndex < watermarkSize) {
        for (int i = 7; i >= 0; i--) {
            if (watermark[watermarkIndex] & (1 << i)) {
                image[imageIndex] |= 1;
            }
            else {
                image[imageIndex] &= ~1;
            }
            imageIndex++;
        }
        watermarkIndex++;
    }
}

// Function to extract a watermark from an image using LSB method
void extractWatermark(uint8_t* image, uint32_t imageSize, uint8_t* watermark, uint32_t watermarkSize) {
    uint32_t imageIndex = 0, watermarkIndex = 0;
    while (watermarkIndex < watermarkSize) {
        uint8_t byte = 0;
        for (int i = 7; i >= 0; i--) {
            if (image[imageIndex] & 1) {
                byte |= (1 << i);
            }
            imageIndex++;
        }
        watermark[watermarkIndex] = byte;
        watermarkIndex++;
    }
}

int main() {
    FILE* imageFile = fopen("input.bmp", "rb");
    if (!imageFile) {
        printf("Failed to open image file\n");
        return 1;
    }

    // Read bitmap header
    uint8_t bmpHeader[54];
    fread(bmpHeader, 1, 54, imageFile);

    // Read image data
    uint8_t image[MAX_LEN];
    uint32_t bytesRead = fread(image, 1, MAX_LEN, imageFile);
    fclose(imageFile);

    // Compute hash value and embed watermark
    uint8_t watermark[] = "Hello, world!";
    uint32_t watermarkSize = sizeof(watermark);
    uint32_t hashValue = computeHashValue(image, bytesRead);
    uint8_t hashValueBytes[4];
    for (int i = 0; i < 4; i++) {
        hashValueBytes[i] = (hashValue >> (8*i)) & 0xFF;
    }
    uint8_t watermarkWithHash[MAX_LEN];
    memcpy(watermarkWithHash, hashValueBytes, 4);
    memcpy(watermarkWithHash + 4, watermark, watermarkSize);
    embedWatermark(image, bytesRead, watermarkWithHash, watermarkSize + 4);

    // Write watermarked image to file
    FILE* watermarkedFile = fopen("watermarked.bmp", "wb");
    if (!watermarkedFile) {
        printf("Failed to create watermarked file\n");
        return 1;
    }
    fwrite(bmpHeader, 1, 54, watermarkedFile);
    fwrite(image, 1, bytesRead, watermarkedFile);
    fclose(watermarkedFile);

    // Extract watermark from watermarked image
    FILE* watermarkedImageFile = fopen("watermarked.bmp", "rb");
    if (!watermarkedImageFile) {
        printf("Failed to open watermarked file\n");
        return 1;
    }
    fread(bmpHeader, 1, 54, watermarkedImageFile);
    bytesRead = fread(image, 1, MAX_LEN, watermarkedImageFile);
    fclose(watermarkedImageFile);

    uint8_t extractedWatermark[MAX_LEN];
    extractWatermark(image, bytesRead, extractedWatermark, watermarkSize + 4);
    uint32_t extractedHashValue = *(uint32_t*)extractedWatermark;
    if (computeHashValue(image, bytesRead) != extractedHashValue) {
        printf("Watermark verification failed\n");
        return 1;
    }
    printf("Extracted watermark: %s\n", extractedWatermark + 4);

    return 0;
}