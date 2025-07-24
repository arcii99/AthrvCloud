//FormAI DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    int sum = num1 + num2;
    printf("The sum of %d and %d is: %d\n", num1, num2, sum);
    
    int difference = num1 - num2;
    printf("The difference of %d and %d is: %d\n", num1, num2, difference);
    
    int product = num1 * num2;
    printf("The product of %d and %d is: %d\n", num1, num2, product);
    
    int quotient = num1 / num2;
    printf("The quotient of %d and %d is: %d\n", num1, num2, quotient);
    
    int remainder = num1 % num2;
    printf("The remainder of %d and %d is: %d\n", num1, num2, remainder);
    
    return 0;
}