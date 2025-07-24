//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Wooohoooo! Time to run a benchmarking program!!\n\n");

    // Generate an array of random integers
    int array_size = 100000;
    int* array = (int*)malloc(sizeof(int) * array_size);
    printf("Generating a random array of %d integers...\n", array_size);
    srand(time(NULL));
    for (int i = 0; i < array_size; i++) {
        array[i] = rand() % 1000;
    }

    // Sort the array using Bubble Sort
    clock_t start_bubble = clock();
    printf("\nBubble Sorting the array...\n");
    for (int i = 0; i < array_size - 1; i++) {
        for (int j = 0; j < array_size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    printf("Bubble Sort completed in %fs\n", time_bubble);

    // Sort the array using Quick Sort
    clock_t start_quick = clock();
    printf("\nQuick Sorting the array...\n");
    quick_sort(array, 0, array_size - 1);
    clock_t end_quick = clock();
    double time_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;
    printf("Quick Sort completed in %fs\n", time_quick);

    // Sort the array using Merge Sort
    clock_t start_merge = clock();
    printf("\nMerge Sorting the array...\n");
    merge_sort(array, 0, array_size - 1);
    clock_t end_merge = clock();
    double time_merge = (double)(end_merge - start_merge) / CLOCKS_PER_SEC;
    printf("Merge Sort completed in %fs\n", time_merge);

    // Free the allocated memory
    free(array);

    printf("\nHooray! We just completed a benchmarking program!\n");

    return 0;
}

void quick_sort(int array[], int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

int partition(int array[], int left, int right) {
    int pivot = array[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;
    return i + 1;
}

void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_arr[n1], right_arr[n2];
    for (int i = 0; i < n1; i++) {
        left_arr[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        right_arr[i] = array[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            array[k] = left_arr[i];
            i++;
        }
        else {
            array[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = right_arr[j];
        j++;
        k++;
    }
}