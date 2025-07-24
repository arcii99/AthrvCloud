//FormAI DATASET v1.0 Category: Arithmetic ; Style: content
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
    remainder = num1 % num2;
    
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference of %d and %d is %d\n", num1, num2, difference);
    printf("The product of %d and %d is %d\n", num1, num2, product);
    printf("The quotient of %d and %d is %d\n", num1, num2, quotient);
    printf("The remainder of %d divided by %d is %d\n", num1, num2, remainder);
    
    if(num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else if(num1 < num2) {
        printf("%d is less than %d\n", num1, num2);
    } else {
        printf("%d is equal to %d\n", num1, num2);
    }
    
    return 0;
}