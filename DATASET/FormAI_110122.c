//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the number of bits to use for steganography
#define BITS 2

// Define image properties
#define WIDTH 512
#define HEIGHT 512
#define PIXELS (WIDTH * HEIGHT)
#define BYTES (PIXELS * 3)

// Define the image array
unsigned char image[BYTES];

// Define function to get a bit from a byte at a given position
unsigned char getBit(unsigned char byte, int pos) {
    return (byte >> pos) & 1;
}

// Define function to set a bit in a byte at a given position
void setBit(unsigned char *byte, int pos, unsigned char val) {
    *byte |= val << pos;
}

// Define function to hide a message in the image
void hideMessage(char *message) {

    // Get the length of the message
    int len = strlen(message);

    // Loop through the pixel array and hide the bits of the message
    for (int i = 0; i < BYTES && i < len * BITS; i += BITS) {

        // Get the current byte and bit position
        int bytePos = i / BITS;
        int bitPos = i % BITS;

        // Get the current bit of the message
        unsigned char bit = getBit(message[bytePos], bitPos);

        // Set the bit of the blue component of the current pixel
        setBit(&image[i], 0, bit);
    }

}

// Define function to extract the message from the image
char *extractMessage() {

    // Allocate memory for the message
    char *message = (char *)malloc(BYTES / BITS);

    // Loop through the pixel array and extract the message bits
    for (int i = 0; i < BYTES; i += BITS) {

        // Get the current byte and bit position
        int bytePos = i / BITS;
        int bitPos = i % BITS;

        // Get the current bit of the message
        unsigned char bit = getBit(image[i], 0);

        // Set the bit in the output message
        setBit(&message[bytePos], bitPos, bit);

    }

    // Return the message
    return message;
}

// Define main function
int main() {

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random message to hide
    char message[] = "Greetings, friend. It's been a while since we've spoken, but I have some new information that I think you'll find interesting.";

    // Print the message
    printf("Message to hide: %s\n", message);

    // Generate a random image
    for (int i = 0; i < BYTES; i++) {
        image[i] = rand() % 256;
    }

    // Hide the message in the image
    hideMessage(message);

    // Extract the message from the image
    char *extractedMessage = extractMessage();

    // Print the extracted message
    printf("Extracted message: %s\n", extractedMessage);

    // Free the memory used for the message
    free(extractedMessage);

    // Exit successfully
    return 0;
}