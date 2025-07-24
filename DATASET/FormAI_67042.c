//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    printf("The Fibonacci value for %d is: %d\n", n, fib(n));
    return 0;
}