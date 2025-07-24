//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
/* A program to calculate the sum of first n natural numbers */

#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of first %d natural numbers is %d", n, sum);

    return 0;
}