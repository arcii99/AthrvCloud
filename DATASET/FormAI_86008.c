//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 4
#define ARRAY_SIZE 16

int array[ARRAY_SIZE] = {9, 7, 2, 10, 0, 6, 4, 3, 1, 8, 11, 15, 14, 12, 13, 5};

typedef struct {
    int start_index;
    int end_index;
} thread_args;

void *sort(void *args) {
    thread_args *t_args = (thread_args*)args;
    int start = t_args->start_index;
    int end = t_args->end_index;
    int i, j, temp;

    for (i = start; i < end - 1; i++) {
        for (j = start; j < end - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N_THREADS];
    thread_args args[N_THREADS];
    int i;

    int segment_size = ARRAY_SIZE / N_THREADS;

    // Create threads and assign data to each thread
    for (i = 0; i < N_THREADS; i++) {
        args[i].start_index = i * segment_size;
        args[i].end_index = (i + 1) * segment_size;
        pthread_create(&threads[i], NULL, sort, (void *)&args[i]);
    }

    // Wait for all threads to complete
    for (i = 0; i < N_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge arrays
    int *temp_array = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    int left = 0;
    int mid = segment_size;
    int right = mid * 2;
    int k = 0;

    while (left < ARRAY_SIZE) {
        while (left < mid && right < ARRAY_SIZE) {
            if (array[left] < array[right]) {
                temp_array[k++] = array[left++];
            } else {
                temp_array[k++] = array[right++];
            }
        }

        while (left < mid) {
            temp_array[k++] = array[left++];
        }

        while (right < ARRAY_SIZE) {
            temp_array[k++] = array[right++];
        }

        left = right;
        mid = right + segment_size;
        right = mid + segment_size;

        if (mid > ARRAY_SIZE) {
            mid = ARRAY_SIZE;
        }

        if (right > ARRAY_SIZE) {
            right = ARRAY_SIZE;
        }
    }

    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = temp_array[i];
    }

    free(temp_array);

    // Print sorted array
    printf("Sorted Array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}