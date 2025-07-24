//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

// Function to calculate the nth Fibonacci number 
unsigned long long fibonacci(unsigned int n) {
    unsigned long long a = 0, b = 1, c;
	
    if (n == 0) {
        return a;
    } else {
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main() {
    unsigned int n;
    printf("Enter a positive integer: ");
    scanf("%u", &n);
    printf("Fibonacci(%d) = %llu\n", n, fibonacci(n));
	
    printf("\n");
    
    printf("Fibonacci Sequence: \n");
    printf("0 ");
    for (int i = 1; i <= n; i++) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");
	
    return 0;
}