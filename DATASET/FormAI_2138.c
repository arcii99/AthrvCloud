//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// asynchronous function definition
void async_factorial(int n, long long int* result, void (*callback)(long long int)) {
    if (n == 0 || n == 1) {
        *result = 1;
        callback(*result);
    } else {
        long long int temp_result = 0;
        async_factorial(n-1, &temp_result, callback);
        usleep(100000); // introduce some delay to make it look like it's asynchronous
        *result = n * temp_result;
        callback(*result);
    }
}

// callback function definition to print the result
void print_result(long long int result) {
    printf("Result: %lld\n", result);
}

int main() {
    int n = 10;
    long long int result;
    printf("Calculating %d! asynchronously:\n", n);
    async_factorial(n, &result, print_result);
    printf("Main function executing while the asynchronous function runs...\n");
    usleep(5000000); // wait for some time to make sure async function runs to completion
    printf("Main function execution finished.\n");
    return 0;
}