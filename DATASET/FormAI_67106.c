//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

// Function to find the minimum and maximum element from the given array
void findMinMax(int arr[], int n, int* min, int* max) {
    // Initialize min and max variables
    *min = arr[0];
    *max = arr[0];
    
    // Loop through the array and update min and max variables
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i]; // update min value
        }
        if (arr[i] > *max) {
            *max = arr[i]; // update max value
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min, max;
    findMinMax(arr, n, &min, &max);
    
    printf("The minimum element of the array is: %d\n", min);
    printf("The maximum element of the array is: %d\n", max);
    
    return 0;
}