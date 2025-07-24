//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main()
{
    int arr[MAX], temp;
    clock_t start, end;

    // generate random numbers and fill the array
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }

    // time the sorting algorithm
    start = clock();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();

    // calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorting %d elements took %f seconds\n", MAX, time_taken);
    
    return 0;
}