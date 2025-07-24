//FormAI DATASET v1.0 Category: Recursive ; Style: ephemeral
#include <stdio.h>

/* This program will recursively calculate the nth number in the Fibonacci sequence. */

int fibonacci(int n) {

    if(n == 0) {                // Base case
        return 0;
    }
    else if(n == 1) {           // Base case
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);  // Recursive call
    }
}

int main() {

    int n = 10;  // Change this value to test different cases

    // Print the first n Fibonacci numbers
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}