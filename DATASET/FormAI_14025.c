//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
// Welcome to the Checksum Calculator program!
// This program helps you calculate a 16-bit checksum for a set of data you provide.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define DATA_SIZE 1024    // Maximum size of data
#define CHECKSUM_SIZE 2   // Size of checksum in bytes

// ASCII string to binary string conversion
void ascii_to_bin(char* in, char* out, int data_size) {
    for (int i = 0; i < data_size; i++) {
        for (int j = 7; j >= 0; j--) {
            out[(i * 8) + (7 - j)] = ((in[i] >> j) & 1) + '0';
        }
    }
}

// Binary string to ASCII string conversion
void bin_to_ascii(char* in, char* out, int data_size) {
    int byte_count = data_size / 8;

    for (int i = 0; i < byte_count; i++) {
        uint8_t byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= ((in[(i * 8) + j] - '0') << (7 - j));
        }
        out[i] = byte;
    }
}

// Calculate checksum
void calculate_checksum(char* data, int data_size, char* checksum) {
    char bin_data[DATA_SIZE * 8] = {0};
    ascii_to_bin(data, bin_data, data_size);  // Convert data to binary

    // Calculate checksum
    uint16_t sum = 0;
    for (int i = 0; i < data_size * 8; i += 16) {
        sum += (uint16_t)strtol(&bin_data[i], NULL, 2);
    }
    sum = (sum & 0xFFFF) + (sum >> 16);

    // Invert the sum to obtain the checksum
    sum = ~sum;
    checksum[0] = (sum >> 8) & 0xFF;  // Extract high byte
    checksum[1] = sum & 0xFF;         // Extract low byte
}

int main(void) {
    char data[DATA_SIZE] = {0};        // Input data
    char checksum[CHECKSUM_SIZE] = {0};  // Checksum

    // Get user input
    printf("Please enter the data to calculate the checksum for:\n");
    fgets(data, DATA_SIZE, stdin);

    // Calculate checksum
    calculate_checksum(data, strlen(data), checksum);

    // Print checksum
    char hex_checksum[CHECKSUM_SIZE * 2] = {0};
    for (int i = 0; i < CHECKSUM_SIZE; i++) {
        sprintf(&hex_checksum[i * 2], "%02x", checksum[i]);
    }
    printf("The checksum is: %s\n", hex_checksum);

    // Convert checksum to binary and print
    char bin_checksum[CHECKSUM_SIZE * 8] = {0};
    ascii_to_bin(hex_checksum, bin_checksum, CHECKSUM_SIZE * 2);
    printf("In binary, the checksum is: %s\n", bin_checksum);

    // Convert checksum from binary back to ASCII and print
    char ascii_checksum[CHECKSUM_SIZE] = {0};
    bin_to_ascii(bin_checksum, ascii_checksum, CHECKSUM_SIZE * 8);
    printf("In ASCII, the checksum is: %s\n", ascii_checksum);

    return 0;
}