//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>

int main() {

    printf("\nWow! Get ready to witness a Fibonacci Sequence Visualizer!\n\n");

    int n, i, first = 0, second = 1, next;

    printf("Enter the number of terms you want to see in the Fibonacci Sequence:\n");
    scanf("%d", &n);

    printf("\nYour Fibonacci Sequence is:\n\n");

    for (i = 0; i < n; i++) {

        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        int j;
        for (j = 0; j < next; j++) {
            printf("🟪 ");
        }

        printf("\n");
    }

    printf("\nHoly cow! You just saw %d terms in the Fibonacci Sequence!\n", n);
    printf("Thank you for using the Fibonacci Sequence Visualizer and have a splendid day!\n");

    return 0;
}