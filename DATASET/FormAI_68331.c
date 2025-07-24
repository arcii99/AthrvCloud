//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    printf("The sum of all even numbers between 1 and %d is %d", n, sum);

    return 0;
}