//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(){

    unsigned char bytes[128];     // An array of bytes to be input by the user
    unsigned int checksum = 0;    // The checksum value
    int num_bytes = 0;            // The number of bytes input by the user
    int i = 0;                    // Loop variable

    printf("Enter bytes (up to 128) to find their 8-bit checksum:\n");

    // Read in bytes up to 128
    while (num_bytes < 128) {
        int b = getchar();
        if (b == '\n' || b == EOF) {
            break;
        }
        bytes[num_bytes++] = b;
    }

    // Calculate the checksum
    for (i = 0; i < num_bytes; i++) {
        checksum += bytes[i];
    }

    // Print the checksum
    printf("The checksum of the bytes is %u\n", checksum);

    return 0;
}