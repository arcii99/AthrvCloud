//FormAI DATASET v1.0 Category: Benchmarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

// Function to generate random integer values
int random_number(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

// Function to perform benchmark testing
void benchmark_test(int arr[]) {
    clock_t t_start, t_end;
    int temp;

    // Test Case 1: Sorting the array using Bubble Sort Algorithm
    t_start = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    t_end = clock();
    printf("Bubble Sort Algorithm: %lf seconds\n", ((double)(t_end - t_start))/CLOCKS_PER_SEC );

    // Test Case 2: Sorting the array using Selection Sort Algorithm
    t_start = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i+1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    t_end = clock();
    printf("Selection Sort Algorithm: %lf seconds\n", ((double)(t_end - t_start))/CLOCKS_PER_SEC );

    // Test Case 3: Sorting the array using Merge Sort Algorithm
    t_start = clock();
    void merge(int arr[], int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void merge_sort(int arr[], int l, int r) {
        if (l < r) {
            int m = l+(r-l)/2;
            merge_sort(arr, l, m);
            merge_sort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
    merge_sort(arr, 0, ARRAY_SIZE-1);
    t_end = clock();
    printf("Merge Sort Algorithm: %lf seconds\n", ((double)(t_end - t_start))/CLOCKS_PER_SEC );
}

int main(void)
{
    int arr[ARRAY_SIZE];

    // Filling the array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = random_number(0,1000);

    // Performing Benchmark Testing on Sorting Algorithms
    benchmark_test(arr);

    return 0;
}