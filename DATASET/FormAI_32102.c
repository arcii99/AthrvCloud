//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000000

int main() {
    int numbers[MAX_NUMBERS];

    // Generate random numbers
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % MAX_NUMBERS;
    }

    // Bubble sort benchmark
    clock_t start1 = clock();
    for (int i = 0; i < MAX_NUMBERS - 1; i++) {
        for (int j = 0; j < MAX_NUMBERS - i - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    clock_t end1 = clock();
    double time1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("Bubble sort took %f seconds\n", time1);

    // Merge sort benchmark
    clock_t start2 = clock();
    merge_sort(numbers, 0, MAX_NUMBERS - 1);
    clock_t end2 = clock();
    double time2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("Merge sort took %f seconds\n", time2);

    return 0;
}

// Merge sort implementation
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;

        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int temp[MAX_NUMBERS];
    int i = left;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }
}