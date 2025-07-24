//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define N 50
#define MAX 1000

typedef struct {
    int start;
    int end;
} SortParams;

int arr[N];

void bubbleSort(int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void *sortThread(void *params) {
    SortParams *sortParams = (SortParams *)params;
    bubbleSort(sortParams->start, sortParams->end);
    pthread_exit(NULL);
}

void *mergeThread(void *params) {
    SortParams *sortParams = (SortParams *)params;
    merge(sortParams->start, (sortParams->start + sortParams->end) / 2, sortParams->end);
    pthread_exit(NULL);
}

int main() {
    srand(time(0));

    // Initialize array with random values
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % MAX;
    }

    printf("Original Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_t sortThreads[2];
    pthread_t mergeThread;

    SortParams sortParam1 = { 0, N / 2 };
    SortParams sortParam2 = { N / 2, N };

    // Sort two halves of the array asynchronously
    pthread_create(&sortThreads[0], NULL, sortThread, &sortParam1);
    pthread_create(&sortThreads[1], NULL, sortThread, &sortParam2);

    // Wait for the sort threads to finish
    pthread_join(sortThreads[0], NULL);
    pthread_join(sortThreads[1], NULL);

    SortParams mergeParam = { 0, N - 1 };

    // Merge the two sorted halves of the array asynchronously
    pthread_create(&mergeThread, NULL, mergeThread, &mergeParam);

    // Wait for the merge thread to finish
    pthread_join(mergeThread, NULL);

    printf("Sorted Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}