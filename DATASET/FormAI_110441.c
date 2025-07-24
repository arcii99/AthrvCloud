//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 

#define NUM_THREADS 4 // number of threads to create
#define ARRAY_SIZE 100 // size of array to be sorted

int array[ARRAY_SIZE]; // array to be sorted

/* function to swap two integers */
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

/* bubble sort algorithm */
void bubbleSort(int start, int end) { 
    int i, j; 
    for (i = start; i <= end; i++) {
        for (j = start; j < end-i; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]); 
            } 
        } 
    }
} 

/* thread function to sort the array */
void *sortArray(void *threadid) { 
    long tid; 
    tid = (long)threadid; 
    int start = tid * (ARRAY_SIZE/NUM_THREADS);
    int end = (tid+1) * (ARRAY_SIZE/NUM_THREADS) - 1;
    bubbleSort(start, end); 
    printf("Thread %ld finished sorting elements from %d to %d\n", tid, start, end);
    pthread_exit(NULL); 
} 

int main(int argc, char *argv[]) { 
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    // populate array with random numbers
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }
    // create threads to sort the array
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, sortArray, (void *)t);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    // wait for threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    // print out sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    pthread_exit(NULL); 
    return 0; 
}