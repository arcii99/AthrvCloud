//FormAI DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HEADER_SIZE 54
#define BMP_SIGNATURE 0x4d42

int main() {

    // Read input image
    char* input_path = "/path/to/input/image.bmp";
    FILE* input_image = fopen(input_path, "rb");
    if (!input_image) {
        printf("Error: input file could not be opened\n");
        return 1;
    }

    // Read BMP header
    uint8_t header[HEADER_SIZE];
    if (fread(header, 1, HEADER_SIZE, input_image) != HEADER_SIZE) {
        printf("Error: invalid BMP file\n");
        fclose(input_image);
        return 1;
    }

    uint16_t signature = *(uint16_t*)(header);
    if (signature != BMP_SIGNATURE) {
        printf("Error: invalid BMP file\n");
        fclose(input_image);
        return 1;
    }

    // Get image dimensions
    uint32_t width = *(uint32_t*)(header+18);
    uint32_t height = *(uint32_t*)(header+22);

    // Calculate image payload size
    uint32_t payload_size = (width * height * 3) / 8;

    // Allocate memory for image data and payload
    uint8_t* image_data = (uint8_t*)malloc(width * height * 3);
    uint8_t* payload = (uint8_t*)malloc(payload_size);

    // Read image data
    fseek(input_image, HEADER_SIZE, SEEK_SET);
    if (fread(image_data, 1, width * height * 3, input_image) != width * height * 3) {
        printf("Error: invalid BMP file\n");
        fclose(input_image);
        free(image_data);
        free(payload);
        return 1;
    }

    // Read payload
    char* message = "Hello, world!";
    uint32_t message_length = strlen(message);
    uint8_t* message_bytes = (uint8_t*)message;

    // Check if payload can fit in image
    if (message_length > payload_size) {
        printf("Error: payload too large for image\n");
        fclose(input_image);
        free(image_data);
        free(payload);
        return 1;
    }

    // Write payload length into first 4 bytes of payload
    *(uint32_t*)payload = message_length;

    // Write message into payload
    memcpy(payload+4, message_bytes, message_length);

    // Encode payload into image using LSB steganography
    for (uint32_t i = 0, j = 0; i < payload_size; i++, j+=8) {
        for (int k = 0; k < 8; k++) {
            uint32_t byte_index = (i * 8) / 3;
            uint8_t bit_value = (payload[i] & (1 << k)) >> k;
            uint8_t image_byte = image_data[byte_index+j];
            image_byte = (image_byte & 0xfe) | bit_value;
            image_data[byte_index+j] = image_byte;
        }
    }

    // Write output image
    char* output_path = "/path/to/output/image.bmp";
    FILE* output_image = fopen(output_path, "wb");
    if (!output_image) {
        printf("Error: output file could not be opened\n");
        fclose(input_image);
        free(image_data);
        free(payload);
        return 1;
    }

    fwrite(header, 1, HEADER_SIZE, output_image);
    fwrite(image_data, 1, width * height * 3, output_image);

    // Cleanup
    fclose(input_image);
    fclose(output_image);
    free(image_data);
    free(payload);

    printf("Steganography successful!\n");

    return 0;
}