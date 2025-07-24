//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to flip the image horizontally
void flipHorizontal(unsigned char *image, int width, int height)
{
    int x, y;
    unsigned char *tempRow = malloc(sizeof(unsigned char) * width * 3);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width / 2; x++) {
            int oldIndex = (y * width * 3) + (x * 3);
            int newIndex = (y * width * 3) + ((width - x - 1) * 3);
            tempRow[0] = image[oldIndex];
            tempRow[1] = image[oldIndex + 1];
            tempRow[2] = image[oldIndex + 2];
            image[oldIndex] = image[newIndex];
            image[oldIndex + 1] = image[newIndex + 1];
            image[oldIndex + 2] = image[newIndex + 2];
            image[newIndex] = tempRow[0];
            image[newIndex + 1] = tempRow[1];
            image[newIndex + 2] = tempRow[2];
        }
    }
    free(tempRow);
}

// Function to adjust the brightness of the image
void adjustBrightness(unsigned char *image, int width, int height, int amount)
{
    int i;
    for (i = 0; i < width * height * 3; i++) {
        int newValue = (int) image[i] + amount;
        if (newValue < 0) {
            image[i] = 0;
        } else if (newValue > 255) {
            image[i] = 255;
        } else {
            image[i] = newValue;
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(unsigned char *image, int width, int height, float amount)
{
    float contrast = (amount + 100) / 100.0;
    contrast *= contrast;
    int i;
    for (i = 0; i < width * height * 3; i++) {
        int newValue = (int) ((((image[i] / 255.0) - 0.5) * contrast + 0.5) * 255.0);
        if (newValue < 0) {
            image[i] = 0;
        } else if (newValue > 255) {
            image[i] = 255;
        } else {
            image[i] = newValue;
        }
    }
}

int main()
{
    // Open the input image file
    FILE *inputFile = fopen("input_image.raw", "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file");
        return 1;
    }
    // Determine the size of the image
    fseek(inputFile, 0L, SEEK_END);
    int imageSize = ftell(inputFile);
    fseek(inputFile, 0L, SEEK_SET);
    // Allocate memory for the image data
    unsigned char *imageData = malloc(sizeof(unsigned char) * imageSize);
    if (imageData == NULL) {
        printf("Error: Unable to allocate memory for image data");
        return 1;
    }
    // Read the image data from the file
    int bytesRead = fread(imageData, sizeof(char), imageSize, inputFile);
    if (bytesRead != imageSize) {
        printf("Error: Unable to read image data from file");
        return 1;
    }
    // Close the input file
    fclose(inputFile);
    // Get the dimensions of the image
    int width = 640;
    int height = 480;
    // Perform image processing tasks
    flipHorizontal(imageData, width, height);
    adjustBrightness(imageData, width, height, 50);
    adjustContrast(imageData, width, height, 50);
    // Open the output image file
    FILE *outputFile = fopen("output_image.raw", "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file");
        return 1;
    }
    // Write the processed image data to the file
    int bytesWritten = fwrite(imageData, sizeof(char), imageSize, outputFile);
    if (bytesWritten != imageSize) {
        printf("Error: Unable to write processed image data to file");
        return 1;
    }
    // Close the output file
    fclose(outputFile);
    // Free the image data memory
    free(imageData);
    return 0;
}