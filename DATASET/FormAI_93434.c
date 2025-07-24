//FormAI DATASET v1.0 Category: Recursive ; Style: visionary
#include<stdio.h>

int fibonacciRecursive(int n){
    if(n == 0)
        return 0;

    else if(n == 1)
        return 1;
    
    else
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main(){
    int n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The first %d terms of the Fibonacci series are: ", n);

    for(i = 0; i < n; i++){
        printf("%d ", fibonacciRecursive(i));
    }

    return 0;
}