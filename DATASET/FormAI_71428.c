//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>

/**
 * This program calculates the 8-bit checksum
 * for a given message
 */

int main() {
    int i;
    char message[50];
    printf("Enter message (up to 50 characters): ");
    scanf("%s", message);

    int sum = 0;
    for (i = 0; message[i] != '\0'; i++) {
        sum += message[i];
    }

    // Checksum is the 2's complement of sum
    int checksum = ~(sum & 0xFF) + 1; 

    printf("Checksum: 0x%X\n", checksum);
    return 0;
}