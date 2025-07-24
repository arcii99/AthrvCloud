//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: calm
#include <stdio.h>

int main() {
    int data[100], checksum = 0, checksum_complement, length, i;

    // Read the length of the data
    printf("Enter the length of the data: ");
    scanf("%d", &length);

    // Read the data
    printf("Enter the data:\n");
    for (i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate the checksum
    for (i = 0; i < length; i++) {
        checksum += data[i];
    }
    checksum = checksum % 256;

    // Calculate the checksum complement
    checksum_complement = 255 - checksum;

    // Print the checksum and checksum complement
    printf("Checksum: %d\n", checksum);
    printf("Checksum complement: %d\n", checksum_complement);

    return 0;
}