//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void drawFibonacci(int x) {
    int a = 0, b = 1, c = 0, i;
    printf("Hello, I'm the Fibonacci Happy Bot! Let me show you the %dth numbers of the Fibonacci sequence in a unique way!\n", x);

    for (i = 0; i < x; i++) {
        c = a + b;
        a = b;
        b = c;

        if (c % 3 == 0 && c % 5 == 0) {
            printf("FizzBuzz ");
        } else if (c % 3 == 0) {
            printf("Fizz ");
        } else if (c % 5 == 0) {
            printf("Buzz ");
        } else {
            printf("%d ", c);
        }
        if (i % 10 == 9) {
            printf("\n");
        }
    }
}

int main() {
    int x;
    printf("Please enter a number n to show the n-th numbers of the Fibonacci sequence:\n");
    scanf("%d", &x);

    drawFibonacci(x);
    return 0;
}