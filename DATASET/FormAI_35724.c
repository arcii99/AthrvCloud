//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

/* Statistical Recursive Program Example */

int factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

double mean(int *arr, int size){
    if(size == 0){
        return 0;
    }
    else{
        double sum = *arr + mean(arr+1, size-1) * (size-1);
        double result = (double)sum / size;
        return result;
    }
}

int max(int *arr, int size){
    if(size == 1){
        return *arr;
    }
    else{
        int temp = max(arr+1, size-1);
        if(*arr > temp){
            return *arr;
        }
        else{
            return temp;
        }
    }
}

int main(){
    int arr[5] = {2, 3, 6, 4, 8};
    int n = 5;
    int fact = factorial(n);
    printf("Factorial of %d is: %d\n", n, fact);

    int fib = fibonacci(n);
    printf("Fibonacci number at position %d is: %d\n", n, fib);

    double mean_val = mean(arr, n);
    printf("Mean of the given array is: %.2lf\n", mean_val);

    int max_val = max(arr, n);
    printf("Maximum element of the given array is: %d\n", max_val);

    return 0;
}