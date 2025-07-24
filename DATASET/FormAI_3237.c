//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to calculate the sum of two numbers
void *calc_sum(void *arg) {
    int *nums = (int *)arg; // Cast the argument to an int array
    int sum = nums[0] + nums[1]; // Calculate the sum
    int *result = malloc(sizeof(int)); // Allocate memory for the result
    *result = sum; // Store the result in the allocated memory
    pthread_exit(result); // Exit the thread and return the result
}

int main() {
    pthread_t tid; // Declare a pthread_t variable to store the thread ID
    int nums[2] = {5, 10}; // Declare an array of ints to store the two numbers
    int *sum; // Declare a pointer to an int to store the result
    pthread_create(&tid, NULL, calc_sum, nums); // Create the thread and pass in the argument
    pthread_join(tid, (void **)&sum); // Wait for the thread to finish and store the result
    printf("The sum of %d and %d is %d\n", nums[0], nums[1], *sum); // Print out the result
    free(sum); // Free the memory allocated for the result
    return 0;
}