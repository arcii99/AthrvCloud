//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

int sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n-1);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid input!");
        return 1;
    }
    int s = sum(n);
    printf("Sum of first %d positive integers is %d", n, s);
    return 0;
}