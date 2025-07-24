//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main() {
    clock_t start, end;
    double time_taken;
    
    int array[MAX];
    int i, j, temp;
    
    // initialize array with random numbers
    srand(time(NULL));
    for(i = 0; i < MAX; i++) {
        array[i] = rand() % 100;
    }
    
    // bubble sort algorithm
    start = clock();
    for(i = 0; i < MAX-1; i++) {
        for(j = 0; j < MAX-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted array in %.2f seconds:\n", time_taken);
    for(i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}