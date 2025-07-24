//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
/* 
This program aims to demonstrate a recursive function to calculate 
Fibonacci numbers up to a given sequence number.
The Fibonacci sequence is defined by the formula: 
f(n) = f(n-1) + f(n-2)
where f(0) = 0 and f(1) = 1. 
This program will print out the Fibonacci number sequence in a peaceful way!
*/ 

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int sequence;
    printf("Enter the sequence number up to which fibonacci numbers will be generated: ");
    scanf("%d", &sequence);
    printf("The Fibonacci sequence up to sequence number %d is:\n", sequence);
    for (int i = 0; i <= sequence; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}