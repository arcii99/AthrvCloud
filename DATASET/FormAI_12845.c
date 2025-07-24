//FormAI DATASET v1.0 Category: Benchmarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100000

void randomize_array(int a[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 10000;
    }
}

void reverse_array(int *a, int size) {
    int *start = a;
    int *end = a + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void bubble_sort(int *a, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[MAX_ARRAY_SIZE];
    randomize_array(array, MAX_ARRAY_SIZE);
    clock_t t1 = clock();
    bubble_sort(array, MAX_ARRAY_SIZE);
    clock_t t2 = clock();
    printf("Time taken to sort array using bubble sort: %f seconds\n", (double) (t2 - t1) / CLOCKS_PER_SEC);

    randomize_array(array, MAX_ARRAY_SIZE);
    t1 = clock();
    reverse_array(array, MAX_ARRAY_SIZE);
    t2 = clock();
    printf("Time taken to reverse array: %f seconds\n", (double) (t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}