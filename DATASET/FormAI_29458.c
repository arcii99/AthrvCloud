//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    int n, i, a = 0, b = 1, c;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("The Fibonacci Sequence for %d terms is:\n", n);

    for (i = 0; i < n; i++) {
        if (i <= 1)
            c = i;
        else {
            c = a + b;
            a = b;
            b = c;
        }
        printf("%d ", c);
        visualize(c); // Call to visualization function
    }

    printf("\nThank you for using Fibonacci Visualizer!\n");

    return 0;
}

void visualize(int num) {
    int i;
    printf("\n");
    for (i = 0; i < num; i++) {
        printf("* ");
    }
}