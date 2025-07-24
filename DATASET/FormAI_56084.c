//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>

// Function to print array
void printArray(int arr[], int n) {
    printf("The sorted array is: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Custom sort function using bubble sort
void customSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Declare variables
    int arr[50], n;

    // Ask user for input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements in the array: ", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call custom sort function
    printf("Sorting the array using custom sort function...\n");
    customSort(arr, n);

    // Print sorted array
    printArray(arr, n);
    
    return 0;
}