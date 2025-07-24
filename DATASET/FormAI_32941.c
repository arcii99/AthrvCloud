//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100]; // Reading input message
    printf("Enter the message to be watermarked:\n");
    fgets(message, sizeof(message), stdin);
    printf("\nMessage entered is: %s\n", message);

    char watermark[20]; // Reading input watermark
    printf("\nEnter the watermark:\n");
    fgets(watermark, sizeof(watermark), stdin);
    printf("\nWatermark is: %s\n", watermark);

    int n = strlen(message);
    int watermarkSize = strlen(watermark);

    // Appending the watermark to the message
    if (watermarkSize < n)
    {
        int start = n - watermarkSize;
        for (int i = start, j = 0; i < n; i++, j++)
        {
            message[i] = watermark[j];
        }
    }
    else
    {
        printf("\nError: Watermark size is larger than message size\n");
        exit(0);
    }

    // Printing the watermarked message
    printf("\nWatermarked message is: %s\n", message);

    // Retrieving the watermark
    char retrievedWatermark[20];
    for (int i = n - watermarkSize, j = 0; i < n; i++, j++)
    {
        retrievedWatermark[j] = message[i];
    }

    // Comparing the retrieved watermark with original watermark
    if (strcmp(watermark, retrievedWatermark) == 0)
    {
        printf("\nWatermark successfully retrieved\n");
    }
    else
    {
        printf("\nError: Watermark could not be retrieved\n");
        exit(0);
    }

    return 0;
}