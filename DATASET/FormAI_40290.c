//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define ITERATIONS 10

void bubbleSort(int arr[], int n) {
   int i, j, temp;
   for (i = 0; i < n-1; i++) {
       for (j = 0; j < n-i-1; j++) {
           if (arr[j] > arr[j+1]) {
               temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
}

double mean(double arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

double stdev(double arr[], int n, double mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / (n - 1));
}

int main() {
    int arr[MAX_SIZE];
    double results[ITERATIONS];
    clock_t start, end;
    double total_time;
    double mean_time, stdev_time;

    srand(time(NULL));
    
    for (int j = 0; j < ITERATIONS; j++) {
        for (int i = 0; i < MAX_SIZE; i++) {
            arr[i] = rand() % MAX_SIZE;
        }
        
        start = clock();
        bubbleSort(arr, MAX_SIZE);
        end = clock();
        
        total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
        results[j] = total_time;
    }

    mean_time = mean(results, ITERATIONS);
    stdev_time = stdev(results, ITERATIONS, mean_time);
    
    printf("Bubble sort on array of %d integers\n", MAX_SIZE);
    printf("Mean runtime over %d iterations: %f seconds\n", ITERATIONS, mean_time);
    printf("Standard deviation of runtime over %d iterations: %f seconds\n", ITERATIONS, stdev_time);
    
    return 0;
}