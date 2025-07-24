//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>

// Function to print the Fibonacci sequence up to a certain limit with visual representation
void fibonacci_visualizer(int limit)
{
    int prev_num = 0, curr_num = 1, next_num, count = 0;
    printf("%2d: %6d\n", count, curr_num); // print first number
    count++;

    while (curr_num <= limit) {
        // calculate next number
        next_num = prev_num + curr_num;
        prev_num = curr_num;
        curr_num = next_num;

        // print visual representation of Fibonacci sequence
        for (int i = 0; i < curr_num; i++) {
            printf("*");
        }
        printf("\n");

        printf("%2d: %6d\n", count, curr_num);
        count++;
    }
}

int main()
{
    int limit;
    printf("Enter a limit for the Fibonacci sequence: ");
    scanf("%d", &limit);

    printf("\nFibonacci Sequence up to limit %d:\n", limit);
    fibonacci_visualizer(limit);

    return 0;
}