//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main()
{
    int data[ARRAY_SIZE];
    int i, j, temp;
    clock_t t;

    // Generating random numbers and filling array
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        data[i] = rand() % 10001;
    }

    // Sorting using bubble sort algorithm
    t = clock();
    for(i = 0; i < ARRAY_SIZE-1; i++) {
        for(j = 0; j < ARRAY_SIZE-i-1; j++) {
            if(data[j] > data[j+1]) {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    t = clock() - t;

    // Printing sorted array and time taken for sorting
    printf("Sorted Array: ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\nTime taken: %f seconds\n", ((double)t)/CLOCKS_PER_SEC);

    return 0;
}