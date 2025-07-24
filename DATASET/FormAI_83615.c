//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15
#define BUCKET_SIZE 10

void print_array(int arr[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[N]) {
    int bucket[BUCKET_SIZE][N] = {0};
    int bucket_count[BUCKET_SIZE] = {0};
    int max_element = arr[0];

    // Determine maximum element
    for (int i = 1; i < N; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    // Distribute elements into buckets
    for (int i = 0; i < N; i++) {
        int bucket_index = arr[i] * BUCKET_SIZE / (max_element + 1);
        bucket[bucket_index][bucket_count[bucket_index]] = arr[i];
        bucket_count[bucket_index]++;
    }

    // Sort elements within each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            for (int k = j+1; k < bucket_count[i]; k++) {
                if (bucket[i][j] > bucket[i][k]) {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    // Merge sorted buckets into original array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }
}

int main() {
    srand(time(NULL));
    int arr[N];

    printf("Original array: ");
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
    print_array(arr);

    printf("Sorted array: ");
    bucket_sort(arr);
    print_array(arr);

    return 0;
}