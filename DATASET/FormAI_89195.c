//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert ASCII values to binary
void asciiToBinary(char *message, char *binary) {
    int i, j, asciiValue;
    char binaryValue[8];
    for (i = 0; message[i] != '\0'; i++) {
        asciiValue = (int) message[i]; // Get ASCII value of current character
        j = 7; // Index to add binary digits starting from the most significant bit
        while (asciiValue > 0 && j >= 0) {
            if (asciiValue % 2 == 0) {
                binaryValue[j] = '0';
            } else {
                binaryValue[j] = '1';
            }
            asciiValue /= 2;
            j--;
        }
        // Pad the remaining digits with 0s
        while (j >= 0) {
            binaryValue[j] = '0';
            j--;
        }
        strcat(binary, binaryValue); // Append binary value to the output string
    }
}

// Function to replace the least significant bit of an 8-bit integer with a given bit
unsigned char replaceLSB(unsigned char byte, char bit) {
    if (bit == '0') {
        byte &= ~1; // Set LSB to 0
    } else {
        byte |= 1; // Set LSB to 1
    }
    return byte;
}

// Function to hide a binary message in an image
int hideMessageInImage(char *message, char *imagePath, char *outputPath) {
    // Open input and output files in binary mode
    FILE *inputFile = fopen(imagePath, "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file %s.\n", imagePath);
        return 1;
    }
    FILE *outputFile = fopen(outputPath, "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file %s.\n", outputPath);
        fclose(inputFile);
        return 1;
    }

    // Read 54-byte BMP header from input file and write it to output file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);
    fwrite(header, sizeof(unsigned char), 54, outputFile);

    // Calculate the maximum number of bytes that can be hidden in the image
    long imageSize = header[2] | (header[3] << 8) | (header[4] << 16) | (header[5] << 24);
    long maxBytes = (imageSize - 54) / 8;

    // Convert message to binary and check if it can be hidden in the image
    char binary[strlen(message) * 8 + 1];
    asciiToBinary(message, binary);
    if (strlen(binary) > maxBytes) {
        printf("Error: The message is too long to hide in the image.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Hide the binary message in the RGB values of the image
    unsigned char pixel[3];
    int i, j, k = 0;
    while (fread(pixel, sizeof(unsigned char), 3, inputFile) == 3 && k < strlen(binary)) {
        for (i = 0; i < 3; i++) {
            for (j = 7; j >= 0; j--) {
                if (k < strlen(binary)) {
                    pixel[i] = replaceLSB(pixel[i], binary[k]);
                    k++;
                }
            }
        }
        fwrite(pixel, sizeof(unsigned char), 3, outputFile);
    }

    // Copy the remaining bytes from the input file to the output file
    unsigned char byte;
    while (fread(&byte, sizeof(unsigned char), 1, inputFile) == 1) {
        fwrite(&byte, sizeof(unsigned char), 1, outputFile);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

// Function to extract a binary message from an image
int extractMessageFromImage(char *imagePath, char *message, int messageLength) {
    // Open input file in binary mode
    FILE *inputFile = fopen(imagePath, "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file %s.\n", imagePath);
        return 1;
    }

    // Read 54-byte BMP header from input file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);

    // Extract the binary message from the RGB values of the image
    unsigned char pixel[3];
    int i, j, k = 0;
    char binary[messageLength * 8 + 1];
    strcpy(binary, "");
    while (fread(pixel, sizeof(unsigned char), 3, inputFile) == 3 && k < messageLength) {
        for (i = 0; i < 3; i++) {
            for (j = 7; j >= 0; j--) {
                char bit = ((pixel[i] >> j) & 1) + '0';
                strcat(binary, &bit);
                if (strlen(binary) == messageLength * 8) {
                    break;
                }
            }
            if (strlen(binary) == messageLength * 8) {
                break;
            }
        }
        if (strlen(binary) == messageLength * 8) {
            break;
        }
    }

    // Convert binary message to ASCII and copy it to the output string
    int byteValue, l;
    char byte[9];
    byte[8] = '\0';
    for (i = 0; i < messageLength; i++) {
        byteValue = 0;
        for (j = 0; j < 8; j++) {
            byte[j] = binary[i * 8 + j];
        }
        for (j = 0, l = 7; j < 8; j++, l--) {
            if (byte[j] == '1') {
                byteValue += (1 << l);
            }
        }
        message[i] = (char) byteValue;
    }

    // Close input file
    fclose(inputFile);

    return 0;
}

// Main function to test the program
int main() {
    char message[] = "This is a secret message!";
    char imagePath[] = "image.bmp";
    char outputPath[] = "output.bmp";
    int messageLength = strlen(message);

    // Hide message in image
    int result = hideMessageInImage(message, imagePath, outputPath);
    if (result != 0) {
        return 1;
    }
    printf("Message has been hidden in the image.\n");

    // Extract message from image
    char extractedMessage[messageLength + 1];
    result = extractMessageFromImage(outputPath, extractedMessage, messageLength);
    if (result != 0) {
        return 1;
    }
    extractedMessage[messageLength] = '\0';
    printf("Extracted message: %s\n", extractedMessage);

    return 0;
}