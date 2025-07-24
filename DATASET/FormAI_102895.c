//FormAI DATASET v1.0 Category: Recursive ; Style: high level of detail
#include <stdio.h>

int recursiveFactorial(int num) {
    if(num == 1) { // If num is 1, we return 1
        return 1;
    } else {
        return num * recursiveFactorial(num-1); // Recursive calls itself with num-1
    }
}

void printArray(int arr[], int size) {
    if(size == 0) { // If size is zero, we print nothing
        return;
    } else {
        printf("%d ", arr[size-1]); // Print the last element of the array
        printArray(arr, size-1); // Recursive calls itself with size-1
    }
}

int recursiveFibonacci(int n) {
    if(n == 0) { // If n is 0, return 0
        return 0;
    } else if (n == 1) { // If n is 1, return 1
        return 1;
    } else { // Else return the summation of two previous numbers
        return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
    }
}

int main() {
    int num = 5, factorial; // A variable to store the number and the resulting factorial
    int arr[5] = {1,2,3,4,5}; // An array of 5 integers
    int fibonacci = 6; // Fibonacci to be calculated for the number 6
    
    factorial = recursiveFactorial(num); // Calling the recursive factorial function
    printf("Factorial of %d is %d\n", num, factorial); // Printing the resulting factorial
    
    printf("Elements of array are: ");
    printArray(arr, 5); // Print the array elements using recursive function
    printf("\n");
    
    printf("Fibonacci number at %d is %d\n", fibonacci, recursiveFibonacci(fibonacci)); // Print the fibonacci number
    
    return 0;
}