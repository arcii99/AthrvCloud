//FormAI DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort algorithm
void bubble_sort(int arr[], int n) {
    // Outer loop to iterate through each element in the array
    for(int i = 0; i < n; i++) {
        // Inner loop to compare adjacent elements and swap if necessary
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print the contents of an array
void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    print_array(arr, n);
    
    bubble_sort(arr, n);
    
    printf("Sorted array: ");
    print_array(arr, n);
    
    return 0;
}