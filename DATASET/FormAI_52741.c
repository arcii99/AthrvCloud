//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

int recursiveSum(int n) {
    if (n <= 0) { // base case
        return 0;
    } else { // recursive case
        int sum = n + recursiveSum(n-1); // recursive call
        printf("The sum of numbers from 1 to %d is %d\n", n, sum); // output
        return sum;
    }
}

int main() {
    int n;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    
    if (n <= 0) { // input validation
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // exit with error code
    }
    
    int sum = recursiveSum(n);
    printf("The final sum is %d\n", sum);
    
    return 0; // exit with success code
}