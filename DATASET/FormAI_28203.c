//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define BUCKETS 5

int max(int *arr) {
    int max_val = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

void bucket_sort(int *arr) {
    int max_val = max(arr);
    int bucket_size = (max_val / BUCKETS) + 1;

    int **buckets = (int **) malloc(BUCKETS * sizeof(int *));
    for (int i = 0; i < BUCKETS; i++) {
        buckets[i] = (int *) malloc(N * sizeof(int));
    }

    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[j] >= i * bucket_size && arr[j] < (i + 1) * bucket_size) {
                for (int k = 0; k < N; k++) {
                    if (buckets[i][k] == 0) {
                        buckets[i][k] = arr[j];
                        break;
                    }
                }
            }
        }
    }

    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < N; j++) {
            if (buckets[i][j] > 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[N] = {5, 8, 10, 3, 1, 7, 9, 2, 4, 6};

    printf("Original array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr);

    printf("\nSorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}