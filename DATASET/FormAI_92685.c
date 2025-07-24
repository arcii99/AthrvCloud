//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GENERATOR_POLYNOMIAL 0xD8
#define CHECKSUM_LENGTH 2

int calculate_checksum(unsigned char *message, int length);

int main(void) {
    unsigned char message[] = "Hello, world!";
    int length = strlen((char *) message);
    int checksum = calculate_checksum(message, length);

    printf("Original message: %s\n", message);
    printf("Checksum: %d\n", checksum);

    return 0;
}

int calculate_checksum(unsigned char *message, int length) {
    unsigned char checksum_value[CHECKSUM_LENGTH] = {0};
    unsigned char generator_polynomial = GENERATOR_POLYNOMIAL;

    for(int i = 0; i < length; i++) {
        unsigned char byte = message[i];

        for(int bit = 0; bit < 8; bit++) {
            unsigned char msb = byte & 0x80;

            for(int j = 0; j < CHECKSUM_LENGTH; j++) {
                unsigned char bitmask = (checksum_value[j] & 0x80) ? 1 : 0;
                checksum_value[j] <<= 1;
                checksum_value[j] |= bitmask;
            }

            if(msb) {
                checksum_value[CHECKSUM_LENGTH - 1] ^= generator_polynomial;
            }

            byte <<= 1;
        }
    }

    return (checksum_value[0] << 8) | checksum_value[1];
}