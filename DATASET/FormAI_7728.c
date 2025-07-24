//FormAI DATASET v1.0 Category: Benchmarking ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

// Function to calculate the sum of first n natural numbers recursively
int recursive_sum(int n){
    if(n == 1){
        return 1;
    }
    else{
        return n+recursive_sum(n-1);
    }
}

// Function to calculate the sum of first n natural numbers iteratively
int iterative_sum(int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    return sum;
}

int main(){

    int n = 10000000; // Change this value to benchmark for different 'n' values

    clock_t start_time, end_time;

    // Time taken for recursive function
    start_time = clock();
    int recursive_answer = recursive_sum(n);
    end_time = clock();
    double recursive_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Time taken for iterative function
    start_time = clock();
    int iterative_answer = iterative_sum(n);
    end_time = clock();
    double iterative_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Recursive sum: %d\n", recursive_answer);
    printf("Iterative sum: %d\n\n", iterative_answer);

    printf("Time taken for recursive function: %lf seconds\n", recursive_time);
    printf("Time taken for iterative function: %lf seconds\n", iterative_time);

    if(recursive_time < iterative_time){
        printf("\nRecursive function is faster than the Iterative function for n = %d\n", n);
    }
    else{
        printf("\nIterative function is faster than the Recursive function for n = %d\n", n);
    }

    return 0;
}