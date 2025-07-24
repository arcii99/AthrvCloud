//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>

// Define a function that finds the sum of all integers between 1 and n
int sum(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += i;
    }
    return result;
}

int main() {
    printf("Welcome to the Sum Calculator!\n");
    printf("Please enter a positive integer: ");

    int n;
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    int result = sum(n);
    printf("The sum of all integers between 1 and %d is %d.\n", n, result);
    
    return 0;
}