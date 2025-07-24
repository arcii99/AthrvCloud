//FormAI DATASET v1.0 Category: Benchmarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    /* Declare variables */
    clock_t start, end;
    double time_taken;
    const int SIZE = 5000000;
    int array[SIZE];
    int i, j, temp;
    
    /* Generate random array */
    srand(time(NULL));
    for(i = 0; i < SIZE; i++){
        array[i] = rand() % 1000;
    }
    
    /* Bubble Sort */
    start = clock();
    for(i = 0; i < SIZE-1; i++){
        for(j = 0; j < SIZE-i-1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", time_taken);
    
    /* Selection Sort */
    start = clock();
    for(i = 0; i < SIZE-1; i++){
        int min_index = i;
        for(j = i+1; j < SIZE; j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Selection Sort Time: %f seconds\n", time_taken);
    
    /* Insertion Sort */
    start = clock();
    for(i = 1; i < SIZE; i++){
        temp = array[i];
        j = i-1;
        while(j >= 0 && array[j] > temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", time_taken);
    
    return 0;
}