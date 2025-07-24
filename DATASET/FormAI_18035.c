//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

// Recursive function to calculate the nth Fibonacci number
// Prints each number in the Fibonacci sequence as it is calculated
int fibonacci(int n)
{
    if (n == 0) {
        printf("The 0th Fibonacci number is 0\n");
        return 0;
    } else if (n == 1) {
        printf("The 1st Fibonacci number is 1\n");
        return 1;
    } else {
        int sum = fibonacci(n-1) + fibonacci(n-2);
        printf("The %dth Fibonacci number is %d\n", n, sum);
        return sum;
    }
}

// Main function to run the program
int main()
{
    int n;

    printf("Please enter an integer n to calculate the nth Fibonacci number: ");
    scanf("%d", &n);

    int result = fibonacci(n);

    printf("The nth Fibonacci number is %d\n", result);

    return 0;
}