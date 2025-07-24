//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>

int main() {
    unsigned char buffer[1000];
    int i, sum = 0, length;

    printf("Enter the message: ");
    fgets(buffer, 1000, stdin);

    // Calculate the length of the message
    for (i = 0; buffer[i] != '\n'; i++) {
        sum += buffer[i];
    }

    length = i;

    // Calculate the checksum using 16-bit addition
    while (sum >> 16) {
        sum = (sum >> 16) + (sum & 0xFFFF);
    }

    unsigned short *checksum = (unsigned short *)&sum;

    // Output the message and the calculated checksum
    printf("\nMessage: %s", buffer);
    printf("Checksum: %04X\n", *checksum);

    return 0;
}