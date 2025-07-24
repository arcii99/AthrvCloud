//FormAI DATASET v1.0 Category: Funny ; Style: satisfied
#include<stdio.h>

int main(void) {
    int num1, num2, sum;
    
    printf("Hey there, let's do some math!\n");
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    
    printf("Now let's do some multiplication! Enter another number: ");
    int num3;
    scanf("%d", &num3);
    
    int product = sum * num3;
    
    printf("The product of the sum (%d) and %d is %d\n", sum, num3, product);
    
    printf("But let's not forget about division! Enter a divisor: ");
    int divisor;
    scanf("%d", &divisor);
    
    float quotient = (float)product / divisor;
    
    printf("The quotient of %d divided by %d is %.2f\n", product, divisor, quotient);
    
    printf("Now let's see if we can find the remainder! Enter another divisor: ");
    int divisor2;
    scanf("%d", &divisor2);
    
    int remainder = product % divisor2;
    
    printf("The remainder of %d divided by %d is %d\n", product, divisor2, remainder);
    
    printf("Phew, that was a lot of math. Thanks for playing! :)");
    
    return 0;
}