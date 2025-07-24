//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

// Function to print Fibonacci sequence up to given input
void fibonacci_sequence(unsigned long long int n)
{
    unsigned long long int num1 = 0, num2 = 1, temp;
    unsigned long long int i;

    printf("Fibonacci Sequence up to %llu:\n", n);

    // Print first two numbers of the sequence
    printf("%llu, %llu, ", num1, num2);

    // Generate and print remaining terms of the sequence
    for (i = 2; i < n; i++) {
        temp = num1 + num2;
        printf("%llu, ", temp);
        num1 = num2;
        num2 = temp;
    }
}

int main()
{
    unsigned long long int input_num;

    printf("Enter a number: ");
    scanf("%llu", &input_num);

    // Call the Fibonacci sequence function
    if (input_num > 0) {
        fibonacci_sequence(input_num);
    } else {
        printf("Invalid input! Enter a positive integer.");
        return 1;
    }

    return 0;
}