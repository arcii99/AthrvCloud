//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    int num1, num2, result;
    
    printf("Hello and welcome to the peaceful addition program!\n");
    printf("Please enter two numbers to add together:\n");
    scanf("%d %d", &num1, &num2);
    
    result = num1 + num2;
    printf("The sum of %d and %d is %d.\n", num1, num2, result);
    
    printf("Now, let's try some peaceful subtraction...\n");
    printf("Please enter two numbers to subtract:\n");
    scanf("%d %d", &num1, &num2);
    
    result = num1 - num2;
    printf("The difference between %d and %d is %d.\n", num1, num2, result);
    
    printf("Let's move onto some peaceful multiplication...\n");
    printf("Please enter two numbers to multiply:\n");
    scanf("%d %d", &num1, &num2);
    
    result = num1 * num2;
    printf("The product of %d and %d is %d.\n", num1, num2, result);
    
    printf("And finally, some peaceful division...\n");
    printf("Please enter two numbers to divide:\n");
    scanf("%d %d", &num1, &num2);
    
    if (num2 == 0) {
        printf("I'm sorry, we cannot divide by zero.\n");
    }
    else {
        float division_result = (float)num1 / num2;
        printf("The result of %d divided by %d is %.2f.\n", num1, num2, division_result);
    }
    
    printf("Thank you for using the peaceful arithmetic program. Have a peaceful day!\n");
    
    return 0;
}