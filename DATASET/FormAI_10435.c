//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>

// Recursive function to calculate checksum
int calculateChecksum(int arr[], int size, int sum) {
    // Base case
    if (size == 0) {
        return sum;
    }
    // Recursive case
    sum += arr[size-1];
    return calculateChecksum(arr, size-1, sum);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;

    // Calculate checksum recursively
    sum = calculateChecksum(arr, 5, sum);

    printf("Checksum: %d", sum);

    return 0;
}