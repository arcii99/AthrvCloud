//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int main() {
    printf("Welcome to the mathematical world of CodeBot!\n");
    
    printf("Please enter two numbers to add:\n");
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2;
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    
    printf("Now let's do some multiplication!\n");
    printf("Please enter two numbers to multiply:\n");
    int num3, num4;
    scanf("%d %d", &num3, &num4);
    int product = num3 * num4;
    printf("The product of %d and %d is %d\n", num3, num4, product);
    
    printf("Wow, we're getting pretty good at this. Let's try something more challenging...\n");
    printf("Please enter a number to divide:\n");
    int dividend;
    scanf("%d", &dividend);
    printf("Now enter a number to divide by:\n");
    int divisor;
    scanf("%d", &divisor);
    if (divisor == 0) {
        printf("Error: cannot divide by zero\n");
    } else {
        int quotient = dividend / divisor;
        int remainder = dividend % divisor;
        printf("%d divided by %d is %d with a remainder of %d\n", dividend, divisor, quotient, remainder);
    }
    
    printf("Let's finish off with some advanced operations...\n");
    int x = 10;
    int y = 5;
    int z = 2;
    int result1 = x + y * z;
    int result2 = (x + y) * z;
    printf("If x = 10, y = 5, and z = 2, what is the result of x + y * z?\n");
    printf("Answer: %d\n", result1);
    printf("What about (x + y) * z?\n");
    printf("Answer: %d\n", result2);
    
    printf("Thanks for playing with numbers today. Goodbye!\n");
    
    return 0;
}