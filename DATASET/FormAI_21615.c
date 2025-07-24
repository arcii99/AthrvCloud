//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_USED 8

typedef unsigned char byte;

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <carrier> <data> <output>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open carrier image file for reading
    FILE *carrier_file = fopen(argv[1], "rb");
    if (carrier_file == NULL) {
        fprintf(stderr, "Failed to open carrier file\n");
        exit(EXIT_FAILURE);
    }

    // Open data file for reading
    FILE *data_file = fopen(argv[2], "rb");
    if (data_file == NULL) {
        fclose(carrier_file);
        fprintf(stderr, "Failed to open data file\n");
        exit(EXIT_FAILURE);
    }
    
    // Open output file for writing
    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        fclose(carrier_file);
        fclose(data_file);
        fprintf(stderr, "Failed to open output file\n");
        exit(EXIT_FAILURE);
    }

    byte carrier_byte, data_byte, output_byte;
    int data_bit;

    // Read carrier file one byte at a time and hide data in the least significant bit
    while (fread(&carrier_byte, sizeof(byte), 1, carrier_file) == 1) {
        for (int i = 0; i < BYTES_USED; i++) {
            // Read in one bit from the data file
            if (fread(&data_byte, sizeof(byte), 1, data_file) == 1) {
                data_bit = (data_byte >> (BYTES_USED - 1)) & 1;
            } else {
                data_bit = 0;
            }

            // Modify the least significant bit of the carrier byte to hide the data bit
            carrier_byte &= ~(1 << i);
            carrier_byte |= (data_bit << i);

            // Write carrier byte to output file
            fwrite(&carrier_byte, sizeof(byte), 1, output_file);
        }
    }

    // Copy any remaining bytes from the carrier file to output file
    while (fread(&carrier_byte, sizeof(byte), 1, carrier_file) == 1) {
        fwrite(&carrier_byte, sizeof(byte), 1, output_file);
    }

    fclose(carrier_file);
    fclose(data_file);
    fclose(output_file);
    printf("Data successfully hidden!\n");
    return EXIT_SUCCESS;
}