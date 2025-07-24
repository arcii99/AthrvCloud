//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int num1, num2, num3, sum;

    printf("Enter three numbers:");
    scanf("%d %d %d", &num1, &num2, &num3);

    sum = num1 + num2 + num3;

    if (sum < 0) {
        printf("The sum is negative.");
    } else {
        printf("The sum is positive.");
    }

    return 0;
}