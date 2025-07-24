//FormAI DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h> 

// Function to perform counting sort 
void countingSort(int arr[], int n, int exp, int base) { 
    int output[n]; // output array
    int count[base]; 
    int i; 

    // Initialize count array to 0
    for (i = 0; i < base; i++) 
        count[i] = 0; 

    // Count the number of occurences of each element
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % base]++; 

    // Change count[i] so that it now contains actual position of this digit in output[]
    for (i = 1; i < base; i++) 
        count[i] += count[i - 1]; 

    // Build the output array
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % base] - 1] = arr[i]; 
        count[(arr[i] / exp) % base]--; 
    } 

    // Copy the output array back to arr[]
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

// Radix sort function 
void radixSort(int arr[], int n, int base) { 
    // Find the maximum number to know the number of digits
    int max = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 

    // Perform counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= base) 
        countingSort(arr, n, exp, base); 
} 

int main() { 
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    radixSort(arr, n, 10); 

    printf("Sorted array: \n"); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    return 0; 
}