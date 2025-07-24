//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void bubble_sort(int arr[]) {
    int i, j, temp;

    for(i = 0; i < SIZE-1; i++) {
        for(j = 0; j < SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int i, arr[SIZE];

    for(i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    bubble_sort(arr);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");

    for(i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %lf seconds\n", cpu_time_used);

    return 0;
}