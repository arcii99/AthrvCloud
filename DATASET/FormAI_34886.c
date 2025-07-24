//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1000], watermark[100] = "ThisIsMyWatermark";
    int messageSize, watermarkSize, i, j, k = 0;

    printf("Enter the message to be watermarked:\n");
    fgets(message, sizeof(message), stdin);
    messageSize = strlen(message);

    watermarkSize = strlen(watermark);

    // Creating the watermarked message
    char watermarkedMessage[messageSize + watermarkSize + 1];
    for(i=0, j=0; i<messageSize+watermarkSize; i++)
    {
        if(i < messageSize)
            watermarkedMessage[i] = message[i];
        else
            watermarkedMessage[i] = watermark[j++];
    }
    watermarkedMessage[i] = '\0';
    printf("\nWatermarking the message...\n");

    // Printing the original message and the watermarked message
    printf("\nOriginal message: %s", message);
    printf("\nWatermarked message: %s", watermarkedMessage);

    // Extracting the watermark from the watermarked message
    char extractedWatermark[watermarkSize+1];
    for(i=messageSize, j=0; i<messageSize+watermarkSize; i++,j++)
        extractedWatermark[j] = watermarkedMessage[i];
    extractedWatermark[i-messageSize] = '\0';
    printf("\n\nExtracted watermark: %s\n", extractedWatermark);

    // Checking if the extracted watermark matches the original watermark
    if(strcmp(watermark, extractedWatermark) == 0)
        printf("The extracted watermark matches the original watermark!");
    else
        printf("The extracted watermark does not match the original watermark!");

    return 0;
}