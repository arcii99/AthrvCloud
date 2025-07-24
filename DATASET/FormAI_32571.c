//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ARRAY_SIZE 1000000

void print_array(int array[], int size){
    printf("[");
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i != size-1){
            printf(", ");
        }
    }
    printf("]");
}

void insert_sort(int array[], int size){
    for(int i=1; i<size; i++){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void bubble_sort(int array[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    int array[ARRAY_SIZE];
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++){
        array[i] = rand() % 1000000;
    }

    printf("Array before sorting:\n");
    print_array(array, ARRAY_SIZE);

    struct timeval start_time, end_time;

    // Insertion Sort Benchmarking
    printf("\n\nInsertion Sort:\n");
    gettimeofday(&start_time, NULL);
    insert_sort(array, ARRAY_SIZE);
    gettimeofday(&end_time, NULL);
    printf("Execution time: %f seconds\n", ((double)end_time.tv_sec + (double)end_time.tv_usec/1000000) - ((double)start_time.tv_sec + (double)start_time.tv_usec/1000000));

    printf("Array after sorting:\n");
    print_array(array, ARRAY_SIZE);

    // Bubble Sort Benchmarking
    printf("\n\nBubble Sort:\n");
    gettimeofday(&start_time, NULL);
    bubble_sort(array, ARRAY_SIZE);
    gettimeofday(&end_time, NULL);
    printf("Execution time: %f seconds\n", ((double)end_time.tv_sec + (double)end_time.tv_usec/1000000) - ((double)start_time.tv_sec + (double)start_time.tv_usec/1000000));

    printf("Array after sorting:\n");
    print_array(array, ARRAY_SIZE);

    return 0;
}