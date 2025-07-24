//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

void printFibonacciSequence(int count) {
    long prev = 0, curr = 1, next;
    for (int i = 0; i < count; i++) {
        printf(" %ld ", curr);
        next = curr + prev;
        prev = curr;
        curr = next;
        if (curr <= prev || curr <= next) {
            printf("Something seems off...\n");
            return;
        }
    }
    printf("That's all folks!\n");
}

int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of terms to display:\n");
    int count;
    scanf("%d", &count);
    if (count <= 0) {
        printf("Invalid input, must be a positive integer.\n");
        return 1;
    }
    printf("Here's the sequence:");
    printFibonacciSequence(count);
    printf("Thank you for using the Fibonacci Sequence Visualizer.\n");
    printf("We hope you are not a hacker...\n");
    return 0;
}