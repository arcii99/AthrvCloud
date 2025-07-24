//FormAI DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BYTE_SIZE 8

// Function to convert the decimal to binary
void decimalToBinary(int decimal, int* binary) {
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    while (index < BYTE_SIZE) {
        binary[index++] = 0;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int* binary) {
    int decimal = 0;

    for (int i = 0; i < BYTE_SIZE; i++) {
        decimal += binary[i] * pow(2, i);
    }

    return decimal;
}

// Function to hide the message into an image
void hideMessage(FILE* file, char* message) {
    int messageLength = strlen(message), messageIndex = 0, c;
    int binary[BYTE_SIZE];
    char pixel;

    while (messageIndex < messageLength) {
        for (int i = 0; i < BYTE_SIZE; i++) {
            c = fgetc(file);

            // Change the last bit of the pixel to store the message bit
            decimalToBinary(c, binary);
            binary[BYTE_SIZE - 1] = ((int)message[messageIndex] >> i) & 1;
            pixel = binaryToDecimal(binary);

            // Write the modified pixel value to the image
            fseek(file, -1, SEEK_CUR);
            fputc(pixel, file);
        }
        messageIndex++;
    }
    printf("Message hidden successfully!\n");
}

// Function to extract the message from an image
void extractMessage(FILE* file) {
    char* message = (char*) malloc(sizeof(char) * BYTE_SIZE + 1);
    int binary[BYTE_SIZE], messageIndex = 0, pixel;

    while (1) {
        for (int i = 0; i < BYTE_SIZE; i++) {
            pixel = fgetc(file);
            if (pixel == EOF) {
                printf("No message found in the image!\n");
                return;
            }

            // Extract the message bit from the last bit of the pixel value
            decimalToBinary(pixel, binary);
            message[messageIndex] = (char) ((binary[BYTE_SIZE - 1]) & 1);
            messageIndex++;
        }

        if (message[messageIndex - 1] == '\0') {
            break;
        }
    }

    printf("Extracted message: %s\n", message);
    free(message);
}

int main() {
    char* message = "Hello world!";
    FILE* image = fopen("image.bmp", "r+");

    if (image == NULL) {
        printf("Error opening image file!\n");
        return 0;
    }

    hideMessage(image, message);
    fseek(image, 0, SEEK_SET);
    extractMessage(image);

    fclose(image);
    return 0;
}