//FormAI DATASET v1.0 Category: Educational ; Style: realistic
#include <stdio.h>

int fibonacci(int num);

int main() {
    int num, fib;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    fib = fibonacci(num);
    
    printf("The %dth number in the Fibonacci sequence is: %d", num, fib);
    
    return 0;
}

int fibonacci(int num) {
    int prev1 = 0, prev2 = 1, current = 0;
    
    if (num == 0) {
        return prev1;
    } else if (num == 1) {
        return prev2;
    } else {
        for (int i = 2; i <= num; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }
}