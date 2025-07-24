//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <limits.h>

int main() {
    int dividend, divisor, quotient, remainder;
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    printf("Enter the divisor: ");
    scanf("%d", &divisor);

    if(divisor == 0) {
        printf("\nError: Division by zero\n");
        return 0;
    }

    quotient = dividend / divisor;
    remainder = dividend % divisor;

    printf("\n\nDividend: %d\nDivisor: %d\nQuotient: %d\nRemainder: %d\n",
           dividend, divisor, quotient, remainder);

    long long temp = (long long) dividend * divisor;
    if(temp > INT_MAX || temp < INT_MIN) {
        printf("\nOverflow detected\n");
        return 0;
    }

    int result = dividend * divisor;
    printf("\nResult of multiplication: %d\n", result);

    int num1, num2, sum;
    printf("\nEnter two numbers to add: ");
    scanf("%d %d", &num1, &num2);

    if((num2 > 0 && num1 > INT_MAX - num2) || (num2 < 0 && num1 < INT_MIN - num2)) {
        printf("\nOverflow detected\n");
        return 0;
    }

    sum = num1 + num2;

    printf("\nSum of %d and %d is: %d\n", num1, num2, sum);

    return 0;
}