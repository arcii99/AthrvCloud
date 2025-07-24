//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define watermark size
#define WATERMARK_SIZE 10

// Define message size
#define MESSAGE_SIZE 100

int main()
{
    // Define message to be watermarked
    char message[MESSAGE_SIZE];
    printf("Please enter the message to be watermarked: ");
    fgets(message, MESSAGE_SIZE, stdin);

    // Define watermark
    char watermark[WATERMARK_SIZE] = "HAPPYCODE!";
    int watermarkIndex = 0;

    // Loop through each character in message to watermark
    for (int i = 0; i < strlen(message); i++)
    {
        // If watermarking is complete, exit loop
        if (watermarkIndex == WATERMARK_SIZE)
        {
            break;
        }

        // Watermark the character by adding the corresponding watermark character's ASCII value
        message[i] += watermark[watermarkIndex];

        // Increment watermark index
        watermarkIndex++;

        // If end of watermark is reached, reset to beginning
        if (watermarkIndex == WATERMARK_SIZE)
        {
            watermarkIndex = 0;
        }
    }

    // Output the watermarked message
    printf("The watermarked message is: %s", message);

    return 0;
}