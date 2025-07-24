//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 10

void print_array(int arr[]);
void bucket_sort(int arr[], int n);

void print_array(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {
    // Create buckets
    int buckets[BUCKET_SIZE][BUCKET_SIZE] = {0};
    
    // Distribute elements
    for (int i = 0; i < n; i++) {
        int index = BUCKET_SIZE * arr[i] / (n + 1);
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[index][j] == 0) {
                buckets[index][j] = arr[i];
                break;
            }   
        }   
    }

    // Sort buckets and merge them
    int k = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int size = 0;
        while (buckets[i][size] != 0) {
            size++;
        }
        
        // Sort using bubble sort
        for (int j = 0; j < size - 1; j++) {
            for (int l = 0; l < size - j - 1; l++) {
                if (buckets[i][l] > buckets[i][l + 1]) {
                    int temp = buckets[i][l];
                    buckets[i][l] = buckets[i][l + 1];
                    buckets[i][l + 1] = temp;
                }
            }
        }

        for (int j = 0; j < size; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main() {
    int arr[ARRAY_SIZE] = {12, 14, 9, 8, 2, 10, 12, 11, 7, 9};
    printf("Original array: ");
    print_array(arr);

    bucket_sort(arr, ARRAY_SIZE);
    printf("Sorted array: ");
    print_array(arr);

    return 0;
}