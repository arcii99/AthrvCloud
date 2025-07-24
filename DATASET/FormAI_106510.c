//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the size of the image */
#define ROWS 10
#define COLS 10

/* Define the watermark to be embedded */
#define WATERMARK "WATERMARK"

/* Function to embed the watermark */
void embed_watermark(char image[ROWS][COLS]) {
    int i, j, k = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            /* Embed the watermark in the last character of each pixel */
            if (k < strlen(WATERMARK)) {
                image[i][j] = image[i][j] & 0xFE;   /* clear LSB */
                image[i][j] = image[i][j] | ((WATERMARK[k] & 1) << 0);   /* embed the bit */
                k++;
            }
        }
    }
}

/* Function to extract the watermark */
void extract_watermark(char image[ROWS][COLS]) {
    char watermark[strlen(WATERMARK)+1];   /* include the null terminator */
    memset(watermark, 0, strlen(WATERMARK)+1);   /* initialize watermark */
    int i, j, k = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            /* Extract the watermark from the last bit of each pixel */
            if (k < strlen(WATERMARK)) {
                watermark[k] = (image[i][j] & 1) + '0';
                k++;
            }
        }
    }
    /* Print the watermark */
    printf("Extracted watermark: %s\n", watermark);
}

int main() {
    /* Initialize the image */
    char image[ROWS][COLS] = {
        {0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x0C, 0x0E, 0x10, 0x12},
        {0x14, 0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24, 0x26},
        {0x28, 0x2A, 0x2C, 0x2E, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3A},
        {0x3C, 0x3E, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4A, 0x4C, 0x4E},
        {0x50, 0x52, 0x54, 0x56, 0x58, 0x5A, 0x5C, 0x5E, 0x60, 0x62},
        {0x64, 0x66, 0x68, 0x6A, 0x6C, 0x6E, 0x70, 0x72, 0x74, 0x76},
        {0x78, 0x7A, 0x7C, 0x7E, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8A},
        {0x8C, 0x8E, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9A, 0x9C, 0x9E},
        {0xA0, 0xA2, 0xA4, 0xA6, 0xA8, 0xAA, 0xAC, 0xAE, 0xB0, 0xB2},
        {0xB4, 0xB6, 0xB8, 0xBA, 0xBC, 0xBE, 0xC0, 0xC2, 0xC4, 0xC6}
    };
    
    /* Embed the watermark */
    embed_watermark(image);
    
    /* Extract the watermark */
    extract_watermark(image);
    
    return 0;
}