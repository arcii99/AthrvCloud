//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000000
#define MAX_VALUE 1000000

int arr[ARRAY_SIZE];

void fillArray() {
    int i;
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    fillArray();

    clock_t start = clock();

    qsort(arr, ARRAY_SIZE, sizeof(int), compare);

    clock_t end = clock();

    printf("Total time taken = %f seconds", ((double)(end - start) / CLOCKS_PER_SEC));

    return 0;
}