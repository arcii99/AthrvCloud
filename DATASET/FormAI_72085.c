//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of the input string
#define WATERMARK 0xAB // Watermark to be embedded in the data

// Function to print the binary representation of a byte
void printBinary(unsigned char c) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (c >> i) & 1);
    }
}

// Function to embed a watermark into the data
void embedWatermark(unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        // Shift the watermark to the LSB of the data byte
        unsigned char watermarkShifted = WATERMARK >> (i % 8);
        // Set the LSB of the data byte to the corresponding bit of the watermark
        data[i] = (data[i] & 0xFE) | (watermarkShifted & 0x01);
    }
}

// Function to extract the watermark from the data
unsigned char extractWatermark(unsigned char *data, int length) {
    unsigned char watermark = 0;
    for (int i = 0; i < length; i++) {
        // Extract the LSB of each byte and shift it to the corresponding bit of the watermark
        watermark |= (data[i] & 0x01) << (i % 8);
    }
    return watermark;
}

int main() {
    unsigned char data[MAX_LENGTH] = {0};
    printf("Enter the data to be watermarked (maximum length %d):\n", MAX_LENGTH - 1);
    fgets(data, MAX_LENGTH, stdin);
    // Remove the newline character added by fgets
    data[strcspn(data, "\n")] = '\0';
    printf("The input data is:\n");
    printf("%s\n", data);
    int length = strlen(data);
    embedWatermark(data, length);
    printf("The watermarked data is:\n");
    for (int i = 0; i < length; i++) {
        printBinary(data[i]);
        printf(" ");
    }
    printf("\n");
    unsigned char extractedWatermark = extractWatermark(data, length);
    printf("The extracted watermark is:\n");
    printBinary(extractedWatermark);
    printf("\n");
    return 0;
}