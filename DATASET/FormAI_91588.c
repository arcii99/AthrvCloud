//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

int getFibonacciNumber(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return getFibonacciNumber(n - 1) + getFibonacciNumber(n - 2);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        printf("%d ", getFibonacciNumber(i));
    }

    return 0;
}