//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>

// Function to calculate CRC32 checksum
unsigned int crc32(char *message) {
    unsigned int i, j, byte;
    unsigned int crc = 0xffffffff;

    i = 0;
    while (message[i] != 0) {
        byte = message[i];            // Get next byte
        crc = crc ^ byte;

        for (j = 0; j < 8; j++) {     // Do eight times:
            if (crc & 0x00000001) {   // If LSB is set
                crc = (crc >> 1) ^ 0xEDB88320; // Shift and XOR with polynomial
            } else {
                crc = crc >> 1;       // If LSB is not set, just shift
            }
        }
        i++;
    }
    return ~crc;                      // One's complement of the result
}

int main() {
    char message[100];
    unsigned int crc;

    printf("Enter a message: ");
    scanf("%[^\n]", message);          // Read input string

    crc = crc32(message);              // Calculate CRC32 checksum
    printf("CRC32 checksum = %08X\n", crc);

    return 0;
}