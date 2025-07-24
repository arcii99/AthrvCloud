//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define NUM_ITERATIONS 100000

void sort_array(int *arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand();
    }

    clock_t t_start = clock();

    for(int i = 0; i < NUM_ITERATIONS; i++){
        sort_array(arr, ARRAY_SIZE);
    }

    clock_t t_end = clock();

    printf("Sorting Array of size %d for %d iterations took %f seconds\n", ARRAY_SIZE, NUM_ITERATIONS, (double)(t_end-t_start)/CLOCKS_PER_SEC);

    return 0;
}