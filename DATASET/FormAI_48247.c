//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>

// function to calculate nth Fibonacci number
int fibonacci(int n) {
    // first two elements of the sequence are hardcoded
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// function to print Fibonacci sequence up to specified term
void print_fibonacci_sequence(int n) {
    printf("Fibonacci sequence up to term %d:\n", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
}

// function to print Fibonacci sequence up to specified value
void print_fibonacci_sequence_up_to(int max_value) {
    printf("Fibonacci sequence up to value %d:\n", max_value);
    int n = 1;
    while (fibonacci(n) <= max_value) {
        printf("%d ", fibonacci(n));
        n++;
    }
    printf("\n");
}

// function to print Fibonacci sequence within specified range
void print_fibonacci_sequence_within_range(int min_value, int max_value) {
    printf("Fibonacci sequence between %d and %d:\n", min_value, max_value);
    int n = 1;
    int current_fibonacci_number = fibonacci(n);
    while (current_fibonacci_number < min_value)
        current_fibonacci_number = fibonacci(++n);
    while (current_fibonacci_number <= max_value) {
        printf("%d ", current_fibonacci_number);
        current_fibonacci_number = fibonacci(++n);
    }
    printf("\n");
}

int main() {
    print_fibonacci_sequence(10);
    print_fibonacci_sequence_up_to(100);
    print_fibonacci_sequence_within_range(50, 200);
    return 0;
}