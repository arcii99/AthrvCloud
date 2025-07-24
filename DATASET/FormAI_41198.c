//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char message[MAX_SIZE], watermark[MAX_SIZE], output[MAX_SIZE];

void hideWatermark(char *message, char *watermark)
{
    int i, j;
    int messageLength = strlen(message), watermarkLength = strlen(watermark);

    for (i = 0, j = 0; i < messageLength; i++, j++)
    {
        if (j == watermarkLength)
        {
            j = 0;
        }
        output[i] = message[i] + watermark[j];
    }
    output[i] = '\0';
}

void extractWatermark(char *output, char *watermark)
{
    int i, j;
    int outputLength = strlen(output), watermarkLength = strlen(watermark);

    for (i = 0, j = 0; i < outputLength; i++, j++)
    {
        if (j == watermarkLength)
        {
            j = 0;
        }
        watermark[j] = output[i] - message[i];
    }
    watermark[j] = '\0';
}

int main()
{
    printf("Enter message to hide watermark in (max 1000 characters): ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter watermark to hide (max 1000 characters): ");
    fgets(watermark, MAX_SIZE, stdin);

    hideWatermark(message, watermark);
    printf("Output message with hidden watermark: %s\n", output);

    printf("Extracting watermark from output message...\n");
    extractWatermark(output, watermark);
    printf("Extracted watermark: %s\n", watermark);

    if (!strcmp(watermark, ""))
    {
        printf("No watermark found - Alert! Message may be compromised or tampered with.\n");
    }
    else
    {
        printf("Watermark found - Go ahead with the message transmission.\n");
    }

    return 0;
}