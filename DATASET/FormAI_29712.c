//FormAI DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the arrays to be sorted
#define MAX_SIZE 50000

// Structure to store the benchmark statistics
typedef struct {
    double best_time;
    double worst_time;
    double average_time;
    double total_time;
} BenchmarkStats;

// Function to generate a random array of integers of a given size
void generate_random_array(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000;
    }
}

// Function to print an array of integers
void print_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on an array of integers
void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform selection sort on an array of integers
void selection_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

// Function to perform insertion sort on an array of integers
void insertion_sort(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform quick sort on an array of integers
void quick_sort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[right]);

        int pivot_index = i + 1;

        quick_sort(arr, left, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, right);
    }
}

// Function to perform merge sort on an array of integers
void merge_sort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        for (i = 0; i < n1; ++i) {
            L[i] = arr[left + i];
        }
        for (j = 0; j < n2; ++j) {
            R[j] = arr[mid + 1 + j];
        }

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                ++i;
            } else {
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = L[i];
            ++i;
            ++k;
        }
        while (j < n2) {
            arr[k] = R[j];
            ++j;
            ++k;
        }
    }
}

// Function to run a given sorting function on a randomly generated array of integers
double run_benchmark(void (*sort_func)(int*, int), int size) {
    int arr[MAX_SIZE];
    generate_random_array(arr, size);

    clock_t start_time = clock();
    (*sort_func)(arr, size);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return elapsed_time;
}

// Function to run the benchmark for a given sorting function and a given array size
BenchmarkStats benchmark_sort(void (*sort_func)(int*, int), int size, int num_runs) {
    BenchmarkStats stats;
    stats.best_time = 1000.0;
    stats.worst_time = 0.0;
    stats.total_time = 0.0;

    for (int i = 0; i < num_runs; ++i) {
        double elapsed_time = run_benchmark(sort_func, size);
        stats.total_time += elapsed_time;

        if (elapsed_time < stats.best_time) {
            stats.best_time = elapsed_time;
        }
        if (elapsed_time > stats.worst_time) {
            stats.worst_time = elapsed_time;
        }
    }

    stats.average_time = stats.total_time / num_runs;

    return stats;
}

int main() {
    printf("Welcome to the shape-shifting benchmark program!\n");

    int array_size = 10000;
    int num_runs = 5;

    printf("Benchmarking bubble sort...\n");
    BenchmarkStats bubble_stats = benchmark_sort(&bubble_sort, array_size, num_runs);
    printf("Best time: %f\n", bubble_stats.best_time);
    printf("Worst time: %f\n", bubble_stats.worst_time);
    printf("Average time: %f\n", bubble_stats.average_time);

    printf("Benchmarking selection sort...\n");
    BenchmarkStats selection_stats = benchmark_sort(&selection_sort, array_size, num_runs);
    printf("Best time: %f\n", selection_stats.best_time);
    printf("Worst time: %f\n", selection_stats.worst_time);
    printf("Average time: %f\n", selection_stats.average_time);

    printf("Benchmarking insertion sort...\n");
    BenchmarkStats insertion_stats = benchmark_sort(&insertion_sort, array_size, num_runs);
    printf("Best time: %f\n", insertion_stats.best_time);
    printf("Worst time: %f\n", insertion_stats.worst_time);
    printf("Average time: %f\n", insertion_stats.average_time);

    printf("Benchmarking quick sort...\n");
    BenchmarkStats quick_stats = benchmark_sort(&quick_sort, array_size, num_runs);
    printf("Best time: %f\n", quick_stats.best_time);
    printf("Worst time: %f\n", quick_stats.worst_time);
    printf("Average time: %f\n", quick_stats.average_time);

    printf("Benchmarking merge sort...\n");
    BenchmarkStats merge_stats = benchmark_sort(&merge_sort, array_size, num_runs);
    printf("Best time: %f\n", merge_stats.best_time);
    printf("Worst time: %f\n", merge_stats.worst_time);
    printf("Average time: %f\n", merge_stats.average_time);

    printf("Thanks for using the shape-shifting benchmark program!\n");
    return 0;
}