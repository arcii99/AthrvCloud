//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include<stdio.h>

// Method to calculate checksum of given bytes
int calculateChecksum(unsigned char *msg,int bytes) {
    int sum = 0;

    // Add each byte to sum
    for (int i = 0; i < bytes; i++) {
        sum += (int)msg[i];
    }

    // Return the two's complement of sum
    return (~sum) + 1; 
}

int main() {
    unsigned char message[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int bytes = 5;

    // Call the checksum function
    int checksum = calculateChecksum(message, bytes);

    // Print the result
    printf("Checksum: %d (0x%X)\n", checksum, checksum);

    return 0;
}