//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("\n*** WELCOME TO THE ULTIMATE ARITHMETIC ADVENTURE! ***\n\n");
    printf("Are you ready to experience the craziest mathematical operations ever?\n\n");
    
    int num1, num2;
    float num3, num4;
    
    printf("Enter two integers to add, subtract, multiply and divide: ");
    scanf("%d %d", &num1, &num2);
    
    int add = num1 + num2;
    int subtract = num1 - num2;
    int multiply = num1 * num2;
    int divide = num1 / num2;
    
    printf("\nWow! You did an amazing job! Here are your results:\n\n");
    
    printf("%d + %d = %d\n", num1, num2, add);
    printf("%d - %d = %d\n", num1, num2, subtract);
    printf("%d x %d = %d\n", num1, num2, multiply);
    printf("%d / %d = %d\n\n", num1, num2, divide);
    
    printf("Now, let's try with some decimal numbers!\n\n");
    printf("Enter two decimal numbers to add, subtract, multiply and divide: ");
    scanf("%f %f", &num3, &num4);
    
    float add_float = num3 + num4;
    float subtract_float = num3 - num4;
    float multiply_float = num3 * num4;
    float divide_float = num3 / num4;
    
    printf("\nThat was fantastic! Check your results below:\n\n");
    
    printf("%.2f + %.2f = %.2f\n", num3, num4, add_float);
    printf("%.2f - %.2f = %.2f\n", num3, num4, subtract_float);
    printf("%.2f x %.2f = %.2f\n", num3, num4, multiply_float);
    printf("%.2f / %.2f = %.2f\n\n", num3, num4, divide_float);
    
    printf("*** THANK YOU FOR PLAYING! SEE YOU SOON! ***\n\n");
    
    return 0;
}