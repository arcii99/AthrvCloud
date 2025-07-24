//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>

int main() {
    int data[20], checksum = 0, i, n;

    printf("Enter the number of data bytes: ");
    scanf("%d", &n);

    printf("\nEnter the data bytes:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    for (i = 0; i < n; i++) {
        checksum += data[i];
    }

    checksum = ~checksum & 0xFF; // One's compliment and truncate to 8 bits

    printf("\nChecksum: %02X\n", checksum);

    return 0;
}