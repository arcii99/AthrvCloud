//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char message[MAX_SIZE], watermark[MAX_SIZE];

    printf("Enter the message to be watermarked: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the watermark: ");
    fgets(watermark, MAX_SIZE, stdin);

    int msize = (int)strlen(message) - 1; // to remove newline character
    int wsize = (int)strlen(watermark) - 1; // to remove newline character

    char result[MAX_SIZE];
    int index = 0;

    // Add the watermark to every other character in message
    for (int i = 0; i < msize; i++)
    {
        result[index++] = message[i];
        if (i % 2 == 0)
        {
            for (int j = 0; j < wsize; j++)
            {
                result[index++] = watermark[j];
            }
        }
    }
    result[index] = '\0';

    printf("The watermarked message is: %s\n", result);

    return 0;
}