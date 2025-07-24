//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

int fibonacci(int n) {    
    if (n == 0)    
        return 0;    
    else if (n == 1)    
        return 1;    
    else    
        return fibonacci(n - 1) + fibonacci(n - 2);    
}    

void countDown(int n) {
    if (n == 0) {
        printf("Blast off!\n");
    } else {
        printf("%d\n", n);
        countDown(n-1);
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return base;
    } else {
        return base * power(base, exponent-1);
    }
}

int main() {
    int n = 5;
    printf("Fibonacci sequence for n=%d: ", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\nCountdown from 3: ");
    countDown(3);

    int x = 5;
    printf("%d! = %d\n", x, factorial(x));

    int base = 2, exponent = 5;
    printf("%d^%d = %d\n", base, exponent, power(base, exponent));

    return 0;
}