//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>

// Function to calculate the checksum
int calculateChecksum(int numArray[], int size) {
    int i, sum = 0;

    // Calculate the sum of all elements in the array
    for (i = 0; i < size; i++) {
        sum += numArray[i];
    }

    // Return the checksum (sum modulo 255)
    return sum % 255;
}

int main() {
    int size, i, checksum;
    
    // Take input from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int numArray[size];
    
    // Take input for the array
    for (i = 0; i < size; i++) {
        printf("Enter the element no. %d: ", i+1);
        scanf("%d", &numArray[i]);
    }
    
    // Calculate the checksum
    checksum = calculateChecksum(numArray, size);
    
    // Print the result
    printf("The checksum of the array is: %d", checksum);

    return 0;
}