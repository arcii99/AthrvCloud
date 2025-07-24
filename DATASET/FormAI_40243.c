//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int array[N];

void generate_random_numbers() {
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 1000;
    }
}

void bubble_sort() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    generate_random_numbers();

    printf("Unsorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }

    bubble_sort();

    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}