//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdint.h>

/*Calculates the checksum of a given buffer*/
uint8_t calculate_checksum(uint8_t buf[], uint32_t len) {
    uint16_t sum = 0;
    uint32_t i = 0;

    /*Add all bytes of the buffer*/
    for (i = 0; i < len; i++) {
        sum += buf[i];
    }

    /*Fold the upper 16 bits into the lower*/
    while (sum >> 16) {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    /*Return the one's complement of the result*/
    return (uint8_t)(~sum);
}

int main() {
    uint8_t buffer[1024];
    uint32_t len = 0;
    uint8_t checksum = 0;

    printf("Enter the buffer to calculate the checksum:\n");

    /*Read the buffer from user*/
    while (1) {
        int c = getchar();

        if (c == EOF || c == '\n') {
            break;
        }

        if (len < 1024) {
            buffer[len++] = (uint8_t)c;
        }
    }

    /*Calculate the checksum*/
    checksum = calculate_checksum(buffer, len);

    /*Print the checksum*/
    printf("Checksum: 0x%X\n", checksum);

    return 0;
}