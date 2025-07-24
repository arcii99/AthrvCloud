//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main(){
    
    int array[MAX_SIZE];
    int index, i, j, temp;
    int n = MAX_SIZE;
    double time_spent;
    
    // Initialize array with random numbers between 1 and 100
    srand(time(NULL)); // Seed using current time
    for (index = 0; index < n; index++){
        array[index] = (rand() % 100) + 1;
    }
    
    // Print unsorted array
    printf("Unsorted Array:\n");
    for (index = 0; index < n; index++){
        printf("%d ", array[index]);
    }
    printf("\n\n");
    
    // Measure time for Bubble Sort
    clock_t begin = clock();
    
    for (i = 0; i < n - 1; i++){ // Traverse through all array elements
        for (j = 0; j < n - i - 1; j++){ // Last i elements are already sorted
            if (array[j] > array[j+1]){ // Swap the elements if the current element is greater than next element
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    clock_t end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC; // Calculate time taken by the Bubble Sort
    
    // Print sorted array
    printf("Sorted Array:\n");
    for (index = 0; index < n; index++){
        printf("%d ", array[index]);
    }
    printf("\n\n");
    
    // Print time taken for Bubble Sort
    printf("Time taken for Bubble Sort: %f seconds\n", time_spent);
    
    return 0;
}