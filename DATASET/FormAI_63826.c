//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

// Recursive function to calculate the sum of first n natural numbers
int sum(int n) {
    if(n == 0) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

// Main function
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Call the recursive function to calculate the sum of first n natural numbers
    int result = sum(n);

    printf("The sum of first %d natural numbers is %d\n", n, result);
    return 0;
}