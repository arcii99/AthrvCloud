//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// Function to find the maximum value in the array
int max(int arr[], int n) {
    int max_val = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Function to find the minimum value in the array
int min(int arr[], int n) {
    int min_val = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

// Function to find the mean of the array
float mean(int arr[], int n) {
    float sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    float mean_val = sum / n;
    return mean_val;
}

// Function to find the median of the array
float median(int arr[], int n) {
    float median_val = 0;
    int mid = n/2;
    if(n%2 == 0) {
        median_val = (float)(arr[mid] + arr[mid-1]) / 2;
    }
    else {
        median_val = arr[mid];
    }
    return median_val;
}

int main() {
    // Data array with 10 elements
    int data_arr[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};

    // Calculate the maximum value in the array
    int max_val = max(data_arr, 10);
    printf("Maximum value: %d\n", max_val);

    // Calculate the minimum value in the array
    int min_val = min(data_arr, 10);
    printf("Minimum value: %d\n", min_val);

    // Calculate the mean of the array
    float mean_val = mean(data_arr, 10);
    printf("Mean value: %f\n", mean_val);

    // Calculate the median of the array
    float median_val = median(data_arr, 10);
    printf("Median value: %f\n", median_val);

    return 0;
}