//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

int main()
{
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;
    
    // initialize array with random integers
    int arr[ARRAY_SIZE];
    for(i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % 100;
    }
    
    // print unsorted array
    printf("Unsorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // start clock
    start = clock();
    
    // bubble sort algorithm
    for(i = 0; i < ARRAY_SIZE - 1; i++){
        for(j = 0; j < ARRAY_SIZE - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // end clock
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print sorted array
    printf("Sorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // print time elapsed
    printf("Time elapsed: %f seconds\n", cpu_time_used);
    
    return 0;
}