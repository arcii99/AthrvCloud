//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array of random numbers
void generate_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (n * 2); // generating random number between 0 to 2n
    }
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n = 10000;
    int arr[n];

    generate_array(arr, n);

    // Bubble Sort
    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();
    double time_taken_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %lf seconds to execute \n", time_taken_bubble);

    // Selection Sort
    generate_array(arr, n);
    start = clock();
    selection_sort(arr, n);
    end = clock();
    double time_taken_selection = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %lf seconds to execute \n", time_taken_selection);

    // Insertion Sort
    generate_array(arr, n);
    start = clock();
    insertion_sort(arr, n);
    end = clock();
    double time_taken_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %lf seconds to execute \n", time_taken_insertion);

    // Merge Sort
    generate_array(arr, n);
    start = clock();
    merge_sort(arr, 0, n - 1);
    end = clock();
    double time_taken_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort took %lf seconds to execute \n", time_taken_merge);

    return 0;
}