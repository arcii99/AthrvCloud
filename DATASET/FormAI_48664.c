//FormAI DATASET v1.0 Category: Recursive ; Style: active
#include <stdio.h>

int recursiveSum(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int result = recursiveSum(n);
    printf("The sum of numbers from 1 to %d is %d", n, result);
    return 0;
}

int recursiveSum(int n) {
    if(n == 0) {
        return 0;
    } else {
        return n + recursiveSum(n-1);
    }
}