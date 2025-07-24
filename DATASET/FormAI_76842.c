//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

#define BUCKET_SIZE 10

// Function to find maximum element in array
int findMax(int A[], int n) {
    int max = A[0], i;
    for(i = 1; i < n; i++) {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int A[], int n) {
    int i, j, k;
    int max_element = findMax(A, n);
    int bucket_count[BUCKET_SIZE];
    int **buckets;

    // Initialize bucket count to 0
    for(i = 0; i < BUCKET_SIZE; i++)
        bucket_count[i] = 0;

    // Create array of buckets
    buckets = (int **)malloc(sizeof(int *) * BUCKET_SIZE);
    for(i = 0; i < BUCKET_SIZE; i++)
        buckets[i] = (int *)malloc(sizeof(int) * n);

    // Initialize each bucket with 0
    for(i = 0; i < BUCKET_SIZE; i++) {
        for(j = 0; j < n; j++)
            buckets[i][j] = 0;
    }

    // Fill buckets with elements from array
    for(i = 0; i < n; i++) {
        int bucket_index = (BUCKET_SIZE * A[i]) / (max_element + 1);
        buckets[bucket_index][bucket_count[bucket_index]++] = A[i];
    }

    // Sort each bucket using insertion sort
    for(i = 0; i < BUCKET_SIZE; i++) {
        for(j = 0; j < bucket_count[i]; j++) {
            int temp = buckets[i][j];
            k = j - 1;
            while(k >= 0 && buckets[i][k] > temp) {
                buckets[i][k+1] = buckets[i][k];
                k = k - 1;
            }
            buckets[i][k+1] = temp;
        }
    }

    // Concatenate all the buckets back into original array
    int index = 0;
    for(i = 0; i < BUCKET_SIZE; i++) {
        for(j = 0; j < bucket_count[i]; j++) {
            A[index++] = buckets[i][j];
        }
    }

    // Free memory allocated to buckets
    for(i = 0; i < BUCKET_SIZE; i++)
        free(buckets[i]);
    free(buckets);
}

// Function to print elements of array
void printArray(int A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int A[] = {31, 7, 10, 22, 45, 14, 38, 65, 3, 56};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Original array : ");
    printArray(A, n);
    
    bucketSort(A, n);
    
    printf("Bucket sorted array : ");
    printArray(A, n);
    return 0;
}