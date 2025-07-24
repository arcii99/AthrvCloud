//FormAI DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>

/* Recursive function to calculate the sum of numbers from 1 to n */
int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("The sum of numbers from 1 to %d is %d.\n", num, sum(num));
    return 0;
}