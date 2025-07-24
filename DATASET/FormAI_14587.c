//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main() {
    int i, j, temp;
    int arr[N];

    // generate random array
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 1000;
    }

    // sort array using bubble sort algorithm
    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print sorted array
    printf("Sorted Array:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}