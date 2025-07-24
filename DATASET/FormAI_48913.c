//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//function for fibonacci series 
int* fibonacci(int n){

    int* fib = (int*)malloc(sizeof(int)*n);
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib;
}

//function to print asterisks
void printAsterisks(int num){

    for(int i=0; i<num; i++){
        printf("*");
    }

    printf("\n");
}

//function to display fibonacci sequence visualizer
void fibonacciVisualizer(int n){

    int* fib = fibonacci(n);

    for(int i=0; i<n; i++){
        printAsterisks(fib[i]);
    }

    free(fib);
}

//main function
int main(){

    int n;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d",&n);
    fibonacciVisualizer(n);

    return 0;
}