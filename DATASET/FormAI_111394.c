//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a number as an arguement.\n");
        exit(1);
    }

    int limit = atoi(argv[1]);

    if (limit <= 0) {
        printf("Please provide a positive number as an arguement.\n");
        exit(1);
    }

    printFibonacci(limit);

    return 0;
}

void printFibonacci(int n) {
    int first = 0, second = 1, next, i;

    for (i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        for (int j = 0; j < next; j++) {
            printf(" ");
        }
        printf("*\n");
    }
}