//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void print_array(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void unexpected_sort(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int random_index = rand() % size;
        int temp = arr[i];
        arr[i] = arr[random_index];
        arr[random_index] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE] = { 5, 9, 2, 7, 1, 4, 3, 8, 6, 0 };
    printf("Original array: ");
    print_array(arr, ARRAY_SIZE);

    printf("Sorting in a random and unexpected way...\n");
    unexpected_sort(arr, ARRAY_SIZE);
    print_array(arr, ARRAY_SIZE);

    return 0;
}