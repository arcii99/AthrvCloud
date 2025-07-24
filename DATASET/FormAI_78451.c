//FormAI DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3 // Each pixel is represented by 3 bytes (R, G, B)
#define BITS_PER_BYTE 8 // Each byte is 8 bits
#define MAX_IMAGE_SIZE 1000000 // Maximum image size in bytes

// Helper function to read in an image file and return the image data as a byte array
unsigned char* read_image(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open image file %s\n", filename);
        return NULL;
    }

    // Read image header (first 54 bytes)
    unsigned char header[54];
    size_t bytes_read = fread(header, sizeof(unsigned char), 54, fp);
    if (bytes_read != 54) {
        printf("Error: invalid image file %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Extract image dimensions from header
    *width = *(int*)(header + 18);
    *height = *(int*)(header + 22);

    // Make sure image is not too large
    if (*width * *height * BYTES_PER_PIXEL > MAX_IMAGE_SIZE) {
        printf("Error: image file %s is too large\n", filename);
        fclose(fp);
        return NULL;
    }

    // Allocate memory for image data
    unsigned char* image_data = (unsigned char*)malloc(*width * *height * BYTES_PER_PIXEL);
    if (image_data == NULL) {
        printf("Error: could not allocate memory for image data\n");
        fclose(fp);
        return NULL;
    }

    // Read in image data
    bytes_read = fread(image_data, sizeof(unsigned char), *width * *height * BYTES_PER_PIXEL, fp);
    if (bytes_read != *width * *height * BYTES_PER_PIXEL) {
        printf("Error: invalid image file %s\n", filename);
        fclose(fp);
        free(image_data);
        return NULL;
    }

    // Close the file and return the image data
    fclose(fp);
    return image_data;
}

// Helper function to write image data to a file
void write_image(const char* filename, unsigned char* image_data, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s for writing\n", filename);
        return;
    }

    // Write image header (first 54 bytes)
    unsigned char header[54] = {
        'B', 'M', // Magic number
        54 + width * height * BYTES_PER_PIXEL, // File size in bytes
        0, 0, 0, 0, // Unused
        54, 0, 0, 0, // Offset to image data
        40, 0, 0, 0, // Size of header
        width & 0xff, (width >> 8) & 0xff, (width >> 16) & 0xff, (width >> 24) & 0xff, // Width
        height & 0xff, (height >> 8) & 0xff, (height >> 16) & 0xff, (height >> 24) & 0xff, // Height
        1, 0, // Number of color planes
        BYTES_PER_PIXEL * BITS_PER_BYTE, 0, // Bits per pixel
        0, 0, 0, 0, // Compression type (none)
        0, 0, 0, 0, // Image size (none)
        0, 0, 0, 0, // Pixels per meter (none)
        0, 0, 0, 0, // Pixels per meter (none)
        0, 0, 0, 0, // Unused
        0, 0, 0, 0 // Unused
    };
    size_t bytes_written = fwrite(header, sizeof(unsigned char), 54, fp);
    if (bytes_written != 54) {
        printf("Error: could not write image header for file %s\n", filename);
        fclose(fp);
        return;
    }

    // Write image data
    bytes_written = fwrite(image_data, sizeof(unsigned char), width * height * BYTES_PER_PIXEL, fp);
    if (bytes_written != width * height * BYTES_PER_PIXEL) {
        printf("Error: could not write image data for file %s\n", filename);
        fclose(fp);
        return;
    }

    // Close the file
    fclose(fp);
}

// Helper function to extract the least significant bit of a byte
int get_lsb(unsigned char byte) {
    return byte & 0x01;
}

// Helper function to set the least significant bit of a byte
void set_lsb(unsigned char* byte, int bit) {
    *byte = (*byte & 0xfe) | (bit & 0x01);
}

// Helper function to hide a secret message in an image
void hide_message(unsigned char* image_data, int width, int height, const char* message) {
    // Convert message to a binary string
    int message_length = strlen(message);
    char* binary_message = (char*)malloc(message_length * BITS_PER_BYTE + 1);
    if (binary_message == NULL) {
        printf("Error: could not allocate memory for binary message\n");
        return;
    }
    int index = 0;
    for (int i = 0; i < message_length; i++) {
        for (int j = BITS_PER_BYTE - 1; j >= 0; j--) {
            binary_message[index++] = ((message[i] >> j) & 0x01) + '0';
        }
    }
    binary_message[index++] = '\0';

    // Hide binary message in image data
    int data_index = 0;
    int message_index = 0;
    while (message_index < index) {
        for (int i = 0; i < BYTES_PER_PIXEL; i++) {
            // Get the least significant bit of the current pixel byte
            int lsb = get_lsb(image_data[data_index]);

            // Set the least significant bit of the pixel byte to the next bit of the binary message
            if (message_index < index) {
                set_lsb(&image_data[data_index], binary_message[message_index++] - '0');
            }

            // Move to the next pixel byte
            data_index++;
        }
    }

    // Free memory allocated for binary message
    free(binary_message);
}

// Helper function to extract a secret message from an image
char* extract_message(unsigned char* image_data, int width, int height) {
    // Extract binary message from image data
    int data_index = 0;
    char binary_message[MAX_IMAGE_SIZE * BITS_PER_BYTE + 1];
    int binary_index = 0;
    while (data_index < width * height * BYTES_PER_PIXEL) {
        for (int i = 0; i < BYTES_PER_PIXEL; i++) {
            // Get the least significant bit of the current pixel byte
            int lsb = get_lsb(image_data[data_index]);

            // Append the least significant bit to the binary message
            binary_message[binary_index++] = lsb + '0';

            // Move to the next pixel byte
            data_index++;
        }
    }
    binary_message[binary_index++] = '\0';

    // Convert binary message to a string
    int message_length = binary_index / BITS_PER_BYTE;
    char* message = (char*)malloc(message_length + 1);
    if (message == NULL) {
        printf("Error: could not allocate memory for extracted message\n");
        return NULL;
    }

    for (int i = 0; i < message_length; i++) {
        // Extract the next byte of the message from the binary string
        char byte = 0;
        for (int j = 0; j < BITS_PER_BYTE; j++) {
            byte = (byte << 1) | (binary_message[i * BITS_PER_BYTE + j] - '0');
        }
        message[i] = byte;
    }
    message[message_length] = '\0';

    return message;
}

int main(int argc, char** argv) {
    // Check command line arguments
    if (argc < 3) {
        printf("Usage: %s <input_image_file> <output_image_file> [message]\n", argv[0]);
        return 0;
    }

    // Read in image data
    int width, height;
    unsigned char* image_data = read_image(argv[1], &width, &height);
    if (image_data == NULL) {
        return 0;
    }

    // Hide or extract message based on command line arguments
    if (argc == 4) {
        hide_message(image_data, width, height, argv[3]);
    } else {
        char* message = extract_message(image_data, width, height);
        if (message != NULL) {
            printf("Extracted message: %s\n", message);
            free(message);
        }
    }

    // Write out image data
    write_image(argv[2], image_data, width, height);
    
    // Free allocated memory
    free(image_data);

    return 0;
}