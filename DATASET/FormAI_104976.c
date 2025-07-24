//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

// Function to find the maximum possible sum for a given set of elements
int maxSum(int arr[], int n, int k) {
    bubbleSort(arr, n); // Sort the array
    int sum = 0, i;
    for (i = n-1; i >= n-k; i--)
        sum += arr[i]; // Add the k largest elements to the sum
    return sum;
}

// Driver code
int main() {
    int arr[] = {2, 6, 1, 8, 4, 10, 7}, k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = maxSum(arr, n, k);
    printf("Maximum possible sum for selecting %d elements is %d\n", k, max);
    return 0;
}