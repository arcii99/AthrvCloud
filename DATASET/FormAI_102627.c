//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>

// function to calculate the checksum using XOR operations
unsigned char checksum(unsigned char *str, int len) {
    unsigned char result = 0;
    for (int i = 0; i < len; i++) {
        result ^= str[i];
    }
    return result;
}

int main() {
    char data[] = "Hello, world!"; // the data to be checksummed
    int len = sizeof(data) - 1; // length of the data (minus the null terminator)

    // calculate the checksum
    unsigned char cksum = checksum((unsigned char*)data, len);

    // print the data and its checksum
    printf("Data: %s\nChecksum: %02X\n", data, cksum);

    return 0;
}