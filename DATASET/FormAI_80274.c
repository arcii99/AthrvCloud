//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: \n");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        }
        else {
            next = first + second;
            first = second;
            second = next;
        }

        for (int j = 0; j < next; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}