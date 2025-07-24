//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate mean
double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

// Function to calculate median
double median(int arr[], int n) {
    int mid = n / 2;
    double median_num;
    if (n % 2 == 0) {
        median_num = (double) (arr[mid - 1] + arr[mid]) / 2;
    } else {
        median_num = arr[mid];
    }
    return median_num;
}

// Function to calculate mode
int mode(int arr[], int n) {
    int max_count = 0, max_num = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_num = arr[i];
        }
    }
    return max_num;
}

int main() {
    // Reading input from user
    char input_string[100];
    printf("Enter a string of numbers separated by spaces: ");
    fgets(input_string, 100, stdin);

    // Tokenizing the input string and building the integer array
    char *token = strtok(input_string, " ");
    int arr[100], i = 0, n;
    while (token != NULL) {
        arr[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
    n = i;

    // Printing the input array and its length
    printf("Input Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nLength: %d\n", n);

    // Calculating mean, median and mode
    double mean_num = mean(arr, n);
    double median_num = median(arr, n);
    int mode_num = mode(arr, n);

    // Printing the calculated values
    printf("Mean: %.2lf\n", mean_num);
    printf("Median: %.2lf\n", median_num);
    printf("Mode: %d\n", mode_num);

    return 0;
}