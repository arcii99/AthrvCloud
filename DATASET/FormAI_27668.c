//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int i, arr[N];
    double time_taken;

    // generate random array of integers
    srand(time(0));
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    clock_t t;
    t = clock();

    bubbleSort(arr, N);

    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nBubble Sort took %f seconds to execute\n", time_taken);
    return 0;
}