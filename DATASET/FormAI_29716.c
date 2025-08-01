//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

int fib(int n) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        return (fib(n-1) + fib(n-2));
    }
}

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for(i=0; i<n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");

    return 0;
}