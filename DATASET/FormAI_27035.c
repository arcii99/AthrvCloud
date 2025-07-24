//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: all-encompassing
#include <stdio.h>

int fibonacci(int num) {
    if (num <= 1) {
        return num;
    }

    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    int num;

    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &num);

    printf("Here is the Fibonacci sequence up to %d terms:\n", num);
    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}