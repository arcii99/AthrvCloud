//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

// Function to calculate checksum of array
unsigned int calculate_checksum(unsigned int arr[], int len) {
    unsigned int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Input array and length from user
    int len;
    printf("Enter length of array: ");
    scanf("%d", &len);
    unsigned int arr[len];
    printf("Enter array elements: ");
    for (int i = 0; i < len; i++) {
        scanf("%u", &arr[i]);
    }

    // Calculate checksum
    unsigned int checksum = calculate_checksum(arr, len);
    printf("Checksum: %u\n", checksum);

    return 0;
}