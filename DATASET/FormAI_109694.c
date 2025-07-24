//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>

// Function to calculate the checksum
unsigned char checksum(char *data, int length) {
    unsigned char sum = 0;
    int i;

    for (i = 0; i < length; i++) {
        sum += data[i];
    }

    return ~sum;
}

int main() {
    char data[] = "Hello, world!";
    int length = strlen(data);
    unsigned char sum;

    sum = checksum(data, length);
    printf("Checksum: %02X\n", sum);

    return 0;
}