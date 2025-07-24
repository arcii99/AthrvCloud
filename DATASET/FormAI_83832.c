//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ELEMENTS 1000

int array[MAX_ELEMENTS];

typedef struct {
    int start_idx;
    int end_idx;
} sort_params_t;

void merge(int start_idx, int mid_idx, int end_idx) {
    int left_idx = start_idx;
    int right_idx = mid_idx;
    int temp_array[end_idx - start_idx];
    int temp_idx = 0;

    while (left_idx < mid_idx && right_idx < end_idx) {
        if (array[left_idx] < array[right_idx]) {
            temp_array[temp_idx++] = array[left_idx++];
        } else {
            temp_array[temp_idx++] = array[right_idx++];
        }
    }

    while (left_idx < mid_idx) {
        temp_array[temp_idx++] = array[left_idx++];
    }
    while (right_idx < end_idx) {
        temp_array[temp_idx++] = array[right_idx++];
    }

    for (int i = 0; i < temp_idx; i++) {
        array[start_idx + i] = temp_array[i];
    }
}

void* sort_worker(void* void_param) {
    sort_params_t* params = (sort_params_t*) void_param;
    int start_idx = params->start_idx;
    int end_idx = params->end_idx;

    if (end_idx - start_idx <= 1) {
        return NULL;
    }

    int mid_idx = (start_idx + end_idx) / 2;

    sort_params_t left_params = {start_idx, mid_idx};
    sort_params_t right_params = {mid_idx, end_idx};
    
    pthread_t left_thread, right_thread;
    pthread_create(&left_thread, NULL, sort_worker, &left_params);
    pthread_create(&right_thread, NULL, sort_worker, &right_params);

    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    merge(start_idx, mid_idx, end_idx);
    return NULL;
}

void parallel_sort(int n) {
    sort_params_t params = {0, n};
    sort_worker(&params);
}

void print_array(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    srand(42);

    int n = 100;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000;
    }

    printf("Unsorted:\n");
    print_array(n);

    parallel_sort(n);

    printf("Sorted:\n");
    print_array(n);

    return 0;
}