//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, product;
    float quotient;
    
    printf("Please enter two integers:\n");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    diff = num1 - num2;
    product = num1 * num2;
    if(num2==0) {
        printf("Cannot divide by zero\n");
    } else {
        quotient = (float)num1 / num2;
        printf("The quotient of %d and %d is: %.2f\n", num1, num2, quotient);
    }
    
    printf("\nThe sum of %d and %d is: %d\n", num1, num2, sum);
    printf("The difference of %d and %d is: %d\n", num1, num2, diff);
    printf("The product of %d and %d is: %d\n", num1, num2, product);
    
    return 0;
}