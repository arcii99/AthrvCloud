//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>

void fibonacci(int n)
{
    int fib[n];

    fib[0] = 0;
    fib[1] = 1;

    printf("%d %d ", fib[0], fib[1]);

    for (int i=2; i<n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        printf("%d ", fib[i]);
    }
}

void make_space(int n)
{
    for (int i=0; i<n; i++) {
        printf(" ");
    }
}

void print_stars(int n)
{
    for (int i=0; i<n; i++) {
        printf("* ");
    }
}

void print_lines(int n)
{
    for (int i=0; i<n; i++) {
        printf("\n");
    }
}

void print_fibonacci_visual(int n)
{
    int fib[n];

    fib[0] = 0;
    fib[1] = 1;

    printf("%d %d \n", fib[0], fib[1]);

    int num_spaces = n-2;
    int num_stars = 1;

    for (int i=2; i<n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        make_space(num_spaces);
        print_stars(num_stars);

        printf("\n");

        make_space(num_spaces);
        printf("%d \n", fib[i]);

        num_spaces--;
        num_stars++;
    }
}

int main()
{
    int n = 10;

    printf("The first %d terms of the Fibonacci sequence are: \n", n);
    fibonacci(n);

    printf("\n\nThe Fibonacci sequence in a visual form: \n");
    print_lines(2);
    print_fibonacci_visual(n);

    return 0;
}