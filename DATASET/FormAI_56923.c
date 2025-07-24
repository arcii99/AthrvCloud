//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>

// Function to find the maximum number in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    // Create an array of numbers
    int arr[] = {10, 5, 20, 15, 25};

    // Find the maximum number using the findMax function
    int max = findMax(arr, 5);

    // Print the result
    printf("The maximum number is: %d", max);
    
    return 0;
}