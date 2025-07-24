//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num; // the user inputted number
    printf("Enter a number to calculate its Fibonacci sequence: ");
    scanf("%d", &num);
    int result = fibonacci(num);
    printf("The %dth number in the Fibonacci sequence is %d.", num, result);
    return 0;
}