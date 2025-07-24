//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n);

int main() {
    int n, fibo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for(int i = 0; i < n; i++) {
        fibo = fibonacci(i);
        printf("%d ", fibo);
    }
    return 0;
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}