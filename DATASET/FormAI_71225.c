//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add the digital watermark
void addWatermark(unsigned char *imageData, const char *watermark) {
    // Calculate the length of the watermark
    int watermarkLength = strlen(watermark);

    // Loop through the image data
    for (int i = 0; i < 5000; i++) {
        // Loop through the watermark
        for (int j = 0; j < watermarkLength; j++) {
            // XOR the image data with the watermark character
            imageData[i+j] ^= watermark[j];
        }
    }
}

int main() {
    // Declare variables
    unsigned char imageData[5000];
    const char *watermark = "Two households, both alike in dignity";

    // Read the image data from a file
    FILE *file = fopen("image.bmp", "rb");
    fread(imageData, sizeof(unsigned char), 5000, file);
    fclose(file);

    // Add the digital watermark
    addWatermark(imageData, watermark);

    // Write the watermarked image data to a file
    FILE *outputFile = fopen("watermarked_image.bmp", "wb");
    fwrite(imageData, sizeof(unsigned char), 5000, outputFile);
    fclose(outputFile);

    return 0;
}