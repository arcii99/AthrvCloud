//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n) {
    // Declare an array of lists and initialize all of them to NULL
    int bucket[10][n];
    int count[10] = {0};
    
    // Divide the elements of the given array into buckets
    for (int i = 0; i < n; i++) {
        int index = 10 * array[i];
        bucket[index][count[index]++] = array[i];
    }
   
    // Apply insertion sort to sort the elements of each bucket
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < count[i]; j++) {
            int key = bucket[i][j], k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }
    
    // Merge sorted buckets back into original array 
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            array[index++] = bucket[i][j];
        }
    }
}

int main() {
    // Declare and initialize an array of integers to be sorted
    int array[] = {28, 12, 50, 6, 3, 29, 34, 24, 21, 1};
    int n = sizeof(array) / sizeof(array[0]);
    
    // Print the original unsorted array
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Sort the array using Bucket Sort algorithm
    bucket_sort(array, n);
    
    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}