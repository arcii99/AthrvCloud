//FormAI DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include<stdio.h>

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int sum = num1 + num2;
    int diff = num1 - num2;
    int mul = num1 * num2;
    int div = num1 / num2;
    int mod = num1 % num2;
    
    printf("\nSum of %d and %d is %d", num1, num2, sum);
    printf("\nDifference of %d and %d is %d", num1, num2, diff);
    printf("\nProduct of %d and %d is %d", num1, num2, mul);
    printf("\nQuotient of %d and %d is %d", num1, num2, div);
    printf("\nRemainder of %d and %d is %d", num1, num2, mod);
    
    return 0;
}