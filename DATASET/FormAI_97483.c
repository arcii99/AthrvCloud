//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;
    
    printf("BENCHMARKING EXAMPLE PROGRAM:\n");
    
    // Generating random array
    int arr[100000], i, j, temp;
    srand(time(0));
    for(i=0; i<100000; i++)
        arr[i] = rand()%10000;
    
    // Bubble Sort
    start = clock();
    for(i=0; i<99999; i++) {
        for(j=0; j<99999-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by Bubble Sort: %f seconds\n", cpu_time_used);
    
    // Quick Sort
    start = clock();
    quickSort(arr, 0, 99999);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Quick Sort: %f seconds\n", cpu_time_used);
    
    // Binary Search
    start = clock();
    binarySearch(arr, 0, 99999, 5000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Binary Search: %f seconds\n", cpu_time_used);
    
    return 0;
}

void quickSort(int* arr, int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

int partition(int* arr, int start, int end) {
    int pivot = arr[end];
    int i = start-1, j, temp;
    for(j=start; j<=end-1; j++) {
        if(arr[j] < pivot) {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i+1;
}

void binarySearch(int* arr, int start, int end, int key) {
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        
        if(arr[mid] == key) {
            printf("Element found at index %d.\n", mid);
            return;
        } else if(arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    printf("Element not found in the array.\n");
}