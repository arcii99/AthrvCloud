//FormAI DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>

/**
 * @brief Function to calculate the nth number in the Fibonacci sequence
 * 
 * @param n 
 * @return int 
 */
int fibonacci(int n) {
    if(n <= 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The %dth number in the Fibonacci sequence is: %d\n", n, fibonacci(n));
    return 0;
}