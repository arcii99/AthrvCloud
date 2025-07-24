//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

int sum(int n);

int main() {
    int n, res;

    printf("Enter a number: ");
    scanf("%d", &n);

    res = sum(n);

    printf("The sum of the first %d natural numbers is %d.\n", n, res);

    return 0;
}

int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n-1);
    }
}