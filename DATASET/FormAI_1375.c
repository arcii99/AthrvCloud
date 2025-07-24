//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[512];
    printf("Enter the data stream (in hexadecimal): ");
    fgets(input, 512, stdin);

    // Remove any newline characters from input
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = 0;
        len--;
    }

    unsigned int checksum = 0;
    int i;
    for (i = 0; i < len; i += 2) {
        // Combine two adjacent hexits into a single byte
        unsigned int byte = 0;
        sscanf(&input[i], "%02x", &byte);

        checksum += byte;
        // If the checksum overflows, wrap it around
        if (checksum > 0xff) {
            checksum = checksum & 0xff;
            checksum += 1;
        }
    }

    // Calculate the complement of the checksum (two's complement)
    checksum = (unsigned char)(~checksum);

    printf("Checksum: 0x%02x\n", checksum);

    return 0;
}