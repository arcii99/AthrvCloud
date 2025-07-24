//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void initialize_array(int arr[]) {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 1000;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temporary arrays */
    int L[n1], R[n2];
 
    /* Copy data to temporary arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temporary arrays back into arr[l..r]*/
    i = 0; /* Initial index of first subarray */
    j = 0; /* Initial index of second subarray */
    k = l; /* Initial index of merged subarray */
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        /* Sort first and second halves */
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[SIZE];
    clock_t t;
 
    srand(time(NULL)); // Seed random number generator
     
    initialize_array(arr);
    printf("Unsorted array:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
     
    t = clock();
    merge_sort(arr, 0, SIZE - 1);
    t = clock() - t;
 
    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
 
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
 
    printf("Merge sort took %f seconds to execute on an array of size %d\n", time_taken, SIZE);
 
    return 0;
}