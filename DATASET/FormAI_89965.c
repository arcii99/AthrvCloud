//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum value within an array
int findMax(int arr[], int n) {
    int maxValue = arr[0]; // Initialize max value to the first element in the array
    
    for(int i = 1; i < n; i++) {
        maxValue = max(maxValue, arr[i]);
    }
    
    return maxValue;
}

int main() {
    int arr[] = {10, 25, 6, 18, 32, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    int maxVal = findMax(arr, n);
    printf("\n\nMaximum value within the array: %d\n\n", maxVal);
    
    return 0;
}