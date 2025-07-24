//FormAI DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    printf("\nThe first number is: %d\n", num1);
    printf("The second number is: %d\n", num2);

    result = num1 + num2;
    printf("\nAddition Result: %d\n", result);

    result = num1 - num2;
    printf("Subtraction Result: %d\n", result);

    result = num1 * num2;
    printf("Multiplication Result: %d\n", result);

    if(num2 != 0){
        float divResult = (float) num1 / (float) num2;
        printf("Division Result: %.2f\n", divResult);
    }else{
        printf("Cannot Divide By Zero\n");
    }

    return 0;
}