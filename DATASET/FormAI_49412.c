//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#define BUCKET_SIZE 10

// Function to find maximum value in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to implement Bucket sort algorithm
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucket[BUCKET_SIZE][BUCKET_SIZE] = {0};
    int bucket_count[BUCKET_SIZE] = {0};

    // Assigning elements into respective buckets
    for(int i = 0; i < n; i++) {
        int index = (arr[i] * (BUCKET_SIZE-1)) / max;
        bucket[index][bucket_count[index]++] = arr[i];
    }

    // Applying insertion sort on individual buckets
    for(int i = 0; i < BUCKET_SIZE; i++) {
        for(int j = 0; j < bucket_count[i]; j++) {
            int k = j-1;
            int key = bucket[i][j];
            while(k >= 0 && bucket[i][k] > key) {
               bucket[i][k+1] = bucket[i][k];
               k--;
            }
            bucket[i][k+1] = key;
        }
    }

    // Concatenating the buckets to form sorted array
    int index = 0;
    for(int i = 0; i < BUCKET_SIZE; i++) {
        for(int j = 0; j < bucket_count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

// Main function to test the program
int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    printf("Array before sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nArray after sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}