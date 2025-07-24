//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
  
int main(int argc, char *argv[]) {
    FILE *image_file, *secret_file, *stego_file;
    unsigned char buffer[BUFFER_SIZE], bit_mask, secret_byte, new_byte;
    int image_byte, bit_index, secret_index, buffer_index;
    long image_size, secret_size, stego_size;

    // Argument check
    if (argc != 4) {
        printf("Usage: ./steganography <image file> <secret file> <stego file>\n");
        return 1;
    }

    // Open image file
    image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Failed to open image file.\n");
        return 1;
    }

    // Open secret file
    secret_file = fopen(argv[2], "rb");
    if (secret_file == NULL) {
        printf("Failed to open secret file.\n");
        fclose(image_file);
        return 1;
    }

    // Open stego file for writing
    stego_file = fopen(argv[3], "wb");
    if (stego_file == NULL) {
        printf("Failed to create stego file.\n");
        fclose(image_file);
        fclose(secret_file);
        return 1;
    }

    // Get image file size
    fseek(image_file, 0L, SEEK_END);
    image_size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    // Write image file header to stego file
    for (int i = 0; i < 54; i++) {
        fputc(fgetc(image_file), stego_file);
    }

    // Get secret file size
    fseek(secret_file, 0L, SEEK_END);
    secret_size = ftell(secret_file);
    fseek(secret_file, 0L, SEEK_SET);

    // Write secret file size to stego file
    fwrite(&secret_size, sizeof(long), 1, stego_file);

    // Set bit mask to first bit of byte
    bit_mask = 0x01;
    // Initialize bit index to 0
    bit_index = 0;
    // Initialize buffer index to 0
    buffer_index = 0;

    // Loop through image bytes until secret is fully embedded
    while (secret_index < secret_size) {
        // If buffer is full, write to stego file
        if (buffer_index == BUFFER_SIZE) {
            fwrite(buffer, sizeof(unsigned char), BUFFER_SIZE, stego_file);
            // Reset buffer index to 0
            buffer_index = 0;
        }
        // Get next image byte
        image_byte = fgetc(image_file);
        // Get next secret byte, or 0 if reached end of file
        if (secret_index < secret_size) {
            secret_byte = fgetc(secret_file);
        } else {
            secret_byte = 0;
        }
        // Embed secret byte in image byte
        new_byte = image_byte & (~bit_mask); // Clear bit at bit_index
        if (secret_byte >> bit_index & 0x01) { // If secret bit is 1
            new_byte |= bit_mask; // Set bit at bit_index
        }
        buffer[buffer_index] = new_byte;
        // Increment bit index
        bit_index++;
        // If bit index has reached 8, reset to 0 and increment secret index
        if (bit_index == 8) {
            bit_index = 0;
            secret_index++;
        }
        // Shift bit mask to next bit
        bit_mask <<= 1;
        // If bit mask has reached 0, set to first bit of byte and increment buffer index
        if (bit_mask == 0) {
            bit_mask = 0x01;
            buffer_index++;
        }
    }

    // Write final buffer to stego file
    if (buffer_index > 0) {
        fwrite(buffer, sizeof(unsigned char), buffer_index, stego_file);
    }

    // Get stego file size
    fseek(stego_file, 0L, SEEK_END);
    stego_size = ftell(stego_file);
    fseek(stego_file, 0L, SEEK_SET);

    // Print results
    printf("Image file size: %ld bytes\n", image_size);
    printf("Secret file size: %ld bytes\n", secret_size);
    printf("Stego file size: %ld bytes\n", stego_size);

    // Close files
    fclose(image_file);
    fclose(secret_file);
    fclose(stego_file);

    return 0;
}