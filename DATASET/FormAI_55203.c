//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize array
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Calculate sum of array elements
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }

    // Generate checksum
    int checksum = 255 - ((sum + 37) % 256);

    // Print checksum value
    printf("The checksum value is: %d\n", checksum);

    return 0;
}