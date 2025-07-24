//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that returns the mean value of an array of integers
double get_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// Function that returns the median value of an array of integers
double get_median(int arr[], int size) {
    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    // If size is odd, return the middle element
    if (size % 2 != 0) {
        return arr[size / 2];
    }
    // If size is even, return the mean of the two middle elements
    return (double) (arr[(size / 2) - 1] + arr[size / 2]) / 2;
}

int main() {
    // Seed the random number generator
    srand(time(0));
    // Generate an array of integers between 0 and 99
    int size = 100;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    // Print out the array
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Calculate the mean and median of the array and print them out
    double mean = get_mean(arr, size);
    printf("Mean: %.2f\n", mean);
    double median = get_median(arr, size);
    printf("Median: %.2f\n", median);
    // Calculate the standard deviation of the array and print it out
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += ((double) arr[i] - mean) * ((double) arr[i] - mean);
    }
    double std_dev = sqrt(sum / size);
    printf("Standard Deviation: %.2f\n", std_dev);
    return 0;
}