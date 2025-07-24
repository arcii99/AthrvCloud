//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void Bucket_Sort(int array[], int n) {

    // Find maximum and minimum value in the array
    int max_val = array[0];
    int min_val = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }

    // Create buckets
    int bucket_size = 10;
    int num_buckets = ((max_val - min_val) / bucket_size) + 1;
    int buckets[num_buckets][n];
    int bucket_count[num_buckets];

    for (int i = 0; i < num_buckets; i++) {
        bucket_count[i] = 0;
    }

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (array[i] - min_val) / bucket_size;
        buckets[bucket_index][bucket_count[bucket_index]] = array[i];
        bucket_count[bucket_index]++;
    }

    // Sort buckets and merge them into original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        int bucket_len = bucket_count[i];
        int temp[bucket_len];
        for (int j = 0; j < bucket_len; j++) {
            temp[j] = buckets[i][j];
        }
        for (int j = 0; j < bucket_len - 1; j++) {
            for (int k = 0; k < bucket_len - 1 - j; k++) {
                if (temp[k] > temp[k+1]) {
                    int swap = temp[k];
                    temp[k] = temp[k+1];
                    temp[k+1] = swap;
                }
            }
        }
        for (int j = 0; j < bucket_len; j++) {
            array[index] = temp[j];
            index++;
        }
    }
}

int main() {
    printf("Bucket Sort Implementation Example Program\n");

    int array[10] = {35, 68, 21, 89, 44, 13, 82, 76, 45, 10};
    int n = 10;

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    Bucket_Sort(array, n);

    printf("\n\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}