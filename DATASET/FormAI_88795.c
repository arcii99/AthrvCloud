//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>

int main() {

    int num1, num2, sum, diff, product, quotient, remainder; //Declared variables
    
    printf("Hello there! I'm your cheerful calculator bot. Let's do some arithmetic!\n");
    printf("First, please enter two numbers: ");
    scanf("%d %d", &num1, &num2); // Input for two numbers
    
    sum = num1 + num2; //Addition
    diff = num1 - num2; //Subtraction
    product = num1 * num2; //Multiplication
    quotient = num1 / num2; //Division
    remainder = num1 % num2; //Modulo
    
    printf("\nGreat job! Here are your results:\n\n");
    printf("  %d + %d = %d\n", num1, num2, sum);
    printf("  %d - %d = %d\n", num1, num2, diff);
    printf("  %d * %d = %d\n", num1, num2, product);
    printf("  %d / %d = %d\n", num1, num2, quotient);
    printf("  %d %% %d = %d\n", num1, num2, remainder);
    
    printf("\nThanks for using my services! Have a great day! :)\n");

    return 0;
}