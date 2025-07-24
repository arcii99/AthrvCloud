//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int fact(int n) {
    if (n == 0) {   // Base case
        return 1;
    } else {        // Recursive case
        return n * fact(n-1);
    }
}

int main() {
    int num = 5;
    int result = fact(num);
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}