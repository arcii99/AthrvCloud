//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdint.h>

#define MAX_LEN 100 // Maximum length of the input message
#define WATERMARK_SIZE 16 // Size of the watermark in bytes
#define WATERMARK_BYTE_OFFSET 5 // Offset from the start of the input message to embed the watermark
#define WATERMARK_BIT_OFFSET 3 // Offset in bits within the given byte to embed the watermark

// Function to embed the watermark into the input message
void embedWatermark(uint8_t *inputMsg, uint8_t *watermark) {
    // Calculate the total number of bits in the watermark
    int watermarkBitCount = 8 * WATERMARK_SIZE;
    // Store the watermark bit count in the first byte of the input message
    inputMsg[0] = (uint8_t)(watermarkBitCount & 0xFF);
    // Embed the watermark into the input message by iterating over each bit of the watermark
    int inputByteIndex = WATERMARK_BYTE_OFFSET;
    int inputBitIndex = WATERMARK_BIT_OFFSET;
    for (int i = 0; i < watermarkBitCount; i++) {
        // Get the current bit from the watermark
        int watermarkBit = (watermark[i / 8] >> (7 - (i % 8))) & 1;
        // Embed the current bit into the input message
        inputMsg[inputByteIndex] |= watermarkBit << (7 - inputBitIndex);
        // Increment the input bit index
        inputBitIndex++;
        // Check if we have reached the end of a byte
        if (inputBitIndex == 8) {
            // Move to the next byte in the input message
            inputByteIndex++;
            inputBitIndex = 0;
        }
    }
}

// Function to extract the watermark from the input message
void extractWatermark(uint8_t *inputMsg, uint8_t *watermark) {
    // Get the watermark bit count from the first byte of the input message
    int watermarkBitCount = inputMsg[0];
    // Extract the watermark from the input message by iterating over each bit of the watermark
    int inputByteIndex = WATERMARK_BYTE_OFFSET;
    int inputBitIndex = WATERMARK_BIT_OFFSET;
    for (int i = 0; i < watermarkBitCount; i++) {
        // Get the current bit from the input message
        int inputBit = (inputMsg[inputByteIndex] >> (7 - inputBitIndex)) & 1;
        // Embed the current bit into the watermark
        watermark[i / 8] |= inputBit << (7 - (i % 8));
        // Increment the input bit index
        inputBitIndex++;
        // Check if we have reached the end of a byte
        if (inputBitIndex == 8) {
            // Move to the next byte in the input message
            inputByteIndex++;
            inputBitIndex = 0;
        }
    }
}

int main() {
    // Input message
    uint8_t inputMsg[MAX_LEN] = "Digital watermarking example program";
    // Watermark
    uint8_t watermark[WATERMARK_SIZE] = "Watermark12345678";
    // Embed the watermark into the input message
    embedWatermark(inputMsg, watermark);
    // Extract the watermark from the input message
    uint8_t extractedWatermark[WATERMARK_SIZE] = {0};
    extractWatermark(inputMsg, extractedWatermark);
    // Print the extracted watermark
    printf("Extracted Watermark: %s\n", extractedWatermark);
    return 0;
}