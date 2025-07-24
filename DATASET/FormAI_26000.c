//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>

int main() {
    int num, i, a = 0, b = 1, c;

    printf("Enter the number of terms to be printed in the Fibonacci Sequence: ");
    scanf("%d", &num);

    printf("\nThe Fibonacci Series:\n");

    for(i = 1; i <= num; i++) {
        printf("%d\t", a);
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}