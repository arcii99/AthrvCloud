//FormAI DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(array[i] > array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int size = 10000;
    int array[size];
    
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }
    
    clock_t start = clock();
    bubble_sort(array, size);
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Elapsed time: %f seconds\n", elapsed_time);
    
    return EXIT_SUCCESS;
}