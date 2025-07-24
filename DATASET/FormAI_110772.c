//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
/* Statistical Component Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000

/* Function to generate random integers */
void generate_random_integers(int *arr, int size) {
    int i;
    srand(time(NULL));    /* Seed for random number generation */
    for(i = 0; i < size; i++) {
        arr[i] = rand() % 1000; /* Generating random numbers between 0 and 999 */
    }
}

/* Function to calculate the sum of integers in an array */
int calculate_sum(int *arr, int size) {
    int i, sum = 0;
    for(i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

/* Function to calculate the median of integers in an array */
int calculate_median(int *arr, int size) {
    int median;
    if(size % 2 == 0) {
        median = (arr[size/2] + arr[size/2 - 1]) / 2;
    } else {
        median = arr[size/2];
    }
    return median;
}

/* Function to calculate the standard deviation of integers in an array */
float calculate_standard_deviation(int *arr, int size) {
    int i;
    float mean = 0.0, deviation = 0.0, variance = 0.0;
    for(i = 0; i < size; i++) {
        mean += arr[i];
    }
    mean /= size;
    for(i = 0; i < size; i++) {
        variance += (arr[i] - mean) * (arr[i] - mean);
    }
    variance /= size;
    deviation = sqrt(variance);
    return deviation;
}

int main() {
    int arr[SIZE], sum, median;
    float deviation;
    generate_random_integers(arr, SIZE);
    sum = calculate_sum(arr, SIZE);
    median = calculate_median(arr, SIZE);
    deviation = calculate_standard_deviation(arr, SIZE);
    printf("Sum: %d\n", sum);
    printf("Median: %d\n", median);
    printf("Standard Deviation: %f\n", deviation);
    return 0;
}