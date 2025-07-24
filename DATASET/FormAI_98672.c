//FormAI DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>

int factorial(int num) {
    if(num == 0) {
        return 1;
    }
    else {
        return num * factorial(num-1);
    }
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    if(n < 0) {
        printf("Error: Please enter a non-negative integer.\n");
        return 0;
    }
    int fact = factorial(n);
    printf("The factorial of %d = %d\n", n, fact);
    return 0;
}