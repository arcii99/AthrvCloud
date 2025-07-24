//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>

int fibonacci(int num) {
    if (num <= 1) {
        return num;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    int num;

    printf("Enter the number of terms in the Fibonacci sequence you want to generate: ");
    scanf("%d", &num);

    printf("Your Fibonacci sequence:\n");

    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}