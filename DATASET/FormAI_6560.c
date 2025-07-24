//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>

int main() {
    int i, checksum = 0, data[20];

    printf("Enter the data (up to 20 integers):\n");

    // Read input data
    for(i=0; i<20; i++) {
        if(scanf("%d", &data[i]) == EOF) break;
    }

    // Calculate the checksum
    for(i=0; i<20 && data[i] > -1; i++) {
        checksum += data[i];
    }

    // Negate the checksum
    checksum = ~(checksum - 1);

    // Print the checksum in hex
    printf("The checksum is 0x%04X\n", (unsigned short) checksum);

    return 0;
}