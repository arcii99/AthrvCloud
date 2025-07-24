//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int recursiveSum(int n) {
    if(n == 0) {
        return 0;
    } else {
        return n + recursiveSum(n-1);
    }
}

int main() {
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);
    int sum = recursiveSum(n);
    printf("The sum of numbers from 1 to %d is %d\n", n, sum);
    return 0;
}