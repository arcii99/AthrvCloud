//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>

// Function to print the Fibonacci sequence
// up to a given number of terms
void fibonacci_sequence(int n)
{
    int first = 0, second = 1, next;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d, ", first);
        }
        else if (i == 1) {
            printf("%d, ", second);
        }
        else {
            next = first + second;
            first = second;
            second = next;
            printf("%d, ", next);
        }
    }
}

// Main function
int main()
{
    int n;
    printf("Enter the number of terms in the Fibonacci sequence to be printed: ");
    scanf("%d", &n);
    printf("The Fibonacci sequence up to %d terms is:\n", n);
    fibonacci_sequence(n);
    return 0;
}