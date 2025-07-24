//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void initialize_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

double find_mean(int *arr) {
    double sum = 0.0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    return sum / ARRAY_SIZE;
}

double find_median(int *arr) {
    int middle = (ARRAY_SIZE / 2);
    int temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (ARRAY_SIZE % 2 != 0) {
        return (double)arr[middle];
    } else {
        return (double)(arr[middle-1] + arr[middle]) / 2.0;
    }
}

void print_results(double mean, double median) {
    printf("\nMean: %f", mean);
    printf("\nMedian: %f\n", median);
}

int main() {
    int arr[ARRAY_SIZE];
    double mean, median;
    
    srand(time(NULL)); // Seed for random number generation
    
    initialize_array(arr);
    
    clock_t start = clock();
    mean = find_mean(arr);
    median = find_median(arr);
    print_results(mean, median);
    clock_t end = clock();
    
    // Calculate time taken for benchmarking
    double time_taken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nProgram took %f seconds to execute\n", time_taken);
    
    return 0;
}