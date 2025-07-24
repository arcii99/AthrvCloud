//FormAI DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>

// Function to convert decimal to binary
int decimalToBinary(int d)
{
    int binary = 0;
    int base = 1;

    while (d > 0) {
        binary += (d % 2) * base;
        d /= 2;
        base *= 10;
    }

    return binary;
}

// Function encode a message into an image using steganography
void encodeMessage(int image[], int message[], int n)
{
    int i, j;

    // Loop through each bit of the message
    for(i=0; i<n; i++) {
        int bit = (message[i / 8] >> (7 - (i % 8))) & 1; // Get the current bit in the message

        // Loop through each pixel in the image
        for(j=0; j<8; j++) {
            int pixel = image[i*8 + j]; // Get the current pixel in the image
            int binary = decimalToBinary(pixel); // Convert the pixel to binary
            int newBinary = (binary / 10) * 10 + bit; // Replace the least significant bit with the current bit in the message
            int newPixel = 0;

            // Convert the new binary back to decimal
            while (newBinary > 0) {
                newPixel = newPixel * 2 + (newBinary % 10);
                newBinary /= 10;
            }

            // Update the image with the new pixel value
            image[i*8 + j] = newPixel;
        }
    }
}

// Function to decode a message from an image using steganography
void decodeMessage(int image[], int message[], int n)
{
    int i, j;

    // Loop through each bit of the message
    for(i=0; i<n; i++) {
        int bit = 0;

        // Loop through each pixel in the image
        for(j=0; j<8; j++) {
            int pixel = image[i*8 + j]; // Get the current pixel in the image
            int binary = decimalToBinary(pixel); // Convert the pixel to binary
            bit = (10 * bit) + (binary % 10); // Get the least significant bit of the binary pixel value
        }

        message[i / 8] |= (bit >> (7 - (i % 8))); // Update the current bit of the message with the bit extracted from the image
    }
}

// Main function
int main()
{
    int image[64] = {156, 117, 79, 64, 198, 156, 117, 79, 182, 198, 156, 117, 45, 182, 198, 156, 23, 45, 182, 198, 137, 23, 45, 110, 137, 198, 23, 45, 110, 138, 198, 45, 110, 138, 150, 198, 110, 138, 150, 69, 110, 138, 110, 150, 138, 138, 110, 150, 198, 138, 110, 150, 198, 138, 110, 198, 150, 110, 138, 198, 150, 110, 138, 198};
    int message[8] = {67, 104, 97, 116, 66, 111, 116, 33};
    int n = 8 * 8;

    // Print the original image
    printf("Original image:\n");
    int i;
    for(i=0; i<64; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    // Encrypt the message in the image
    encodeMessage(image, message, n);

    // Print the encrypted image
    printf("Encrypted image:\n");
    for(i=0; i<64; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    // Decrypt the message from the image
    int decryptedMessage[8] = {0};
    decodeMessage(image, decryptedMessage, n);

    // Print the decrypted message
    printf("Decrypted message: ");
    for(i=0; i<8; i++) {
        printf("%c", decryptedMessage[i]);
    }
    printf("\n");

    return 0;
}