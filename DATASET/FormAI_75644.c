//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>

int factorial(int n) {
    if(n == 0 || n == 1)
        return 1;
    
    return n * factorial(n-1);
}

int fibonacci(int n) {
    if(n == 0) 
        return 0;
    if(n == 1)
        return 1;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("%d! = %d\n", num, factorial(num));
    printf("Fibonacci of %d = %d\n", num, fibonacci(num));
    
    return 0;
}