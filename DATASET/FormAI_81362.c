//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

int main() {
    int num1, num2, sum, difference, product, quotient;
  
    printf("Enter two integers separated by a space: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
    quotient = num1 / num2;
  
    printf("\nThe sum of %d and %d is %d.", num1, num2, sum);
    printf("\nThe difference between %d and %d is %d.", num1, num2, difference);
    printf("\nThe product of %d and %d is %d.", num1, num2, product);
    printf("\nThe quotient of %d and %d is %d.", num1, num2, quotient);
  
    return 0;
}