//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void fill_array(int *arr, int size) {
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int j = i - 1;
        int temp = arr[i];
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int *arr = malloc(SIZE * sizeof(int));
    fill_array(arr, SIZE);
    printf("Before sorting:\n");
    print_array(arr, SIZE);
    insertion_sort(arr, SIZE);
    printf("After sorting:\n");
    print_array(arr, SIZE);
    free(arr);
    return 0;
}