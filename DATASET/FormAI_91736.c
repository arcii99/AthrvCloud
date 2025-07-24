//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

// Function to calculate the average of an array of integers
double calculateAverage(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    double avg = (double) sum / len;
    return avg;
}

// Function to calculate the product of an array of integers
long calculateProduct(int arr[], int len) {
    long prod = 1;
    for (int i = 0; i < len; i++) {
        prod *= arr[i];
    }
    return prod;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(int);
    double avg = calculateAverage(arr, len);
    long prod = calculateProduct(arr, len);

    printf("The average of the array is: %lf\n", avg);
    printf("The product of the array is: %ld\n", prod);

    return 0;
}