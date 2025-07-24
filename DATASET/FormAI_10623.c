//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>

void fibonacciSeries(int n) {
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    //Printing the Fibonacci series 
    printf("The Fibonacci Series:\n");
    for(int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int n;

    //take the input for number of terms in Fibonacci series
    printf("Enter the number of terms of Fibonacci series you want to see: ");
    scanf("%d", &n);

    fibonacciSeries(n); //call the Fibonacci Series Function

    return 0;
}