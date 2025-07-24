//FormAI DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000

void init_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    init_array(arr, ARRAY_SIZE);
    printf("Before sorting:\n");
    print_array(arr, ARRAY_SIZE);
    bubble_sort(arr, ARRAY_SIZE);
    printf("After sorting:\n");
    print_array(arr, ARRAY_SIZE);
    return 0;
}