//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

void printFibonacciSeries(int n) {
    static int a = 0, b = 1, sum = 0;
    if (n > 0) {
        sum = a + b;
        a = b;
        b = sum;
        printf("%d ", sum);
        printFibonacciSeries(n - 1);
    }
}

int main() {
    int n;
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);
    printf("Fibonacci Series:\n");
    printf("0 1 ");
    printFibonacciSeries(n - 2);
    printf("\n");
    return 0;
}