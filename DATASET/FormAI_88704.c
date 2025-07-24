//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void fibonacci_sequence_visualizer(int limit) {
    if (limit == 0 || limit == 1) { // base case
        printf("%d", limit);
        return;
    }
    // initialize arrays to store fibonacci sequence and visualization
    int sequence[limit], visualization[limit];
    sequence[0] = 0, sequence[1] = 1;
    visualization[0] = 0, visualization[1] = 1;
    // generate fibonacci sequence
    for (int i = 2; i < limit; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
    // generate visualization
    for (int i = 2; i < limit; i++) {
        if (sequence[i] % 3 == 0 && sequence[i] % 5 == 0) {
            visualization[i] = 2; // fibonacci number is a multiple of both 3 and 5
        } else if (sequence[i] % 3 == 0) {
            visualization[i] = 1; // fibonacci number is a multiple of 3
        } else if (sequence[i] % 5 == 0) {
            visualization[i] = 3; // fibonacci number is a multiple of 5
        } else {
            visualization[i] = 0; // fibonacci number is not a multiple of 3 or 5
        }
    }
    // print out fibonacci sequence and corresponding visualization
    for (int i = 0; i < limit; i++) {
        if (visualization[i] == 0) {
            printf("%d ", sequence[i]);
        } else if (visualization[i] == 1) {
            printf("Fizz ");
        } else if (visualization[i] == 2) {
            printf("FizzBuzz ");
        } else {
            printf("Buzz ");
        }
    }
}

int main() {
    int limit;
    printf("Enter limit: ");
    scanf("%d", &limit);
    fibonacci_sequence_visualizer(limit);
    return 0;
}