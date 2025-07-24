//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

void encode(char *filename, char *message) {
    FILE *inputFile = fopen(filename, "rb");
    FILE *outputFile = fopen("encoded.bmp", "wb");

    unsigned char buffer[54]; // BMP header is 54 bytes

    // Read the header of the BMP file
    fread(buffer, sizeof(unsigned char), 54, inputFile);

    // Write the header back to the output file
    fwrite(buffer, sizeof(unsigned char), 54, outputFile);

    int len = strlen(message);
    int bitIndex = 0;
    int byteIndex = 54; // Start writing message after header

    while (bitIndex < len * 8) {
        unsigned char byte = fgetc(inputFile);

        // Encode the message in the least significant bit of each color channel (RGB)
        byte = (byte & ~1) | ((message[bitIndex/8] >> (bitIndex % 8)) & 1);
        fputc(byte, outputFile);

        bitIndex++;
        byteIndex++;

        // Reset the byte index after every three bytes (RGB values)
        if ((byteIndex - 54) % 3 == 0) {
            byteIndex++;
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

char *decode(char *filename) {
    FILE *inputFile = fopen(filename, "rb");

    fseek(inputFile, 54, SEEK_SET); // Skip over BMP header

    char bits[8] = {0}; // Used to keep track of the current byte of the message
    int bitIndex = 0;
    char *message = malloc(sizeof(char)); // Allocate memory for the message

    while (1) {
        unsigned char byte = fgetc(inputFile);

        // Decode the message from the least significant bit of each color channel (RGB)
        bits[bitIndex] = byte & 1;
        bitIndex++;

        // If we've read a full byte, add it to the message and allocate more memory
        if (bitIndex == 8) {
            bitIndex = 0;
            message = realloc(message, strlen(message) + 2);
            message[strlen(message)] = 0;

            // Convert the bits to a char and add it to the message
            for (int i = 0; i < 8; i++) {
                message[strlen(message) - 1] |= (bits[i] << i);
            }

            // If we've read the null terminator, break out of the loop
            if (message[strlen(message) - 1] == 0) {
                break;
            }
        }
    }

    fclose(inputFile);
    return message;
}

int main() {
    char message[] = "The future is now.";

    encode("image.bmp", message);

    char *decoded = decode("encoded.bmp");
    printf("%s\n", decoded);

    free(decoded);

    return 0;
}