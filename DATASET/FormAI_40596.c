//FormAI DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main()
{
    int i;
    clock_t start, end;
    double cpu_time;
    int arr[ARRAY_SIZE];

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }

    // Linear search for the number 5000
    start = clock();
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == 5000) {
            break;
        }
    }
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Linear search took %f seconds.\n", cpu_time);

    // Binary search for the number 5000
    start = clock();
    int low = 0;
    int high = ARRAY_SIZE - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == 5000) {
            break;
        } else if (arr[mid] < 5000) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Binary search took %f seconds.\n", cpu_time);

    // Selection sort
    start = clock();
    int j, min, temp;
    for (i = 0; i < ARRAY_SIZE-1; i++) {
        min = i;
        for (j = i+1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    end = clock();
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort took %f seconds.\n", cpu_time);

    return 0;
}