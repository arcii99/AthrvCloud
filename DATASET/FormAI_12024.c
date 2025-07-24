//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>

int main() {
    int n, t1 = 0, t2 = 1, nextTerm;

    printf("====================\n");
    printf("FIBONACCI SEQUENCE\n");
    printf("====================\n");

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence: ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        if (i % 10 == 0) { //line break every 10th number
            printf("\n");
        }
    }

    printf("\n\nThank you for using Fibonacci Sequence Visualizer! Have a great day!");

    return 0;
}

/*
OUTPUT:
====================
FIBONACCI SEQUENCE
====================
Enter the number of terms: 20
Fibonacci Sequence: 0 1 1 2 3 5 8 13 21 34
55 89 144 233 377 610 987 1597 2584 4181

Thank you for using Fibonacci Sequence Visualizer! Have a great day!
*/