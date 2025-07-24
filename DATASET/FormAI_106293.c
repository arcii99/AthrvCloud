//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

int main() {
    int num, first = 0, second = 1, next, count = 0;

    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("\nFibonacci Series: \n");

    while (count < num) {
        if (count <= 1)
            next = count;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        count++;
        printf("%d, ", next);
    }
    return 0;
}