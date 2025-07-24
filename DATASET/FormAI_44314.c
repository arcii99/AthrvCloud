//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_DATA_SIZE 1024

// Function to embed the watermark in the input data
void embed_watermark(uint8_t* data, uint8_t* watermark) {
    int i, j;
    uint8_t mask = 0x01; // mask to bitwise operations

    for (i = 0; i < 8; i++) {
        for (j = 0; j < MAX_DATA_SIZE; j++) {
            // Embed the current bit of watermark into the least significant bit of data
            data[j] = (data[j] & ~mask) | ((watermark[i] & mask) << i);
        }
        mask = mask << 1; // shift the mask to the left
    }
}

// Function to extract the embedded watermark from the input data
void extract_watermark(uint8_t* data, uint8_t* watermark) {
    int i, j;
    uint8_t mask = 0x01; // mask to bitwise operations
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < MAX_DATA_SIZE; j++) {
            // Extract the least significant bit of data into the current bit of watermark
            watermark[i] = watermark[i] | ((data[j] & mask) >> i);
        }
        mask = mask << 1; // shift the mask to the left
    }
}

int main() {
    uint8_t data[MAX_DATA_SIZE];
    uint8_t watermark[8];
    memset(data, 0, MAX_DATA_SIZE);
    memset(watermark, 0, 8);

    // Read input data and watermark from files
    FILE* data_file = fopen("input.data", "rb");
    if (!data_file) {
        printf("Error: cannot open input.data file\n");
        return 1;
    }
    fread(data, sizeof(uint8_t), MAX_DATA_SIZE, data_file);
    fclose(data_file);

    FILE* watermark_file = fopen("watermark.data", "rb");
    if (!watermark_file) {
        printf("Error: cannot open watermark.data file\n");
        return 1;
    }
    fread(watermark, sizeof(uint8_t), 8, watermark_file);
    fclose(watermark_file);

    // Embed the watermark into the input data
    embed_watermark(data, watermark);

    // Write the watermarked data back into the input file
    data_file = fopen("input.data", "wb");
    if (!data_file) {
        printf("Error: cannot open input.data file\n");
        return 1;
    }
    fwrite(data, sizeof(uint8_t), MAX_DATA_SIZE, data_file);
    fclose(data_file);

    // Extract the watermark from the watermarked data
    uint8_t extracted_watermark[8];
    memset(extracted_watermark, 0, 8);
    extract_watermark(data, extracted_watermark);

    // Write the extracted watermark into the output file
    FILE* output_file = fopen("output.data", "wb");
    if (!output_file) {
        printf("Error: cannot open output.data file\n");
        return 1;
    }
    fwrite(extracted_watermark, sizeof(uint8_t), 8, output_file);
    fclose(output_file);

    return 0;
}