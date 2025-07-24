//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

double average_time = 0.0;

double get_time_difference(struct timespec start, struct timespec end) {
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    return seconds + nanoseconds*1e-9;
}

void generate_random_array(int* arr) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000; 
    }
}

void bubble_sort(int* arr) {
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        for(int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int* arr) {
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_idx = i;
        for(int j = i+1; j < ARRAY_SIZE; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void benchmark_algorithm(char* algorithm_name, void (*sorting_algorithm)(int*) ) {
    struct timespec start, end;
    int array[ARRAY_SIZE];
    generate_random_array(array);
    clock_gettime(CLOCK_REALTIME, &start);
    sorting_algorithm(array);
    clock_gettime(CLOCK_REALTIME, &end);
    double elapsed_time = get_time_difference(start, end);
    average_time += elapsed_time;
    printf("%s took %lf seconds for an array of size %d\n", algorithm_name, elapsed_time, ARRAY_SIZE);
}

int main() {
    srand(time(NULL));
    for(int i = 1; i <= 10; i++) {
        benchmark_algorithm("Bubble sort", bubble_sort);
        benchmark_algorithm("Selection sort", selection_sort);
    }
    average_time /= 20.0;
    printf("The average time for each algorithm was %lf seconds.\n", average_time);
    return 0;
}