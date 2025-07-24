//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to embed the watermark
void embedWatermark(char *originalText, char *watermark) {
    // Calculate size of watermark and original text
    int watermarkSize = strlen(watermark);
    int originalTextSize = strlen(originalText);

    // Check if watermark size is bigger than original text size
    if (watermarkSize > originalTextSize) {
        printf("Cannot embed watermark, watermark size is bigger than original text");
        return;
    }

    // Loop through the original text and embed the watermark
    for (int i = 0; i < originalTextSize; i++) {
        // If watermark hasn't been fully embedded yet
        if (i < watermarkSize) {
            originalText[i] = watermark[i];
        } 
        // Otherwise, XOR the character with the corresponding watermark character
        else {
            originalText[i] ^= watermark[i % watermarkSize];
        }
    }

    printf("Watermark embedded successfully");
    printf("Embedded Output: %s\n", originalText);
}

// Function to extract the watermark
void extractWatermark(char *originalText, char *extractedWatermark, int extractedWatermarkSize) {
    // Calculate size of original text
    int originalTextSize = strlen(originalText);

    // Loop through the original text and extract the watermark
    for (int i = 0; i < originalTextSize; i++) {
        // If we're still in the watermark, add the character to the extracted watermark
        if (i < extractedWatermarkSize) {
            extractedWatermark[i] = originalText[i];
        }
        // Otherwise, XOR the character with the corresponding extracted watermark character
        else {
            extractedWatermark[i % extractedWatermarkSize] ^= originalText[i];
        }
    }

    printf("Watermark extracted successfully");
    printf("Extracted Output: %s\n", extractedWatermark);
}

// Main function
int main() {
    // Set up original text and watermark
    char originalText[50] = "Hello, world!";
    char watermark[15] = "Watermark123";

    // Embed watermark in the original text
    embedWatermark(originalText, watermark);

    // Extract watermark from the original text
    int extractedWatermarkSize = strlen(watermark);
    char extractedWatermark[extractedWatermarkSize];
    extractWatermark(originalText, extractedWatermark, extractedWatermarkSize);

    return 0;
}