//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
#define KEY_LENGTH 32
#define WATERMARK_LENGTH 16

bool addWatermark(char *inputFile, char *outputFile, char *key, char *watermark) {
    // Open input file for reading
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        printf("Error: Could not open input file!\n");
        return false;
    }

    // Open output file for writing
    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        printf("Error: Could not open output file!\n");
        fclose(inFile);
        return false;
    }

    // Calculate number of watermarks that can be added to the input file
    fseek(inFile, 0L, SEEK_END);
    long fileSize = ftell(inFile);
    fseek(inFile, 0L, SEEK_SET);
    int watermarkCount = fileSize / BLOCK_SIZE;

    // If there is no space to add watermark
    if (watermarkCount == 0) {
        printf("Error: Input file is too small to add watermark!\n");
        fclose(inFile);
        fclose(outFile);
        return false;
    }

    // Create key array
    uint8_t keyArray[KEY_LENGTH];
    strncpy(keyArray, key, KEY_LENGTH);

    // Create watermark array
    uint8_t waterMarkArray[WATERMARK_LENGTH];
    strncpy(waterMarkArray, watermark, WATERMARK_LENGTH);

    // Allocate memory for read and write buffers
    uint8_t *readBuffer = malloc(BLOCK_SIZE);
    uint8_t *writeBuffer = malloc(BLOCK_SIZE);

    // Read input file block by block and add watermark to each block
    for (int i = 0; i < watermarkCount; i++) {
        // Read block from input file
        fread(readBuffer, sizeof(uint8_t), BLOCK_SIZE, inFile);

        // Add watermark to block
        for (int j = 0; j < WATERMARK_LENGTH; j++) {
            readBuffer[j] ^= waterMarkArray[j];
        }

        // Encrypt block with key
        for (int j = 0; j < BLOCK_SIZE; j++) {
            writeBuffer[j] = readBuffer[j] ^ keyArray[j % KEY_LENGTH];
        }

        // Write encrypted block to output file
        fwrite(writeBuffer, sizeof(uint8_t), BLOCK_SIZE, outFile);
    }

    // Add remaining bytes to output file
    int remainingBytes = fileSize % BLOCK_SIZE;
    if (remainingBytes > 0) {
        fread(readBuffer, sizeof(uint8_t), remainingBytes, inFile);
        for (int j = 0; j < remainingBytes; j++) {
            writeBuffer[j] = readBuffer[j] ^ keyArray[j % KEY_LENGTH];
        }
        fwrite(writeBuffer, sizeof(uint8_t), remainingBytes, outFile);
    }

    // Close input and output files
    fclose(inFile);
    fclose(outFile);

    // Free memory for buffers
    free(readBuffer);
    free(writeBuffer);

    return true;
}

bool verifyWatermark(char *inputFile, char *key, char *watermark) {
    // Open input file for reading
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        printf("Error: Could not open input file!\n");
        return false;
    }

    // Calculate number of watermarks that should be present in the input file
    fseek(inFile, 0L, SEEK_END);
    long fileSize = ftell(inFile);
    fseek(inFile, 0L, SEEK_SET);
    int watermarkCount = fileSize / BLOCK_SIZE;

    // If there is no watermark in the input file
    if (watermarkCount == 0) {
        printf("Error: Input file does not contain any watermark!\n");
        fclose(inFile);
        return false;
    }

    // Create key array
    uint8_t keyArray[KEY_LENGTH];
    strncpy(keyArray, key, KEY_LENGTH);

    // Create watermark array
    uint8_t waterMarkArray[WATERMARK_LENGTH];
    strncpy(waterMarkArray, watermark, WATERMARK_LENGTH);

    // Allocate memory for read buffer
    uint8_t *readBuffer = malloc(BLOCK_SIZE);

    // Verify each block in the input file
    bool verified = true;
    for (int i = 0; i < watermarkCount; i++) {
        // Read block from input file
        fread(readBuffer, sizeof(uint8_t), BLOCK_SIZE, inFile);

        // Decrypt block with key
        for (int j = 0; j < BLOCK_SIZE; j++) {
            readBuffer[j] ^= keyArray[j % KEY_LENGTH];
        }

        // Verify watermark in block
        for (int j = 0; j < WATERMARK_LENGTH; j++) {
            if (readBuffer[j] != waterMarkArray[j]) {
                verified = false;
                break;
            }
        }

        if (!verified) {
            break;
        }
    }

    // Close input file
    fclose(inFile);

    // Free memory for buffer
    free(readBuffer);

    return verified;
}

int main() {
    char *inputFile = "input_file.bin";
    char *outputFile = "output_file.bin";
    char *key = "thisiszxcvbnmlkjhgfdsaqwertyuiop";
    char *watermark = "MyWatermark12345";

    if (addWatermark(inputFile, outputFile, key, watermark)) {
        printf("Watermark added successfully!\n");
    } else {
        printf("Failed to add watermark!\n");
    }

    if (verifyWatermark(outputFile, key, watermark)) {
        printf("Watermark verification successful!\n");
    } else {
        printf("Watermark verification failed!\n");
    }

    return 0;
}