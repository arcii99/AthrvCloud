//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10000

void fill_array(int array[]) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        array[i] = rand() % 100;
    }
}

void merge(int array[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int left_array[n1], right_array[n2];

    for (int i = 0; i < n1; i++) {
        left_array[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        right_array[j] = array[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (left_array[i] <= right_array[j]) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int array[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = (left + right) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    merge(array, left, middle, right);
}

int main() {
    int numbers[MAX_NUMBERS];
    fill_array(numbers);

    clock_t t;
    t = clock();
    merge_sort(numbers, 0, MAX_NUMBERS - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");

    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}