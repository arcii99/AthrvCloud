//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 100

// Function to calculate the average of the image pixels
int calculateAvg(int (*image)[MAX_IMAGE_SIZE], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += image[i][j];
        }
    }
    int avg = sum / (n * n);
    return avg;
}

// Function to embed digital watermark in the image
void embedWatermark(int (*image)[MAX_IMAGE_SIZE], int n)
{
    int watermark[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    int avg = calculateAvg(image, n);
    int threshold = avg * 2;

    // Embed the watermark in the image using binary encoding
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (image[i][j] >= threshold)
            {
                if (watermark[i % 3][j % 3] == 1)
                {
                    image[i][j] = 255;
                }
                else
                {
                    image[i][j] = 0;
                }
            }
        }
    }
}

// Function to extract the digital watermark from the image
void extractWatermark(int (*image)[MAX_IMAGE_SIZE], int n)
{
    int watermark[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    int avg = calculateAvg(image, n);
    int threshold = avg * 2;

    // Extract the watermark from the image
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (image[i][j] >= threshold)
            {
                if (watermark[i % 3][j % 3] != 1)
                {
                    printf("The image does not contain the specified digital watermark.");
                    return;
                }
            }
            else
            {
                if (watermark[i % 3][j % 3] != 0)
                {
                    printf("The image does not contain the specified digital watermark.");
                    return;
                }
            }
        }
    }
    printf("The image contains the specified digital watermark.");
}

int main()
{
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int n;

    printf("Enter size of the image: ");
    scanf("%d", &n);

    printf("Enter the pixel values of the image (0-255):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    embedWatermark(image, n);

    printf("The image after embedding digital watermark:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("Extracting digital watermark from the image...\n");
    extractWatermark(image, n);

    return 0;
}