//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define BYTES_PER_PIXEL 3

void hideDataInImage(char* sourceImagePath, char* secretMessagePath, char* outputImagePath) {
    // Open image files
    FILE* sourceImageFile = fopen(sourceImagePath, "rb");
    FILE* secretMessageFile = fopen(secretMessagePath, "r");
    FILE* outputImageFile = fopen(outputImagePath, "wb");

    // Ensure all files are valid
    if (sourceImageFile == NULL) {
        printf("Error: Unable to open source image file\n");
        return;
    } else if (secretMessageFile == NULL) {
        printf("Error: Unable to open secret message file\n");
        fclose(sourceImageFile);
        return;
    } else if (outputImageFile == NULL) {
        printf("Error: Unable to create output image file\n");
        fclose(sourceImageFile);
        fclose(secretMessageFile);
        return;
    }

    // Read source image header data
    unsigned char* headerBuffer = (unsigned char*)malloc(BMP_HEADER_SIZE);
    fread(headerBuffer, sizeof(unsigned char), BMP_HEADER_SIZE, sourceImageFile);

    unsigned int width = *(int*)&headerBuffer[18];
    unsigned int height = *(int*)&headerBuffer[22];
    unsigned int imageSize = width * height * BYTES_PER_PIXEL;

    // Verify secret message can be hidden in image
    if (imageSize < strlen(secretMessagePath)) {
        printf("Error: Source image is too small to hide secret message\n");
        free(headerBuffer);
        fclose(sourceImageFile);
        fclose(secretMessageFile);
        fclose(outputImageFile);
        return;
    }

    // Copy header data to output image
    fwrite(headerBuffer, sizeof(unsigned char), BMP_HEADER_SIZE, outputImageFile);

    // Read secret message
    char* secretMessage = (char*)malloc(sizeof(char) * (strlen(secretMessagePath) + 1));
    fgets(secretMessage, strlen(secretMessagePath) + 1, secretMessageFile);

    // Hide secret message in image data
    fseek(sourceImageFile, BMP_HEADER_SIZE, SEEK_SET);
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, sourceImageFile);

    unsigned int imageIndex = 0;
    for (int messageIndex = 0; messageIndex < strlen(secretMessage); messageIndex++) {
        char messageChar = secretMessage[messageIndex];
        for (int bitIndex = 0; bitIndex < 8; bitIndex++) {
            // Get bit from message character
            unsigned char messageBit = (messageChar >> (7 - bitIndex)) & 0x01;

            // Set pixel bit to message bit
            imageData[imageIndex] = (imageData[imageIndex] & 0xFE) | messageBit;

            // Move to next pixel
            imageIndex++;
        }
    }

    fwrite(imageData, sizeof(unsigned char), imageSize, outputImageFile);

    // Cleanup
    free(secretMessage);
    free(imageData);
    free(headerBuffer);
    fclose(sourceImageFile);
    fclose(secretMessageFile);
    fclose(outputImageFile);

    printf("Secret message hidden in image\n");
}


char* revealDataInImage(char* imagePath) {
    // Open image file
    FILE* imageFile = fopen(imagePath, "rb");

    // Ensure image file is valid
    if (imageFile == NULL) {
        printf("Error: Unable to open image file\n");
        return NULL;
    }

    // Read image header data
    unsigned char* headerBuffer = (unsigned char*)malloc(BMP_HEADER_SIZE);
    fread(headerBuffer, sizeof(unsigned char), BMP_HEADER_SIZE, imageFile);

    unsigned int width = *(int*)&headerBuffer[18];
    unsigned int height = *(int*)&headerBuffer[22];
    unsigned int imageSize = width * height * BYTES_PER_PIXEL;

    // Read hidden data from image
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, imageFile);

    char* secretMessage = (char*)malloc(sizeof(char) * (imageSize / 8));
    unsigned int messageIndex = 0;
    for (int dataIndex = BMP_HEADER_SIZE; dataIndex < imageSize; dataIndex += 8) {
        char messageChar = 0;
        for (int bitIndex = 0; bitIndex < 8; bitIndex++) {
            unsigned char pixelBit = imageData[dataIndex + bitIndex] & 0x01;
            messageChar |= pixelBit << (7 - bitIndex);
        }
        secretMessage[messageIndex] = messageChar;
        messageIndex++;
    }

    // Cleanup
    free(imageData);
    free(headerBuffer);
    fclose(imageFile);

    printf("Secret message revealed from image\n");
    return secretMessage;
}


int main() {
    char* sourceImagePath = "source_image.bmp";
    char* secretMessagePath = "secret_message.txt";
    char* outputImagePath = "output_image.bmp";

    hideDataInImage(sourceImagePath, secretMessagePath, outputImagePath);

    char* revealedMessage = revealDataInImage(outputImagePath);
    printf("Secret message: %s\n", revealedMessage);
    free(revealedMessage);

    return 0;
}