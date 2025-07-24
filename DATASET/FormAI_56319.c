//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, c = 0;
    printf("%d %d ", a, b);
    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

int main() {
    int n, option;
    printf("Welcome to Fibonacci Sequence Visualizer\n");
    while (1) {
        printf("\nPlease enter the number of terms you wish to display: ");
        scanf("%d", &n);
        printf("\n");
        fibonacci(n);
        printf("\nWould you like to continue?\n1 - Yes\n0 - No\n");
        scanf("%d", &option);
        if (option != 1)
            break;
    }
    printf("\nThank you for using Fibonacci Sequence Visualizer\n");
    return 0;
}