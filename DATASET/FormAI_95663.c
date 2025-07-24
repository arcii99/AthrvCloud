//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int array[], int n) {
    int i, j, count;
    int *temp = NULL;
    int min_value = array[0];
    int max_value = array[0];

    for (i = 1; i < n; i++) {
        if (min_value > array[i]) {
            min_value = array[i];
        } else if (max_value < array[i]) {
            max_value = array[i];
        }
    }

    int num_buckets = (max_value - min_value) / n + 1;
    int **buckets = (int **) calloc(num_buckets, sizeof(int *));

    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *) calloc(n, sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int bucket_index = (array[i] - min_value) / n;
        buckets[bucket_index][i] = array[i];
    }

    for (i = 0; i < num_buckets; i++) {
        temp = buckets[i];
        count = 0;

        for (j = 0; j < n; j++) {
            if (temp[j] != 0) {
                array[count++] = temp[j];
            }
        }
    }

    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }

    free(buckets);
}

int main() {
    srand(time(NULL));
    int array[100];
    int i, n = sizeof(array) / sizeof(array[0]);

    printf("The original array is: ");
    for (i = 0; i < n; i++) {
        array[i] = rand() % 1001;
        printf("%d ", array[i]);
    }

    bucket_sort(array, n);

    printf("\n\nThe sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return 0;
}