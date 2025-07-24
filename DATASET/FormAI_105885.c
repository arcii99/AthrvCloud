//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10	//size of the array to be sorted

int arr[ARRAY_SIZE];	//global array

//function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to perform bubble sort
void* bubbleSort(void *args) {
    int i, j;
    for (i = 0; i < ARRAY_SIZE-1; i++) {
		for (j = 0; j < ARRAY_SIZE-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

//function to perform selection sort
void* selectionSort(void *args) {
    int i, j, min_idx;
    for (i = 0; i < ARRAY_SIZE-1; i++) {
		min_idx = i;
		for (j = i+1; j < ARRAY_SIZE; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		swap(&arr[min_idx], &arr[i]);
	}
}

int main() {
    int i;

    printf("Before sorting: \n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;		//initializing the array with random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    pthread_t thread1, thread2;	//declaring two threads

    //creating threads for bubble sort and selection sort
    pthread_create(&thread1, NULL, bubbleSort, NULL);
    pthread_create(&thread2, NULL, selectionSort, NULL);

    //joining the threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("After sorting: \n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}