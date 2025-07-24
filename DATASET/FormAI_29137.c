//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    printf("Surprise! You are about to see a performance-critical component program!\n");
  
    int n = 10000000,i,j;
    int *array = (int*)malloc(n*sizeof(int));   // Allocating memory for the array
    
    clock_t start,end;
    double time_taken;
    
    printf("Initializing the array with values...\n");
    
    start = clock();
    for (i = 0; i < n; i++) {
        array[i] = rand() % 10000;   // Initializing array with random values (0-9999)
    }
    end = clock();
    
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Array Initialization done in %.2f seconds!\n", time_taken);

    printf("Sorting the array using Bubble sort...\n");

    start = clock();
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Array Sort done in %.2f seconds!\n", time_taken);

    printf("Printing the sorted array...\n");
    for (i = 0; i < n; i++) {
        printf("%d ",array[i]);
    }

    free(array);   // Free the allocated memory
    return 0;
}