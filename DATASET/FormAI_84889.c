//FormAI DATASET v1.0 Category: Image Steganography ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the bit value from a pixel 
int getPixelValue(int pixel) {
    return (pixel & 1);
}

// Function to write a bit value into a pixel 
int setPixelValue(int pixel, int bit) {
    if (bit == 0) {
        return (pixel & 0xFE);
    } else {
        return (pixel | 0x01);
    }
}

// Function to hide a message in an image 
void hideMessageInImage(char* imageFileName, char* message, char* outputFileName) {
    FILE* fp = fopen(imageFileName, "rb");
    FILE* outfp = fopen(outputFileName, "wb");

    int bitIndex = 0;
    char c = message[0];
    int j = 0;
    while (c != '\0') {
        for (int i = 0; i < 8; i++) {
            int pixel = fgetc(fp);
            int value = getPixelValue(pixel);
            int bit = 0x80 & (c << bitIndex);

            if (bit != 0) {
                value = setPixelValue(pixel, 1);
            } else {
                value = setPixelValue(pixel, 0);
            }

            fputc(value, outfp);

            if (bitIndex == 7) {
                j++;
                c = message[j];
                bitIndex = 0;
            } else {
                bitIndex++;
            }
        }
    }

    int pixel;
    while ((pixel = fgetc(fp)) != EOF) {
        fputc(pixel, outfp);
    }

    fclose(fp);
    fclose(outfp);
}

// Function to extract a message from an image 
void extractMessageFromImage(char* imageFileName) {
    FILE* fp = fopen(imageFileName, "rb");
    int bitIndex = 0;
    char c = 0;
    int j = 0;
    while (1) {
        int pixel = fgetc(fp);
        if (pixel == EOF) break;
        int value = getPixelValue(pixel);

        c |= value << bitIndex;

        if (bitIndex == 7) {
            if (c == '\0') break;
            printf("%c", c);
            j++;
            c = 0;
            bitIndex = 0;
        } else {
            bitIndex++;
        }
    }
    fclose(fp);
}

// Main function
int main() {
    char* message = "The quick brown fox jumps over the lazy dog.";
    hideMessageInImage("surrealist_image.bmp", message, "surrealist_image_with_hidden_message.bmp");
    extractMessageFromImage("surrealist_image_with_hidden_message.bmp");
    return 0;
}