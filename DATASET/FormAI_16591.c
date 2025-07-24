//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: decentralized
#include <stdio.h>

int main() {
    int nums[50], checksum = 0;
    int size, i;

    printf("Enter the size of data (maximum 50 bytes): ");
    scanf("%d", &size);

    printf("Enter the data (one byte at a time, in decimal): ");
    for (i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
        checksum += nums[i];
    }

    // Perform the one's complement
    checksum = ~checksum;
    printf("Checksum (one's complement): %d\n", checksum);

    return 0;
}