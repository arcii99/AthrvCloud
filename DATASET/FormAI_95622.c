//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SIZE 10 // Define size of data structure
#define MAX_THREAD 4 // Define number of threads

int array[SIZE]; // Define data structure

// Generate random integers to fill data structure
void generateRandom() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }
}

// Display data structure
void display() {
    printf("Data Structure: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Bubble sort algorithm to sort data structure
void bubbleSort() {
    int i, j, temp;
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Thread function
void *sortThread(void *arg) {
    int thread_num = *(int *)arg;
    int start = thread_num * (SIZE / MAX_THREAD);
    int end = start + (SIZE / MAX_THREAD);
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    pthread_exit(NULL);
}

// Main function
int main() {
    pthread_t threads[MAX_THREAD];
    int thread_nums[MAX_THREAD];
    generateRandom();
    printf("Before Sorting: ");
    display();
    for (int i = 0; i < MAX_THREAD; i++) {
        thread_nums[i] = i;
        pthread_create(&threads[i], NULL, sortThread, &thread_nums[i]);
    }
    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }
    bubbleSort();
    printf("After Sorting: ");
    display();
    return 0;
}