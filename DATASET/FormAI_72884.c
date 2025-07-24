//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selection_sort(int a[], int n) {
    int i, j, temp, min_index;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        temp = a[min_index];
        a[min_index] = a[i];
        a[i] = temp;
    }
}

void insertion_sort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void merge(int a[], int left[], int right[], int nl, int nr) {
    int i = 0, j = 0, k = 0;
    while (i < nl && j < nr) {
        if (left[i] < right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }
    while (i < nl) {
        a[k++] = left[i++];
    }
    while (j < nr) {
        a[k++] = right[j++];
    }
}

void merge_sort(int a[], int n) {
    if (n <= 1) {
        return;
    }
    int mid = n / 2;
    int left[mid], right[n-mid];
    int i;
    for (i = 0; i < mid; i++) {
        left[i] = a[i];
    }
    for (i = mid; i < n; i++) {
        right[i-mid] = a[i];
    }
    merge_sort(left, mid);
    merge_sort(right, n-mid);
    merge(a, left, right, mid, n-mid);
}

void quick_sort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = a[left + (right-left)/2];
    int i = left, j = right;
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(a, left, j);
    quick_sort(a, i, right);
}

void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n = 10000;
    int a[n], b[n], c[n], d[n], e[n];
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++) {
        a[i] = rand() % n;
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
        e[i] = a[i];
    }
    clock_t start, end;
    double time_elapsed;
    start = clock();
    bubble_sort(a, n);
    end = clock();
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f seconds\n", time_elapsed);
    start = clock();
    selection_sort(b, n);
    end = clock();
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f seconds\n", time_elapsed);
    start = clock();
    insertion_sort(c, n);
    end = clock();
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f seconds\n", time_elapsed);
    start = clock();
    merge_sort(d, n);
    end = clock();
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f seconds\n", time_elapsed);
    start = clock();
    quick_sort(e, 0, n-1);
    end = clock();
    time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f seconds\n", time_elapsed);
    return 0;
}