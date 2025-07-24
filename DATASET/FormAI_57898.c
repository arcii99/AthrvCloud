//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Array of integers to sort
int array[] = {9, 5, 7, 1, 3, 2, 4, 6, 8};

// Forward declaration
void * thread_function(void *);

int main() {
    int i;
    pthread_t thread;

    // Create thread
    pthread_create(&thread, NULL, thread_function, (void *) NULL);

    // Sort array using bubble sort
    int n = sizeof(array) / sizeof(int);
    for(i = 0; i < n-1; i++) {
        int j;
        for(j = 0; j < n-i-1; j++) {
            if(array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    
    // Wait for thread to complete
    pthread_join(thread, NULL);

    // Print sorted array
    printf("Sorted Array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

// Thread function to print message
void * thread_function(void * arg) {
    printf("Thread is running!\n");
    pthread_exit(NULL);
}