//FormAI DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>

// This function takes in an integer and returns its factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) { // Base case
        return 1;
    }
    else {
        return n * factorial(n-1); // Recursive call
    }
}

// Driver function to test the recursive factorial function
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Negative integers not allowed!");
        return 0;
    }
    
    printf("%d! = %llu", num, factorial(num));

    return 0;
}