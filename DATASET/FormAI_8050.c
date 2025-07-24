//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

int main() {
    int array[MAX];
    int temp, i, j;

    srand(time(NULL));  // seed the random number generator

    // fill array with random numbers
    for(i = 0; i < MAX; i++) {
        array[i] = rand() % MAX;
    }

    // print unsorted array
    printf("Unsorted Array:\n");
    for(i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }

    // bubble sort algorithm
    for(i = 0; i < MAX-1; i++) {
        for(j = 0; j < MAX-i-1; j++) {
            if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // print sorted array
    printf("\n\nSorted Array:\n");
    for(i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}