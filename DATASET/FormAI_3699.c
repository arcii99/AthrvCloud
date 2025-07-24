//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        main();     // Energized recursion
    } else {
        int answer = fibonacci(num);
        printf("The %dth Fibonacci number is %d.\n", num, answer);
    }

    return 0;
}