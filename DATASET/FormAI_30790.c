//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define ARRAY_SIZE 1000
#define THREADS_NUM 4

int arr[ARRAY_SIZE];

void merge_sort(int start, int end);
void merge(int start, int mid, int end);
void* merge_sort_wrapper(void * param);

int main() {
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % ARRAY_SIZE;
    }

    pthread_t threads[THREADS_NUM];
    int len = ARRAY_SIZE / THREADS_NUM;
    int chunks[THREADS_NUM][2];

    for (int i = 0; i < THREADS_NUM; i++){
        int s = i * len;
        int e = (i + 1) * len - 1;
        chunks[i][0] = s;
        chunks[i][1] = e;
        pthread_create(&threads[i], NULL, merge_sort_wrapper, chunks[i]);
    }

    for (int i = 0; i < THREADS_NUM; i++){
        pthread_join(threads[i], NULL);
    }

    merge(0, len - 1, ARRAY_SIZE - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void* merge_sort_wrapper(void * param){
    int *temp = (int *) param;
    int start = temp[0];
    int end = temp[1];
    merge_sort(start, end);
    pthread_exit(NULL);
}

void merge_sort(int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, mid, end);
}

void merge(int start, int mid, int end) {
    int size = end - start + 1;
    int *temp = (int*)malloc(size * sizeof(int));

    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = start; i <= end; i ++) {
        arr[i] = temp[i - start];
    }

    free(temp);
}