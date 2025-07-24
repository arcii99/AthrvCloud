//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: automated
#include <stdio.h>

int main() {
    int num1, num2, sum = 0;
    printf("Enter the first number:");
    scanf("%d", &num1);
    printf("Enter the second number:");
    scanf("%d", &num2);

    for(int i = 1; i <= num2; i++) {
        sum += num1;
    }

    printf("The product of %d and %d is: %d\n", num1, num2, sum);
    return 0;
}