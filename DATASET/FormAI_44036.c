//FormAI DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 54 // BMP header size

// Function to read text from user
void readMessage(char *message, int size) {
    printf("Enter the message to hide:\n");
    fgets(message, size, stdin);
}

// Function to encode the message into the image
void encodeMessage(char *message, FILE *imageFile) {
    // Move file cursor to start of pixel array
    fseek(imageFile, HEADER_SIZE, SEEK_SET);
    
    char c; 
    int i = 0;
    while((c = message[i]) != '\0') { // Check for end of message
        // Loop through RGB values of a pixel
        for(int j = 0; j < 3; j++) {
            int pixelValue = fgetc(imageFile);
            int bitValue = (c >> j) & 1; // Get the j-th bit of the character
            // Set the least significant bit of the pixelValue to bitValue
            pixelValue = (pixelValue & ~1) | bitValue;
            fseek(imageFile, -1, SEEK_CUR); // Move file cursor back one byte
            fputc(pixelValue, imageFile); // Write the new pixel value
        }
        i++;
    }
}

// Function to decode the message hidden in the image
void decodeMessage(char *decodedMessage, FILE *imageFile, int messageSize) {
    // Move file cursor to start of pixel array
    fseek(imageFile, HEADER_SIZE, SEEK_SET);

    char c = 0;
    int i = 0;
    while(i < messageSize) { // Loop through each character in the message
        // Loop through RGB values of a pixel
        for(int j = 0; j < 3; j++) {
            // Get the least significant bit of the pixelValue
            int pixelValue = fgetc(imageFile) & 1;
            c |= (pixelValue << j); // Set the j-th bit of the character
        }
        decodedMessage[i] = c;
        c = 0;
        i++;
    }
}

int main() {
    // Open the image file
    FILE *imageFile = fopen("image.bmp", "rb+");
    if(imageFile == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    
    // Read the message to hide
    char message[256];
    readMessage(message, sizeof(message));

    // Encode the message into the image
    encodeMessage(message, imageFile);

    // Decode the message from the image
    char decodedMessage[256] = {0}; // Initialize to all zeros
    decodeMessage(decodedMessage, imageFile, sizeof(message));
    printf("The decoded message is:\n%s", decodedMessage);

    // Close the image file
    fclose(imageFile);
    return 0;
}