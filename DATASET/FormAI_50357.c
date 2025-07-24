//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>

// Function to calculate checksum
int calculateChecksum(int arr[], int size) {
    int sum = 0;
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    return sum;
}

int main() {
    // Input array from user
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Calculate the checksum
    int checksum = calculateChecksum(arr, size);
    
    // Print the results
    printf("Checksum: %d\n", checksum);
    
    return 0;
}