//FormAI DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 256
#define COLS 256

// Function to get the binary sequence of a number
void getBinary(char *binary, int number)
{
    int i = 0;
    while (number)
    {
        binary[i++] = ((number & 1) == 1) ? '1' : '0';
        number >>= 1;
    }
    binary[i] = '\0';
}

// Function to encode the message into the image
void encode(char *message, char image[][COLS])
{
    int messageLen = strlen(message);

    // Convert messageLength to binary string
    char binary[16];
    getBinary(binary, messageLen);

    // Encode message length using RGB values of the first 2 pixels
    int pixelIndex = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char binaryVal[8];
            getBinary(binaryVal, image[i][j]);
            binaryVal[7] = binary[strlen(binary) - (pixelIndex++) - 1];
            image[i][j] = strtol(binaryVal, NULL, 2);
        }
    }

    // Encode the message using RGB values of the rest of the pixels
    pixelIndex = 0;
    for (int i = 2; i < ROWS && pixelIndex < messageLen; i++)
    {
        for (int j = 0; j < COLS && pixelIndex < messageLen; j += 3)
        {
            if (message[pixelIndex] == '\0')
                return;

            char binaryVal[8];
            getBinary(binaryVal, image[i][j]);
            binaryVal[7] = message[pixelIndex++];
            image[i][j] = strtol(binaryVal, NULL, 2);

            getBinary(binaryVal, image[i][j + 1]);
            binaryVal[7] = message[pixelIndex++];
            image[i][j + 1] = strtol(binaryVal, NULL, 2);

            getBinary(binaryVal, image[i][j + 2]);
            binaryVal[7] = message[pixelIndex++];
            image[i][j + 2] = strtol(binaryVal, NULL, 2);
        }
    }
}

// Function to decode the message from the image
char* decode(char image[][COLS])
{
    // Decode message length from RGB values of first 2 pixels
    int messageLen = 0;
    char binary[16];
    int pixelIndex = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char binaryVal[8];
            getBinary(binaryVal, image[i][j]);
            binary[strlen(binary) - (pixelIndex++) - 1] = binaryVal[7];
        }
    }
    messageLen = strtol(binary, NULL, 2);
    char *message = (char*)malloc(messageLen+1);

    // Decode the message from the RGB values of the rest of the pixels
    pixelIndex = 0;
    for (int i = 2; i < ROWS && pixelIndex < messageLen; i++)
    {
        for (int j = 0; j < COLS && pixelIndex < messageLen; j += 3)
        {
            char binaryVal[8];
            getBinary(binaryVal, image[i][j]);
            message[pixelIndex++] = binaryVal[7];

            getBinary(binaryVal, image[i][j + 1]);
            message[pixelIndex++] = binaryVal[7];

            getBinary(binaryVal, image[i][j + 2]);
            message[pixelIndex++] = binaryVal[7];
        }
    }
    message[messageLen] = '\0';
    return message;
}

int main()
{
    char message[] = "This is a hidden message!";
    char image[ROWS][COLS];

    // Load image data into the 'image' 2D array
    // ...

    // Encode the message into the image
    encode(message, image);

    // Decode the message from the image
    char *decodedMessage = decode(image);

    // Print the original message and the decoded message
    printf("Original Message: %s\n", message);
    printf("Decoded Message: %s\n", decodedMessage);

    free(decodedMessage);
    return 0;
}