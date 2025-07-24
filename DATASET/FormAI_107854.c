//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

int recursive_function(int n) {
    static int counter = 0;
    printf("Iteration %d: n = %d\n", ++counter, n);
    if (n == 0) {
        return 1;
    } else {
        return n * recursive_function(n-1);
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Calculating factorial of %d...\n", number);
    int result = recursive_function(number);
    printf("Factorial of %d is %d\n", number, result);
    return 0;
}