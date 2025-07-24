//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8
#define BIT_LIMIT 4

void embedWatermark(char *watermark, char *buffer)
{
    int watermarkIndex = 0;
    int bufferIndex = 0;
    char block[BLOCK_SIZE];
    int bitCounter = 0;

    while (watermarkIndex < strlen(watermark))
    {
        strncpy(block, buffer + bufferIndex, BLOCK_SIZE);

        for (int i = 0; i < BLOCK_SIZE; i++)
        {
            if (bitCounter < BIT_LIMIT && watermarkIndex < strlen(watermark))
            {
                int bit = (watermark[watermarkIndex] >> (BIT_LIMIT - bitCounter - 1)) & 1;
                block[i] = (block[i] & 0xFE) | bit;
                bitCounter++;
                watermarkIndex++;
            }
        }

        strncpy(buffer + bufferIndex, block, BLOCK_SIZE);
        bufferIndex += BLOCK_SIZE;
        bitCounter = 0;
    }
}

void extractWatermark(char *watermark, char *buffer)
{
    int watermarkIndex = 0;
    int bufferIndex = 0;
    char block[BLOCK_SIZE];
    int bitCounter = 0;

    while (watermarkIndex < strlen(watermark))
    {
        strncpy(block, buffer + bufferIndex, BLOCK_SIZE);

        for (int i = 0; i < BLOCK_SIZE; i++)
        {
            if (bitCounter < BIT_LIMIT && watermarkIndex < strlen(watermark))
            {
                int bit = block[i] & 1;
                watermark[watermarkIndex] = (watermark[watermarkIndex] << 1) | bit;
                bitCounter++;

                if (bitCounter == BIT_LIMIT)
                {
                    watermarkIndex++;
                    bitCounter = 0;
                }
            }
        }

        bufferIndex += BLOCK_SIZE;
    }
}

int main()
{
    char buffer[] = "This is an example of digital watermarking using a distributed style. The watermark is embedded in the first 4 bits of every byte in the buffer.";
    char watermark[] = "DWM2021";

    printf("Original buffer: %s\n", buffer);

    embedWatermark(watermark, buffer);
    printf("Buffer with watermark embedded: %s\n", buffer);

    char extractedWatermark[strlen(watermark) + 1];
    memset(extractedWatermark, 0, strlen(watermark) + 1);

    extractWatermark(extractedWatermark, buffer);
    printf("Extracted watermark: %s\n", extractedWatermark);

    return 0;
}