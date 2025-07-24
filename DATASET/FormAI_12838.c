//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000 // Maximum length of message
#define MAX_WATERMARK_LENGTH 100 // Maximum length of watermark
#define WATERMARK_BIT_LENGTH 16 // Number of bits in watermark
#define ENCODING_LOCATION 17 // Bit location of encoding
#define SHIFT_AMOUNT 1 // Shift amount for encoding

int main()
{
    char message[MAX_LENGTH]; // Message input by user
    char watermark[MAX_WATERMARK_LENGTH]; // Watermark input by user
    char encoded_message[MAX_LENGTH]; // Encoded message
    int watermark_bits[WATERMARK_BIT_LENGTH]; // Array of bits in watermark
    int i, j, k, l;

    // Get message input from user
    printf("Enter the message (max length %d characters):\n", MAX_LENGTH);
    fgets(message, MAX_LENGTH, stdin);

    // Get watermark input from user
    printf("Enter the watermark (max length %d characters):\n", MAX_WATERMARK_LENGTH);
    fgets(watermark, MAX_WATERMARK_LENGTH, stdin);

    // Convert watermark to bits
    for (i = 0, j = 0; i < strlen(watermark) && j < WATERMARK_BIT_LENGTH; i++)
    {
        int ascii_value = (int)watermark[i];
        int bit_array[8];

        // Convert character to 8 bit binary representation
        for (k = 7; k >= 0; k--)
        {
            bit_array[k] = ascii_value % 2;
            ascii_value /= 2;
        }

        // Add bits to watermark_bits array
        for (l = 0; l < 8 && j < WATERMARK_BIT_LENGTH; l++, j++)
        {
            watermark_bits[j] = bit_array[l];
        }
    }

    // Add watermark to message
    for (i = 0, j = 0; i < strlen(message); i++)
    {
        int ascii_value = (int)message[i];
        int bit_array[8];

        // Convert character to 8 bit binary representation
        for (k = 7; k >= 0; k--)
        {
            bit_array[k] = ascii_value % 2;
            ascii_value /= 2;
        }

        // Check if the jth bit of the watermark should be added
        if (j < WATERMARK_BIT_LENGTH)
        {
            bit_array[ENCODING_LOCATION] = watermark_bits[j];

            j++;
        }

        // Convert back to ASCII value
        ascii_value = 0;
        for (k = 0; k < 8; k++)
        {
            ascii_value += bit_array[k] * pow(2, 7 - k);
        }

        encoded_message[i] = (char)ascii_value;
    }

    // Print encoded message
    printf("Encoded message with watermark:\n%s", encoded_message);

    return 0;
}