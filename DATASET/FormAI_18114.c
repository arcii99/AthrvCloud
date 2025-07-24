//FormAI DATASET v1.0 Category: Benchmarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int main() {

    int arr[MAX_SIZE];
    int i, j, temp;
    clock_t t1, t2; // Variables to store time taken by the program
    double bubble_sort_time, selection_sort_time;

    // Initialize array with random values
    srand(time(NULL));
    for(i=0; i<MAX_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Bubble sort
    t1 = clock();
    for(i=0; i<MAX_SIZE-1; i++) {
        for(j=0; j<MAX_SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }   
    }
    t2 = clock();
    bubble_sort_time = (t2-t1) / (double) CLOCKS_PER_SEC;

    // Selection sort
    t1 = clock();
    for(i=0; i<MAX_SIZE-1; i++) {
        int min_index = i;
        for(j=i+1; j<MAX_SIZE; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    t2 = clock();
    selection_sort_time = (t2-t1) / (double) CLOCKS_PER_SEC;

    printf("Bubble Sort Time: %lf\n", bubble_sort_time);
    printf("Selection Sort Time: %lf\n", selection_sort_time);

    return 0;
}