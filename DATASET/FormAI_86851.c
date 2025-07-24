//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

// recursive function to calculate factorial
int fact(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return n * fact(n-1);
    }
}

// main function
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Factorial of %d is %d\n", number, fact(number));
    return 0;
}