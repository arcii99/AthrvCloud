//FormAI DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>

// Function to calculate the sum of an integer array
int calculate_sum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Define an array of integers
    int nums[] = {1, 2, 3, 4, 5};

    // Calculate the sum of the elements in the array
    int sum = calculate_sum(nums, 5);

    // Print the sum to the console
    printf("The sum of the integers in the array is: %d\n", sum);

    return 0; // End the program
}