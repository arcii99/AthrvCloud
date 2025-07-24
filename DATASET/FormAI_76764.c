//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>

int main() {
    int data[100], sum = 0, checksum = 0;
    int length, i;

    printf("Enter the length of the data: ");
    scanf("%d", &length);

    printf("Enter the data (separated by spaces): ");
    for (i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }

    // Add up all the values in the data
    for (i = 0; i < length; i++) {
        sum += data[i];
    }

    // Calculate the checksum
    checksum = 255 - sum;

    printf("\nChecksum = %d\n", checksum);

    return 0;
}