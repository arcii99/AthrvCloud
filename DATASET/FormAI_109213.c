//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10000000 // 10 million elements

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i=1;i<n;i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int* arr, i;
    arr = malloc(LENGTH*sizeof(int)); // dynamically allocate array
    srand(time(NULL)); // seed random number generator
    for(i=0;i<LENGTH;i++) {
        arr[i] = rand()%100; // fill array with random integers in range [0,100)
    }
    clock_t t;
    double time_taken;
    t = clock();
    insertion_sort(arr, LENGTH);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("Sorting %d elements took %lf seconds.\n", LENGTH, time_taken);
    free(arr); // free dynamically allocated memory
    return 0;
}