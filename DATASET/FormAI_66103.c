//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void insertion_sort(int arr[]) {
    int i, key, j;
    for (i = 1; i < ARRAY_SIZE; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int i;

    /* Initialize array with random integers between 0 and 100 */
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = rand() % 100;
    }

    /* Calculate the time taken by insertion sort function */
    clock_t t;
    t = clock();
    insertion_sort(arr);
    t = clock() - t;

    /* Print the sorted array and time taken */
    printf("Sorted Array:\n");
    for (i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", ((double) t) / CLOCKS_PER_SEC);
    return 0;
}