//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int size) {
    int temp = 0;
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size) {
    int min_idx;
    for(int i = 0; i < size-1; i++) {
        min_idx = i;
        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    srand(time(NULL));
    int size = 10;
    int arr[size];
    printf("Unsorted array: ");
    for(int i = 0; i < size; i++) {
        arr[i] = rand()%100; // random value from 0 to 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, size);
    printf("Bubble sort: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    srand(time(NULL)); // reset seed for random value
    printf("Unsorted array: ");
    for(int i = 0; i < size; i++) {
        arr[i] = rand()%100; // random value from 0 to 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort(arr, size);
    printf("Selection sort: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}