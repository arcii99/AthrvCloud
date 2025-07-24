//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>

int main() {
    int arr[10], sum = 0, checksum;
    
    // Taking user input for the array
    printf("Enter the array of 10 integers: ");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Calculating sum of the array
    for(int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    
    // Calculating checksum
    checksum = ~(sum % 256);
    
    // Printing the checksum
    printf("Checksum: %d", checksum);
    
    return 0;
}