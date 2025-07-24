//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUCKET_SIZE 1000

int arr[BUCKET_SIZE];
int bucket[MAX_THREADS][BUCKET_SIZE];

typedef struct _bucket_data {
    int index;
    int thread_id;
} bucket_data;

void* sort_bucket(void* bd) {
    bucket_data* data = (bucket_data*) bd;
    int thread_id = data->thread_id;
    int index = data->index;

    int i, j;
    for (i = 0; i < BUCKET_SIZE; i++) {
        if (bucket[thread_id][i] < index * MAX_THREADS || bucket[thread_id][i] >= (index + 1) * MAX_THREADS)
            continue;

        for (j = i + 1; j < BUCKET_SIZE; j++) {
            if (bucket[thread_id][j] < index * MAX_THREADS || bucket[thread_id][j] >= (index + 1) * MAX_THREADS)
                continue;

            if (bucket[thread_id][i] > bucket[thread_id][j]) {
                int temp = bucket[thread_id][i];
                bucket[thread_id][i] = bucket[thread_id][j];
                bucket[thread_id][j] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    int i, j, k;

    printf("Unsorted array:\n");
    for (i = 0; i < BUCKET_SIZE; i++) {
        arr[i] = rand() % 10000;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < MAX_THREADS; j++) {
            if (arr[i] >= j * MAX_THREADS && arr[i] < (j + 1) * MAX_THREADS) {
                for (k = 0; k < BUCKET_SIZE; k++) {
                    if (bucket[j][k] == 0) {
                        bucket[j][k] = arr[i];
                        break;
                    }
                }
                break;
            }
        }
    }

    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        bucket_data* data = (bucket_data*) malloc(sizeof(bucket_data));
        data->index = i;
        data->thread_id = i;
        pthread_create(&threads[i], NULL, sort_bucket, (void*) data);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sorted array:\n");
    for (i = 0; i < MAX_THREADS; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (bucket[i][j] == 0)
                break;
            printf("%d ", bucket[i][j]);
        }
    }

    printf("\n");

    return 0;
}