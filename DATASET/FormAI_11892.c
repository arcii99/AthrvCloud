//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

uint16_t calculate_checksum(uint16_t *buffer, size_t length);

int main()
{
    uint16_t message[] = { 0x0102, 0x0304, 0x0506, 0x0708, 0x090a };
    size_t message_length = sizeof(message)/sizeof(message[0]);

    uint16_t checksum = calculate_checksum(message, message_length);
    printf("Message: ");
    for (size_t i = 0; i < message_length; ++i)
    {
        printf("%04" PRIx16 " ", message[i]);
    }
    printf("\n");
    printf("Checksum: %04" PRIx16 "\n", checksum);

    return EXIT_SUCCESS;
}

uint16_t calculate_checksum(uint16_t *buffer, size_t length)
{
    uint32_t sum = 0;

    // Calculate the sum of 16-bit words
    for (size_t i = 0; i < length; ++i)
    {
        sum += buffer[i];
    }

    // Fold the sum into 16 bits
    while (sum >> 16)
    {
        sum = (sum & 0xffff) + (sum >> 16);
    }

    // Take the 1's complement of the sum
    sum = ~sum;

    return (uint16_t)sum;
}