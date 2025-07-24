//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int original_image[256][256], watermarked_image[256][256];
int watermark[64][64];

// Function to read the image from file
void readImage(char *filename, int image[256][256]) {
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Could not open file\n");
        exit(0);
    }
    // Skip the header of the BMP file
    fseek(fp, 54, SEEK_SET);
    // Read the image data
    int i, j;
    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            image[i][j] = fgetc(fp);
        }
    }
    fclose(fp);
}

// Function to write the image to file
void writeImage(char *filename, int image[256][256]) {
    FILE *fp;
    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Could not open file\n");
        exit(0);
    }
    // Write the header of the BMP file
    int header[54];
    memset(header, 0, sizeof(header));
    header[0] = 'B';
    header[1] = 'M';
    header[10] = 54;
    header[14] = 40;
    header[26] = 1;
    header[28] = 8;
    fwrite(header, sizeof(int), 54/sizeof(int), fp);
    // Write the image data
    int i, j;
    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            fputc(image[i][j], fp);
        }
    }
    fclose(fp);
}

// Function to embed the watermark into the image
void embedWatermark(int image[256][256], int watermark[64][64]) {
    int i, j;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64; j++) {
            image[i][j] = ((image[i][j] >> 4) << 4) | (watermark[i][j] >> 4);
            image[i][j+64] = ((image[i][j+64] >> 4) << 4) | (watermark[i][j] & 0x0F);
            image[i][j+128] = ((image[i][j+128] >> 4) << 4) | ((watermark[i][j] << 4) & 0xF0);
            image[i][j+192] = ((image[i][j+192] >> 4) << 4) | ((watermark[i][j] << 8) & 0xF0);
            image[i+64][j] = ((image[i+64][j] >> 4) << 4) | ((watermark[i][j] << 12) & 0xF0);
            image[i+64][j+64] = ((image[i+64][j+64] >> 4) << 4) | ((watermark[i][j] << 16) & 0xF0);
            image[i+64][j+128] = ((image[i+64][j+128] >> 4) << 4) | ((watermark[i][j] << 20) & 0xF0);
            image[i+64][j+192] = ((image[i+64][j+192] >> 4) << 4) | ((watermark[i][j] << 24) & 0xF0);
            image[i+128][j] = ((image[i+128][j] >> 4) << 4) | ((watermark[i][j] << 28) & 0xF0);
            image[i+128][j+64] = ((image[i+128][j+64] >> 4) << 4) | (watermark[i][j+4] & 0x0F);
            image[i+128][j+128] = ((image[i+128][j+128] >> 4) << 4) | ((watermark[i][j+4] << 4) & 0xF0);
            image[i+128][j+192] = ((image[i+128][j+192] >> 4) << 4) | ((watermark[i][j+4] << 8) & 0xF0);
            image[i+192][j] = ((image[i+192][j] >> 4) << 4) | ((watermark[i][j+4] << 12) & 0xF0);
            image[i+192][j+64] = ((image[i+192][j+64] >> 4) << 4) | ((watermark[i][j+4] << 16) & 0xF0);
            image[i+192][j+128] = ((image[i+192][j+128] >> 4) << 4) | ((watermark[i][j+4] << 20) & 0xF0);
            image[i+192][j+192] = ((image[i+192][j+192] >> 4) << 4) | ((watermark[i][j+4] << 24) & 0xF0);
        }
    }
}

// Function to extract the watermark from the watermarked image
void extractWatermark(int watermarked_image[256][256], int watermark[64][64]) {
    int i, j;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64; j++) {
            watermark[i][j] = ((watermarked_image[i][j] & 0x0F) << 4) | ((watermarked_image[i][j+64] & 0x0F) & 0x0F);
            watermark[i][j+4] = ((watermarked_image[i][j+128] & 0xF0) >> 4) | ((watermarked_image[i][j+64] & 0xF0) & 0x0F);
            watermark[i][j+8] = ((watermarked_image[i][j+192] & 0xF0) >> 4) | ((watermarked_image[i][j+128] & 0x0F) & 0x0F);
            watermark[i][j+12] = ((watermarked_image[i+64][j] & 0xF0) >> 4) | ((watermarked_image[i][j+192] & 0x0F) & 0x0F);
            watermark[i][j+16] = ((watermarked_image[i+64][j+64] & 0xF0) >> 4) | ((watermarked_image[i+64][j] & 0x0F) & 0x0F);
            watermark[i][j+20] = ((watermarked_image[i+64][j+128] & 0xF0) >> 4) | ((watermarked_image[i+64][j+64] & 0xF0) & 0x0F);
            watermark[i][j+24] = ((watermarked_image[i+64][j+192] & 0xF0) >> 4) | ((watermarked_image[i+64][j+128] & 0x0F) & 0x0F);
            watermark[i][j+28] = ((watermarked_image[i+128][j] & 0xF0) >> 4) | ((watermarked_image[i+64][j+192] & 0x0F) & 0x0F);
            watermark[i][j+32] = ((watermarked_image[i+128][j+64] & 0xF0) >> 4) | ((watermarked_image[i+128][j] & 0x0F) & 0x0F);
            watermark[i][j+36] = ((watermarked_image[i+128][j+128] & 0xF0) >> 4) | ((watermarked_image[i+128][j+64] & 0xF0) & 0x0F);
            watermark[i][j+40] = ((watermarked_image[i+128][j+192] & 0xF0) >> 4) | ((watermarked_image[i+128][j+128] & 0x0F) & 0x0F);
            watermark[i][j+44] = ((watermarked_image[i+192][j] & 0xF0) >> 4) | ((watermarked_image[i+128][j+192] & 0x0F) & 0x0F);
            watermark[i][j+48] = ((watermarked_image[i+192][j+64] & 0xF0) >> 4) | ((watermarked_image[i+192][j] & 0x0F) & 0x0F);
            watermark[i][j+52] = ((watermarked_image[i+192][j+128] & 0xF0) >> 4) | ((watermarked_image[i+192][j+64] & 0xF0) & 0x0F);
            watermark[i][j+56] = ((watermarked_image[i+192][j+192] & 0xF0) >> 4) | ((watermarked_image[i+192][j+128] & 0x0F) & 0x0F);
        }
    }
}

int main() {
    readImage("original_image.bmp", original_image);
    readImage("watermark.bmp", watermark);
    embedWatermark(original_image, watermark);
    writeImage("watermarked_image.bmp", original_image);
    readImage("watermarked_image.bmp", watermarked_image);
    extractWatermark(watermarked_image, watermark);
    writeImage("extracted_watermark.bmp", watermark);
    return 0;
}