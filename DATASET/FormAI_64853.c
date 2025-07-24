//FormAI DATASET v1.0 Category: Image Steganography ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54

// Function that returns the size of a file in bytes
long getFileSize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    rewind(file);
    return size;
}

// Function that reads in a BMP image and stores
// the image pixels in an unsigned char array
unsigned char* readBmp(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Skip the BMP header
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, file);

    // Read in width and height
    int offset = *(int*)&header[10];
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int imageSize = *width * *height * 3; // RGB values for each pixel
    unsigned char *image = malloc(sizeof(unsigned char) * imageSize);
    fread(image, sizeof(unsigned char), imageSize, file);
    fclose(file);
    return image;
}

// Function that writes out a BMP image to a file
void writeBmp(char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char header[BMP_HEADER_SIZE];
    memset(header, 0, BMP_HEADER_SIZE);

    // Write BMP header
    header[0] = 'B';
    header[1] = 'M';
    int imageSize = width * height * 3;
    *(int*)&header[2] = BMP_HEADER_SIZE + imageSize;
    *(int*)&header[10] = BMP_HEADER_SIZE;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(unsigned short*)&header[26] = 1;
    *(unsigned short*)&header[28] = 24;
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, file);

    // Write image
    fwrite(image, sizeof(unsigned char), imageSize, file);
    fclose(file);
}

// Function that encodes a message into an image
void encode(char *filename, char *message) {
    int width, height;
    unsigned char *image = readBmp(filename, &width, &height);
    if (!image) {
        return;
    }

    int imageSize = width * height * 3;
    int messageLength = strlen(message);
    if (messageLength * 8 > imageSize) {
        printf("Error: Message too long to encode in image.\n");
        free(image);
        return;
    }

    // Loop through each pixel and encode message
    int i, j, k, l;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixelIndex = i * width + j;
            if (pixelIndex * 3 + 2 >= messageLength * 8) {
                break;
            }

            for (k = 0; k < 3; k++) {
                int bit = ((message[pixelIndex * 8 / 3] >> k) & 1);
                image[pixelIndex * 3 + k] = (image[pixelIndex * 3 + k] & 0xFE) | bit;
            }
        }
    }

    writeBmp("encoded.bmp", image, width, height);
    free(image);
}

// Function that decodes a message from an image
void decode(char *filename) {
    int width, height;
    unsigned char *image = readBmp(filename, &width, &height);
    if (!image) {
        return;
    }

    int messageLength = width * height * 3 / 8;
    char *message = malloc(sizeof(char) * (messageLength + 1));
    memset(message, 0, messageLength + 1);

    // Loop through each pixel and decode message
    int i, j, k, l;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixelIndex = i * width + j;
            if (pixelIndex * 3 + 2 >= messageLength * 8) {
                break;
            }

            char currentChar = 0;
            for (k = 0; k < 3; k++) {
                int bit = image[pixelIndex * 3 + k] & 1;
                currentChar = currentChar | (bit << k);
            }
            message[pixelIndex * 8 / 3] = currentChar;
        }
    }

    printf("Decoded message: %s\n", message);
    free(message);
    free(image);
}

// Main function
int main() {
    printf("Enter a message to encode: ");
    char message[255];
    scanf("%[^\n]", message);
    encode("lenna.bmp", message);

    decode("encoded.bmp");
    return 0;
}