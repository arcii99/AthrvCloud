//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void fill_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int *arr, int len) {
    int temp;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    srand(time(0));
    fill_array(arr, SIZE);
    clock_t start = clock();
    bubble_sort(arr, SIZE);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array sorted successfully in %f seconds.", time_taken);
    return 0;
}