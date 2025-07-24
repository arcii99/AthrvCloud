//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>

// Define a function to calculate checksum
int calculateChecksum(unsigned char message[], int length) {
    int sum = 0;
    // Do a simple addition of all the bytes in the message
    for (int i = 0; i < length; i++) {
        sum += message[i];
    }
    // Return the one's complement of the sum as the checksum
    return ~sum;
}

int main() {
    unsigned char message[] = {0x08, 0x01, 0x02, 0x03, 0x04, 0x05};
    int length = sizeof(message) / sizeof(message[0]);
    int checksum = calculateChecksum(message, length);
    printf("Checksum of message is: %x\n", checksum);
    return 0;
}