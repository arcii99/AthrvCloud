//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to set the lowest bit of every pixel to zero, except for the watermark bit
void embed_watermark(char *image_path, char *output_path, char *watermark) {
    FILE *image_file = fopen(image_path, "rb");
    FILE *output_file = fopen(output_path, "wb");

    if (image_file == NULL || output_file == NULL) {
        printf("File error!\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    fwrite(header, sizeof(unsigned char), 54, output_file);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;

    // Embed the watermark text bit by bit
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, image_file);

            // Set the lowest bit of the red component to zero
            pixel[0] = pixel[0] & 0xFE;

            if (*watermark != '\0') {
                // If there are more bits in the watermark message, embed the next one
                if ((*watermark & 0x80) == 0x80) {
                    // Set the lowest bit of the red component to one
                    pixel[0] = pixel[0] | 0x01;
                }
                watermark++;
            }

            fwrite(pixel, sizeof(unsigned char), 3, output_file);
        }
        // Add padding to the end of each row
        fseek(image_file, padding, SEEK_CUR);
        for (int k = 0; k < padding; k++) {
            fputc(0x00, output_file);
        }
    }

    fclose(image_file);
    fclose(output_file);
}

// Function to extract the watermark from an image
void extract_watermark(char *image_path, int watermark_len) {
    FILE *image_file = fopen(image_path, "rb");

    if (image_file == NULL) {
        printf("File error!\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;

    char watermark[watermark_len + 1];
    memset(watermark, 0, watermark_len + 1);

    // Extract the watermark from the LSB of the red component of each pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, image_file);

            // Extract the lowest bit of the red component
            if ((pixel[0] & 0x01) == 0x01) {
                watermark[i * width + j] = '1';
            } else {
                watermark[i * width + j] = '0';
            }

            if (i * width + j == watermark_len) {
                break;
            }
        }
        // Skip the padding at the end of each row
        fseek(image_file, padding, SEEK_CUR);
    }

    printf("Extracted watermark: %s\n", watermark);

    fclose(image_file);
}

int main() {
    char *image_path = "input.bmp";
    char *output_path = "output.bmp";
    char *watermark = "Hello, World!";
    int watermark_len = strlen(watermark) * 8;

    embed_watermark(image_path, output_path, watermark);

    extract_watermark(output_path, watermark_len);

    return 0;
}