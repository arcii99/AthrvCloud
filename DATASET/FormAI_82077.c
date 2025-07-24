//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
// Program to sort an array using bubble sort in a multiplayer style

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 20

int array[ARRAY_SIZE] = {4, 2, 10, 3, 1, 7, 8, 5, 6, 19, 15, 12, 11, 18, 20, 17, 16, 13, 9, 14};

void printArray() {
    printf("[ ");
    for(int i = 0; i < ARRAY_SIZE; i++)
      printf("%d ", array[i]);
    printf("]\n");
}

void *sort(void *arg) {
    int start = *((int *)arg);
    int end = start + (ARRAY_SIZE/2) - 1;

    for(int i = start; i <= end; i++) {
        for(int j = start; j <= end-i-1; j++) {
            if(array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    printf("Unsorted array: ");
    printArray();

    pthread_t thread1, thread2;
    int start1 = 0;
    int start2 = ARRAY_SIZE/2;

    pthread_create(&thread1, NULL, sort, &start1);
    pthread_create(&thread2, NULL, sort, &start2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Sorted array: ");
    printArray();

    return 0;
}