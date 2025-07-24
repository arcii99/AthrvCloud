//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define POLY 0x1021

/* CRC16-CCITT checksum calculation function */
unsigned short crc16_ccitt(unsigned char *data, unsigned int length)
{
    unsigned short crc = 0;
    int i, j;

    for (i = 0; i < length; i++) {
        crc ^= (unsigned short)data[i] << 8;
        for (j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ POLY;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main(int argc, char **argv)
{
    /* read user input */
    char *input = NULL;
    size_t input_len = 0;
    printf("Enter the data to checksum: ");
    getline(&input, &input_len, stdin);

    /* calculate the checksum using CRC16-CCITT */
    unsigned short checksum = crc16_ccitt((unsigned char *)input, strlen(input));

    /* print the result */
    printf("Checksum: 0x%04x\n", checksum);

    /* clean up */
    free(input);
    return 0;
}