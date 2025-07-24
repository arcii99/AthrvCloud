//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n);
void quick_sort(int arr[], int low, int high);
void merge_sort(int arr[], int left, int right);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void heap_sort(int arr[], int n);

void populate(int arr[], int n);
void print_array(int arr[], int n);
int is_sorted(int arr[], int n);

int main() {
    int n = 10000;
    int arr[n];

    srand(time(NULL));

    // populate array with random integers
    populate(arr, n);

    printf("Unsorted array:\n");
    print_array(arr, n);

    // measure performance of bubble sort
    clock_t t;
    t = clock();
    bubble_sort(arr, n);
    t = clock() - t;
    double time_taken_bubble = ((double)t) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %f seconds\n", time_taken_bubble);

    // measure performance of quick sort
    t = clock();
    quick_sort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken_quick = ((double)t) / CLOCKS_PER_SEC;
    printf("Quick sort time: %f seconds\n", time_taken_quick);

    // measure performance of merge sort
    t = clock();
    merge_sort(arr, 0, n - 1);
    t = clock() - t;
    double time_taken_merge = ((double)t) / CLOCKS_PER_SEC;
    printf("Merge sort time: %f seconds\n", time_taken_merge);

    // measure performance of insertion sort
    t = clock();
    insertion_sort(arr, n);
    t = clock() - t;
    double time_taken_insertion = ((double)t) / CLOCKS_PER_SEC;
    printf("Insertion sort time: %f seconds\n", time_taken_insertion);

    // measure performance of selection sort
    t = clock();
    selection_sort(arr, n);
    t = clock() - t;
    double time_taken_selection = ((double)t) / CLOCKS_PER_SEC;
    printf("Selection sort time: %f seconds\n", time_taken_selection);

    // measure performance of heap sort
    t = clock();
    heap_sort(arr, n);
    t = clock() - t;
    double time_taken_heap = ((double)t) / CLOCKS_PER_SEC;
    printf("Heap sort time: %f seconds\n", time_taken_heap);

    // check if array is sorted
    printf("Sorted array:\n");
    print_array(arr, n);
    printf("Array is sorted? %s\n", is_sorted(arr, n) ? "Yes" : "No");

    return 0;
}

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
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

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void populate(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i+1]) {
            return 0;
        }
    }
    return 1;
}