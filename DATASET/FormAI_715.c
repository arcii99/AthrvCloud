//FormAI DATASET v1.0 Category: Image compression ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

// Function to calculate frequency of each pixel
void calculateFrequency(int image[ROW][COL], int frequency[256])
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            frequency[image[i][j]]++;
        }
    }
}

// Function to calculate probability of each pixel
void calculateProbability(int frequency[256], double probability[256])
{
    int totalPixels = ROW * COL;

    for(int i=0; i<256; i++)
    {
        probability[i] = (double)frequency[i] / totalPixels;
    }
}

// Function to calculate cumulative probability of each pixel
void calculateCumulativeProbability(double probability[256], double cumulativeProbability[256])
{
    cumulativeProbability[0] = probability[0];
    
    for(int i=1; i<256; i++)
    {
        cumulativeProbability[i] = cumulativeProbability[i-1] + probability[i];
    }
}

// Function to calculate new pixel value after compression
int calculateNewPixelValue(double cumulativeProbability[256], int pixel)
{
    return (int)(255 * cumulativeProbability[pixel]);
}

// Function to perform image compression
void compressImage(int image[ROW][COL], int compressedImage[ROW][COL], double cumulativeProbability[256])
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            compressedImage[i][j] = calculateNewPixelValue(cumulativeProbability, image[i][j]);
        }
    }
}

// Function to print the image
void printImage(int image[ROW][COL])
{
    printf("Image:\n");

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            printf("%d ", image[i][j]);
        }

        printf("\n");
    }
}

// Function to print the compressed image
void printCompressedImage(int compressedImage[ROW][COL])
{
    printf("Compressed Image:\n");

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            printf("%d ", compressedImage[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int image[ROW][COL] = {{0, 0, 0, 0, 0}, {0, 1, 2, 1, 0}, {0, 1, 3, 1, 0}, {0, 1, 2, 1, 0}, {0, 0, 0, 0, 0}};
    int compressedImage[ROW][COL];
    int frequency[256] = {0};
    double probability[256] = {0.0};
    double cumulativeProbability[256] = {0.0};

    calculateFrequency(image, frequency);

    calculateProbability(frequency, probability);

    calculateCumulativeProbability(probability, cumulativeProbability);

    compressImage(image, compressedImage, cumulativeProbability);

    printImage(image);

    printCompressedImage(compressedImage);

    return 0;
}