//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define WATERMARK "MyWatermark"

void embedWatermark(FILE* inputFile, FILE* outputFile) {
    int c, i = 0, wmBit;
    char wmChar;
    
    // Embed watermark in LSB of each pixel
    while ((c = fgetc(inputFile)) != EOF) {
        wmChar = WATERMARK[i / 8];
        wmBit = (wmChar >> (i % 8)) & 1;
        c = (c & 0xFE) | wmBit;
        fputc(c, outputFile);
        i++;
    }
    
    // Append watermark size at the end
    int wmSize = i / 8;
    fwrite(&wmSize, sizeof(int), 1, outputFile);
}

void extractWatermark(FILE* inputFile) {
    int c, i = 0, wmSize;
    char wmStr[9] = {0};
    
    // Extract watermark from LSB of each pixel
    while ((c = fgetc(inputFile)) != EOF) {
        int wmBit = c & 1;
        wmStr[i/8] |= (wmBit << (i % 8));
        i++;
    }
    
    // Extract watermark size from the end
    fseek(inputFile, -sizeof(int), SEEK_END);
    fread(&wmSize, sizeof(int), 1, inputFile);
    
    // Print watermark if valid
    if (strncmp(wmStr, WATERMARK, wmSize) == 0) {
        printf("Watermark found: %s\n", wmStr);
    } else {
        printf("No watermark found.\n");
    }
}

int main() {
    FILE* inputFile = fopen("input.bmp", "rb");
    FILE* outputFile = fopen("output.bmp", "wb");
    
    embedWatermark(inputFile, outputFile);
    
    fclose(inputFile);
    fclose(outputFile);
    
    // Extract watermark
    FILE* outputFile2 = fopen("output.bmp", "rb");
    extractWatermark(outputFile2);
    
    fclose(outputFile2);
    
    return 0;
}