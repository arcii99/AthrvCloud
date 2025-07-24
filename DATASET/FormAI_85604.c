//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: beginner-friendly
#include <stdio.h>

int getFibonacci(int n){
    if(n<=1)
        return n;
    return getFibonacci(n-1) + getFibonacci(n-2);
}

void printFibonacci(int n){
    for(int i=0;i<n;i++)
        printf("%d ", getFibonacci(i));
}

void printFibonacciVisual(int n){
    for(int i=0;i<n;i++){
        int num = getFibonacci(i);
        for(int j=0;j<num;j++)
            printf("*");
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter the number of terms in Fibonacci Sequence: ");
    scanf("%d", &n);

    printf("\nFibonacci Sequence:");
    printFibonacci(n);

    printf("\n\nFibonacci Sequence Visual:");
    printFibonacciVisual(n);

    return 0;
}