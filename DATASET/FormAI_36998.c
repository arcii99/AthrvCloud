//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>

void printFibonacci(int n) {
    int arr[n];
    
    // initialize the first two elements in the sequence
    arr[0] = 0;
    arr[1] = 1;
    
    for (int i = 2; i < n; i++) {
        // compute the next element in the sequence
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    // display the sequence on the screen
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements in the sequence: ");
    scanf("%d", &n);
    
    printf("Fibonacci sequence:\n");
    printFibonacci(n);
    
    return 0;
}