//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define SIZE 10

int arr[SIZE];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void* sort(void* ptr) {
    int* idx = (int*)ptr;
    for (int i = (*idx); i < SIZE - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t tid1, tid2;
    
    // creating random array
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
    }
    
    printf("Unsorted Array: ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int idx1 = 0, idx2 = 1;
    
    // calling the sort function through threads
    if (pthread_create(&tid1, NULL, sort, &idx1)) {
        perror("pthread_create error");
        exit(1);
    }
    
    if (pthread_create(&tid2, NULL, sort, &idx2)) {
        perror("pthread_create error");
        exit(1);
    }
    
    if (pthread_join(tid1, NULL)) {
        perror("pthread_join error");
        exit(1);
    }
    
    if (pthread_join(tid2, NULL)) {
        perror("pthread_join error");
        exit(1);
    }
    
    printf("Sorted Array: ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}