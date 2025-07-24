//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to calculate the checksum
uint8_t checksum(uint8_t *data, size_t len) {
    uint8_t sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += data[i];
    }
    return ~sum + 1;
}

int main() {
    printf("Welcome to the Checksum Calculator v1.0!\n");

    // Get user input
    printf("Please enter a string of data to calculate the checksum:\n");
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Convert input to bytes
    size_t len = strlen(input);
    uint8_t *data = (uint8_t *) calloc(len, sizeof(uint8_t));
    for (size_t i = 0; i < len; i++) {
        data[i] = (uint8_t) input[i];
    }

    // Calculate checksum
    uint8_t sum = checksum(data, len);
    printf("Checksum: %02x\n", sum);

    // Free memory
    free(data);

    return 0;
}