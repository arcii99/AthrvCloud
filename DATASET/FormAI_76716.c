//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int arr[ARRAY_SIZE] = {9, 2, 7, 1, 6, 5, 3, 8, 10, 4};

typedef struct {
    int start_index;
    int end_index;
} sort_data_t;

void *sort_thread(void *param) {
    int start_index = ((sort_data_t*)param)->start_index;
    int end_index = ((sort_data_t*)param)->end_index;
    
    int i, j, temp;
    for (i = start_index; i < end_index; i++) {
        for (j = i+1; j < end_index; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    sort_data_t data[2];
    
    int i;
    
    // print unsorted array
    printf("Unsorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // initialize thread data
    data[0].start_index = 0;
    data[0].end_index = ARRAY_SIZE / 2;
    data[1].start_index = ARRAY_SIZE / 2;
    data[1].end_index = ARRAY_SIZE;
    
    // create threads and sort
    for (i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, sort_thread, &data[i]);
    }
    
    // wait for threads to finish
    for (i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // merge sorted arrays
    int merged_arr[ARRAY_SIZE];
    int index1 = 0, index2 = ARRAY_SIZE / 2, index3 = 0;
    while (index1 < ARRAY_SIZE/2 && index2 < ARRAY_SIZE) {
        if (arr[index1] < arr[index2]) {
            merged_arr[index3++] = arr[index1++];
        } else {
            merged_arr[index3++] = arr[index2++];
        }
    }
    while (index1 < ARRAY_SIZE/2) {
        merged_arr[index3++] = arr[index1++];
    }
    while (index2 < ARRAY_SIZE) {
        merged_arr[index3++] = arr[index2++];
    }
    
    // print sorted array
    printf("Sorted array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", merged_arr[i]);
    }
    printf("\n");
    
    return 0;
}