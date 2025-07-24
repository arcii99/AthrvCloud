//FormAI DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>

// A recursive function that calculates the factorial of a given number
int fact(int n) {
    if(n == 0 || n == 1) { // base case
        return 1;
    }
    else {
        return n * fact(n-1); // recursive call
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d", num, fact(num));
    return 0;
}