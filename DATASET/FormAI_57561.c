//FormAI DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>

// This program is a future-proof way to calculate the Fibonacci sequence
// It uses a recursive function to calculate the sequence up to a specified number of terms

int fibonacci(int n);

int main() {
    int numTerms;
    printf("How many terms of the Fibonacci sequence would you like to calculate? ");
    scanf("%d", &numTerms);
    
    printf("Here are the first %d terms of the Fibonacci sequence:\n", numTerms);
    
    for(int i=0; i<numTerms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}

int fibonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}