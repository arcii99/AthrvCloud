//FormAI DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // to use uint8_t data type
#include <string.h> // for string functions

// Function to read the image data
void readImage(char *fname, uint8_t *imageData, uint32_t imageSize)
{
    FILE *fp = fopen(fname, "rb");
    if(fp == NULL)
    {
        printf("Error: Unable to open file %s\n", fname);
        return;
    }

    uint32_t bytesRead = fread(imageData, 1, imageSize, fp);
    if(bytesRead != imageSize)
    {
        printf("Error: Unable to read %u bytes from file\n", imageSize);
        fclose(fp);
        return;
    }

    fclose(fp);
}

// Function to write the image data
void writeImage(char *fname, uint8_t *imageData, uint32_t imageSize)
{
    FILE *fp = fopen(fname, "wb");
    if(fp == NULL)
    {
        printf("Error: Unable to create file %s\n", fname);
        return;
    }

    uint32_t bytesWritten = fwrite(imageData, 1, imageSize, fp);
    if(bytesWritten != imageSize)
    {
        printf("Error: Unable to write %u bytes to file\n", imageSize);
        fclose(fp);
        return;
    }

    fclose(fp);
}

// Function to invert the color of the image
void invertColors(uint8_t *imageData, uint32_t imageSize)
{
    for(uint32_t i = 0; i < imageSize; i++)
    {
        imageData[i] = ~imageData[i]; // bitwise NOT operation to invert color
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 0;
    }

    char *inputImage = argv[1];
    char *outputImage = argv[2];

    // Read the image data
    FILE *fp = fopen(inputImage, "rb");
    if(fp == NULL)
    {
        printf("Error: Unable to open file %s\n", inputImage);
        return 0;
    }
    fseek(fp, 0, SEEK_END);
    uint32_t imageSize = ftell(fp);
    rewind(fp);
    uint8_t *imageData = (uint8_t *) malloc(imageSize);
    if(imageData == NULL)
    {
        printf("Error: Unable to allocate memory for image data\n");
        fclose(fp);
        return 0;
    }
    readImage(inputImage, imageData, imageSize);
    fclose(fp);

    // Invert the color of the image
    invertColors(imageData, imageSize);

    // Write the image data
    writeImage(outputImage, imageData, imageSize);

    // Free the memory allocated for image data
    free(imageData);

    return 0;
}