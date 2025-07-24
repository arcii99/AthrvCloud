//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>

// Function to compute the checksum of a given array
int computeChecksum(int arr[], int n) {
    int sum = 0, i;
    
    // Loop through the entire array and sum up each element
    for (i = 0; i < n; i++) {
        sum += arr[i];
        
        // If the sum goes above 255 (maximum value that can be represented by 1 byte), then wrap it around to 0
        if (sum > 255) {
            sum = sum - 255;
        }
    }
    
    // Return the final checksum
    return sum;
}

int main() {
    int arr[] = {20, 25, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int checksum = computeChecksum(arr, n);
    
    // Print the checksum in hex format
    printf("The checksum of the array is: %X", checksum);
    
    return 0;
}