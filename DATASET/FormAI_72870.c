//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>

// Function to initialize the array
void initializeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Function to calculate the sum of elements
int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to calculate the product of elements
int calculateProduct(int arr[], int n) {
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    return product;
}

int main() {
    // Initialize the array
    int arr[5];
    initializeArray(arr, 5);

    // Calculate the sum and print it
    int sum = calculateSum(arr, 5);
    printf("The sum of elements is: %d\n", sum);

    // Calculate the product and print it
    int product = calculateProduct(arr, 5);
    printf("The product of elements is: %d\n", product);

    return 0;
}