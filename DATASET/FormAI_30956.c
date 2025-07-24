//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// function to calculate the nth fibonacci number
int fibonacci(int n) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        int fib_1 = 0, fib_2 = 1, fib_n = 0;
        
        // calculate the nth fibonacci number using a loop
        for(int i = 2; i <= n; i++) {
            fib_n = fib_1 + fib_2;
            fib_1 = fib_2;
            fib_2 = fib_n;
        }
        
        return fib_n;
    }
}

// function to calculate the average of an array of integers
float calculate_average(int arr[], int size) {
    float sum = 0.0, average;
    
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    average = sum / size;
    return average;
}

// main function
int main() {
    int n = 10; // calculate the 10th fibonacci number
    int fib_n;
    
    // calculate the fibonacci number
    fib_n = fibonacci(n);

    printf("The %dth fibonacci number is: %d\n\n", n, fib_n);

    // calculate the average of an array of integers
    int size = 5;
    int arr[] = {10, 20, 30, 40, 50};
    float average = calculate_average(arr, size);

    printf("The average of the array of integers is: %f", average);

    return 0;
}