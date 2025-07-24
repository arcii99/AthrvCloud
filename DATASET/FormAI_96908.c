//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MSG_LENGTH 100
#define MAX_WATERMARK_LENGTH 10
#define MAX_DIGITS 10
#define BLOCK_SIZE 8

/*
 * Function to convert a decimal number to binary
 */
int* decimalToBinary(int decimalNum) {
    int* binary = (int*)calloc(MAX_DIGITS, sizeof(int));
    int index = 0;

    while (decimalNum > 0) {
        binary[index++] = decimalNum % 2;
        decimalNum /= 2;
    }

    return binary;
}

/*
 * Function to embed the watermark into the message
 */
void embed(char* message, char* watermark) {
    int watermarkLength = strlen(watermark);
    int messageLength = strlen(message);
    int k = 0;

    for (int i = 0; i < messageLength; i += BLOCK_SIZE) {
        // Convert the next 8 characters of the message to a block of binary digits
        char block[BLOCK_SIZE + 1] = "";
        strncpy(block, message + i, BLOCK_SIZE);
        block[BLOCK_SIZE] = '\0';

        int decimal = strtol(block, NULL, 2);
        int* binary = decimalToBinary(decimal);

        // Embed the watermark into the least significant bits of the binary digits
        for (int j = 0; j < watermarkLength; j++) {
            binary[7 - j] = watermark[k++] - '0';
        }

        // Convert the binary digits back to a decimal number and then to an ASCII character
        int newDecimal = 0;
        for (int j = 0; j < BLOCK_SIZE; j++) {
            newDecimal += binary[j] * pow(2, BLOCK_SIZE - j - 1);
        }

        message[i / BLOCK_SIZE] = (char)newDecimal;
        free(binary);
    }
}

/*
 * Function to extract the watermark from the message
 */
char* extract(char* message, int watermarkLength) {
    int messageLength = strlen(message);
    char* watermark = (char*)calloc(watermarkLength + 1, sizeof(char));
    int k = 0;

    for (int i = 0; i < messageLength; i += BLOCK_SIZE) {
        // Convert the next 8 characters of the message to a block of binary digits
        char block[BLOCK_SIZE + 1] = "";
        strncpy(block, message + i, BLOCK_SIZE);
        block[BLOCK_SIZE] = '\0';

        int decimal = strtol(block, NULL, 2);
        int* binary = decimalToBinary(decimal);

        // Extract the watermark from the least significant bits of the binary digits
        for (int j = 0; j < watermarkLength; j++) {
            watermark[k++] = binary[7 - j] + '0';
        }

        free(binary);
    }

    return watermark;
}

int main() {
    char message[MAX_MSG_LENGTH] = "This is a secret message!";
    char watermark[MAX_WATERMARK_LENGTH] = "10101010";

    printf("Original message: %s\n", message);
    printf("Watermark to embed: %s\n", watermark);

    // Embed the watermark into the message
    embed(message, watermark);
    printf("Message with watermark: %s\n", message);

    // Extract the watermark from the message
    char* extractedWatermark = extract(message, strlen(watermark));
    printf("Extracted watermark: %s\n", extractedWatermark);

    return 0;
}