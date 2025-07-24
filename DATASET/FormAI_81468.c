//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the bucket sort function
void bucket_sort(int arr[], int n) {
    // Find the maximum value in the array
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    
    // Create the buckets and initialize them to zero
    int bucket[10][n];
    int bucket_count[10] = {0};
    
    // Distribute the elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (10 * arr[i]) / (max_value + 1);
        bucket[bucket_index][bucket_count[bucket_index]] = arr[i];
        bucket_count[bucket_index]++;
    }
    
    // Sort the elements within each bucket
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < bucket_count[i]; j++) {
            int temp = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > temp) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = temp;
        }
    }
    
    // Concatenate the sorted elements from the buckets
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }
}

// Define the main function
int main() {
    // Create an array to be sorted
    int arr[] = {23, 8, 4, 16, 42, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array using bucket sort
    bucket_sort(arr, n);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}