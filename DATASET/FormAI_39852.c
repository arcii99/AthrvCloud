//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include<stdio.h>

// The size ranges from 0 to 255
#define MAX_SIZE 255

// Function to embed the watermark
void embedWatermark(char* data, char* watermark) {
    int dataLen = strlen(data);
    int watermarkLen = strlen(watermark);

    // Check if the data size is large enough to embed the watermark
    if (dataLen < (watermarkLen * 8)) {
        printf("Data size too small to embed watermark.");
        return;
    }

    int watermarkBitIndex = 0;

    // Embed the watermark bit by bit
    for (int i = 0; i < watermarkLen; i++) {
        char ch = watermark[i];

        // Embed each bit of the character ch
        for (int j = 7; j >= 0; j--) {
            char bit = (ch >> j) & 1;

            if (bit == 0) { // If bit is 0, set LSB to 0
                data[watermarkBitIndex] &= ~1;
            }
            else { // If bit is 1, set LSB to 1
                data[watermarkBitIndex] |= 1;
            }

            watermarkBitIndex++;
        }
    }
}

// Function to extract the watermark
void extractWatermark(char* data, int dataLen, int watermarkLen) {
    char watermark[MAX_SIZE];
    memset(watermark, 0, sizeof(watermark));

    int watermarkBitIndex = 0;

    // Extract the watermark bit by bit
    for (int i = 0; i < watermarkLen; i++) {
        char ch = 0;

        // Extract each bit of the character ch
        for (int j = 7; j >= 0; j--) {
            char bit = data[watermarkBitIndex] & 1;

            // Set the j-th bit of ch to the extracted bit
            ch |= (bit << j);

            watermarkBitIndex++;
        }

        watermark[i] = ch;
    }

    // Print the extracted watermark
    printf("Extracted watermark: %s", watermark);
}

int main() {
    // Demo data and watermark
    char data[MAX_SIZE] = "This is a demo of digital watermarking in C programming language.";
    char watermark[MAX_SIZE] = "Embedded by John Doe";

    // Embed the watermark in the data
    embedWatermark(data, watermark);

    // Extract the watermark from the data
    extractWatermark(data, strlen(data), strlen(watermark));

    return 0;
}