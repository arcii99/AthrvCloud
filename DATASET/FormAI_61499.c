//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10

int arr[SIZE] = {100, 23, 47, 6, 87, 9, 1, 5, 32, 56};

typedef struct {
    int low;
    int high;
} parameters;

void merge(int low, int mid, int high) {
    int* temp = (int*) malloc(sizeof(int) * (high - low + 1));
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i++];
        } else {
            temp[k] = arr[j++];
        }
        k++;
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (k = 0, i = low; i <= high; ++i, ++k) {
        arr[i] = temp[k];
    }

    free(temp);
}

void* merge_sort(void* arg) {
    parameters* p = (parameters*) arg;
    int low = p->low;
    int high = p->high;

    if (low < high) {
        int mid = (low + high) / 2;

        parameters left = {low, mid};
        parameters right = {mid + 1, high};

        pthread_t left_thread, right_thread;

        pthread_create(&left_thread, NULL, merge_sort, &left);
        pthread_create(&right_thread, NULL, merge_sort, &right);

        pthread_join(left_thread, NULL);
        pthread_join(right_thread, NULL);

        merge(low, mid, high);
    }

    pthread_exit(NULL);
}

int main(void) {
    printf("Unsorted Array: ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    parameters params = {0, SIZE - 1};
    pthread_t tid;

    pthread_create(&tid, NULL, merge_sort, &params);
    pthread_join(tid, NULL);

    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}