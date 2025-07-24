//FormAI DATASET v1.0 Category: Sorting ; Style: retro
#include<stdio.h>
#include<stdlib.h>

void print_array(int arr[], int size) {
    printf("[");
    int i;
    for (i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size-1]);
}

void bubble_sort(int arr[], int size) {
    int i, j;
    int temp;
    for (i = 0 ; i < size - 1; i++) {
        for (j = 0 ; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("After pass %d: ", i+1);
        print_array(arr, size);
    }
}

int main() {
    int arr[] = {23, 16, 13, 12, 31, 7, 45, 37, 0, -5};
    int size = 10;
    printf("Input array: ");
    print_array(arr, size);
    printf("\nSorting using Bubble Sort...\n");
    bubble_sort(arr, size);
    printf("\nOutput array: ");
    print_array(arr, size);
    return 0;
}