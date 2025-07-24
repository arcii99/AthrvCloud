//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value in the array to be sorted
#define MAX_VALUE 100

// Define the size of each bucket
#define BUCKET_SIZE 10

// Define the number of buckets needed
#define NUM_BUCKETS ((MAX_VALUE / BUCKET_SIZE) + 1)

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using the bucket sort algorithm
void bucket_sort(int arr[], int n) {
    // Create an array of empty buckets
    int buckets[NUM_BUCKETS][BUCKET_SIZE] = {{0}};

    // Create an array to keep track of the number of elements in each bucket
    int bucket_size[NUM_BUCKETS] = {0};

    // Calculate the bucket index for each element in the array
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        buckets[bucket_index][bucket_size[bucket_index]] = arr[i];
        bucket_size[bucket_index]++;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 1; j < bucket_size[i]; j++) {
            int k = j;
            while (k > 0 && buckets[i][k - 1] > buckets[i][k]) {
                swap(&buckets[i][k - 1], &buckets[i][k]);
                k--;
            }
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < bucket_size[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test the bucket_sort function
int main() {
    printf("Welcome to the happy world of Bucket Sort!\n");

    int arr[] = {46, 72, 32, 88, 65, 12, 74, 31, 23, 56, 89, 90, 66, 77, 99, 44, 51, 85, 62, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    print_array(arr, n);

    bucket_sort(arr, n);

    printf("After sorting: ");
    print_array(arr, n);

    printf("Hooray! Our array is now sorted using the Bucket Sort algorithm.\n");

    return 0;
}