//FormAI DATASET v1.0 Category: Image Steganography ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FILE_SIZE 1024

void hideDataInImage(unsigned char *imageData, unsigned char *secretData, int imageSize, int secretSize, int baseOffset);
void readImageFile(unsigned char *imageData, int *imageSize, char *filename);
void writeImageFile(unsigned char *imageData, int imageSize, char *filename);

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Usage: %s [cover image] [secret data file] [output image]\n", argv[0]);
        return 1;
    }

    char *coverImageFilename = argv[1];
    char *secretDataFilename = argv[2];
    char *outputImageFilename = argv[3];

    unsigned char coverImageData[MAX_FILE_SIZE];
    unsigned char secretData[MAX_FILE_SIZE];

    int coverImageSize;
    int secretDataSize;

    readImageFile(coverImageData, &coverImageSize, coverImageFilename);

    FILE *secretDataFile = fopen(secretDataFilename, "rb");

    if(secretDataFile == NULL)
    {
        printf("Error: Could not open secret data file '%s'\n", secretDataFilename);
        return 1;
    }

    secretDataSize = fread(secretData, sizeof(unsigned char), MAX_FILE_SIZE, secretDataFile);

    fclose(secretDataFile);

    int baseOffset = 54; // Header of BMP file is 54 bytes

    hideDataInImage(coverImageData, secretData, coverImageSize, secretDataSize, baseOffset);

    writeImageFile(coverImageData, coverImageSize, outputImageFilename);

    printf("Data hidden successfully!\n");

    return 0;
}

void hideDataInImage(unsigned char *imageData, unsigned char *secretData, int imageSize, int secretSize, int baseOffset)
{
    int bitCount = 0;
    int dataCount = 0;
    int bitMask = 1;
    int bit = 0;

    for(int i = baseOffset; i < imageSize; i++)
    {
        if(bitCount == 8)
        {
            bitCount = 0;
            bitMask = 1;
            dataCount++;

            if(dataCount > secretSize)
            {
                return;
            }
        }

        bit = (*secretData & bitMask) >> bitCount;
        *secretData = (*secretData & ~bitMask) | (imageData[i] & bitMask);
        imageData[i] = (imageData[i] & ~bitMask) | (bit << bitCount);

        bitMask <<= 1;
        bitCount++;
    }
}

void readImageFile(unsigned char *imageData, int *imageSize, char *filename)
{
    FILE *imageFile = fopen(filename, "rb");

    if(imageFile == NULL)
    {
        printf("Error: Could not open image file '%s'\n", filename);
        exit(1);
    }

    fseek(imageFile, 0, SEEK_END);
    *imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    fread(imageData, sizeof(unsigned char), *imageSize, imageFile);
    fclose(imageFile);
}

void writeImageFile(unsigned char *imageData, int imageSize, char *filename)
{
    FILE *imageFile = fopen(filename, "wb");

    if(imageFile == NULL)
    {
        printf("Error: Could not create output image file '%s'\n", filename);
        exit(1);
    }

    fwrite(imageData, sizeof(unsigned char), imageSize, imageFile);
    fclose(imageFile);
}