//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include<stdio.h>

#define N 1000000

int main()
{
    int arr[N], i, j, temp;
    
    // fill the array with random integers
    for (i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }
    
    // display the unsorted array
    printf("Unsorted Array:\n");
    for(i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // perform insertion sort
    for(i = 1; i < N; i++) {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    // display the sorted array
    printf("Sorted Array:\n");
    for(i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}