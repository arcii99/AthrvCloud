//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>

// function to generate fibonacci sequence
void fibonacci_sequence(int count) {
    int a = 0, b = 1, sum = 0;

    printf("%d %d ", a, b); // print first two numbers of the sequence

    for (int i = 2; i < count; i++) {
        sum = a + b;
        printf("%d ", sum);
        a = b;
        b = sum;
    }
}

int main() {
    int count;

    printf("Enter the count of fibonacci numbers to generate: ");
    scanf("%d", &count);

    if (count <= 0) { // check for negative count
        printf("Invalid count entered!"); // print error message
    } else {
        printf("Fibonacci Sequence:\n");
        fibonacci_sequence(count); // generate sequence
    }

    return 0;
}