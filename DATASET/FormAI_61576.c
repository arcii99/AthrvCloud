//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void quick_sort_async(int* arr, int left, int right);
void * quick_sort_thread(void * v_params);

struct SortParams {
    int * arr;
    int left;
    int right;
};

int main() {
    int arr[] = {5, 7, 0, 3, 2, 6, 8, 1, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    pthread_t sort_thread;
    struct SortParams params = {arr, 0, n - 1};
    pthread_create(&sort_thread, NULL, quick_sort_thread, (void *)&params);

    printf("Sorting in progress...\n\n");

    pthread_join(sort_thread, NULL);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quick_sort_async(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int i = left;
    int j = right;
    int pivot = arr[left + (right - left) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) {
        struct SortParams left_params = {arr, left, j};
        pthread_t left_thread;
        pthread_create(&left_thread, NULL, quick_sort_thread, (void *)&left_params);
    }
    if (right > i) {
        struct SortParams right_params = {arr, i, right};
        pthread_t right_thread;
        pthread_create(&right_thread, NULL, quick_sort_thread, (void *)&right_params);
    }
}

void * quick_sort_thread(void * v_params) {
    struct SortParams * params = (struct SortParams *)v_params;

    quick_sort_async(params->arr, params->left, params->right);

    pthread_exit(NULL);
}