//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define custom error codes
#define ERROR_NULL_PTR 1
#define ERROR_OUT_OF_BOUNDS 2
#define ERROR_FILE_NOT_FOUND 3

// Define a structure to store errors
typedef struct {
    int code;
    char *message;
} error_t;

// Define a global variable to store errors
error_t global_error = {0, NULL};

// Function to handle errors
void handle_error(error_t error) {
    // Store the error in the global variable
    global_error.code = error.code;
    global_error.message = error.message;
    
    // Print the error message
    printf("Error %d: %s\n", error.code, error.message);
}

// Function to perform some operation
void *do_operation(void *arg) {
    int *arr = (int *) arg;
    int sum = 0;
    
    // Calculate the sum of the array
    for (int i = 0; i < 5; i++) {
        if (arr[i] < 0) {
            // Handle error if number is negative
            handle_error((error_t) {ERROR_OUT_OF_BOUNDS, "Array contains negative number"});
            return NULL;
        }
        sum += arr[i];
    }
    
    printf("Sum of array elements: %d\n", sum);
    
    return NULL;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, -2, 3, 4, 5};
    pthread_t thread1, thread2;
    
    // Create thread 1 to perform operation on array 1
    if (pthread_create(&thread1, NULL, do_operation, arr1) != 0) {
        // Handle error if thread creation fails
        handle_error((error_t) {ERROR_NULL_PTR, "Thread creation failed"});
        return 1;
    }
    
    // Create thread 2 to perform operation on array 2
    if (pthread_create(&thread2, NULL, do_operation, arr2) != 0) {
        // Handle error if thread creation fails
        handle_error((error_t) {ERROR_NULL_PTR, "Thread creation failed"});
        return 1;
    }
    
    // Wait for threads to complete
    if (pthread_join(thread1, NULL) != 0) {
        // Handle error if thread 1 join fails
        handle_error((error_t) {ERROR_NULL_PTR, "Thread join failed"});
    }
    
    if (pthread_join(thread2, NULL) != 0) {
        // Handle error if thread 2 join fails
        handle_error((error_t) {ERROR_NULL_PTR, "Thread join failed"});
    }
    
    // Check if any errors occurred
    if (global_error.code != 0) {
        // Handle global error
        printf("Program exited with error %d: %s\n", global_error.code, global_error.message);
        return 1;
    }
    
    printf("Program executed successfully\n");
    
    return 0;
}