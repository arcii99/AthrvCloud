//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    printf("Welcome to the math exercise program!\n\n");
    
    int num1, num2, num3, num4, num5;
    float decimal_num1, decimal_num2, decimal_num3, decimal_num4, decimal_num5;
    
    printf("Enter an integer number between 1 and 10: ");
    scanf("%d", &num1);
    printf("Enter a decimal number between -10.0 and 10.0: ");
    scanf("%f", &decimal_num1);
    
    printf("Enter a positive integer number: ");
    scanf("%d", &num2);
    printf("Enter a negative decimal number between -20.0 and 0.0: ");
    scanf("%f", &decimal_num2);
    
    printf("Enter another integer number between 1 and 5: ");
    scanf("%d", &num3);
    printf("Enter a decimal number between 1.0 and 5.0: ");
    scanf("%f", &decimal_num3);
    
    printf("Enter a negative integer number: ");
    scanf("%d", &num4);
    printf("Enter a decimal number between -5.0 and -1.0: ");
    scanf("%f", &decimal_num4);
    
    printf("Enter a positive integer number: ");
    scanf("%d", &num5);
    printf("Enter a decimal number between 2.5 and 5.0: ");
    scanf("%f", &decimal_num5);
    
    int result1 = pow(num1, num3);
    float result2 = fabs(decimal_num2);
    float result3 = pow(decimal_num3, num5);
    float result4 = floor(decimal_num4);
    float result5 = ceil(decimal_num5);
    
    printf("\n\nHere are your results:\n");
    printf("1. %d raised to the power of %d is %d.\n", num1, num3, result1);
    printf("2. The absolute value of %.2f is %.2f.\n", decimal_num2, result2);
    printf("3. %.2f raised to the power of %d is %.2f.\n", decimal_num3, num5, result3);
    printf("4. The floor of %.2f is %.2f.\n", decimal_num4, result4);
    printf("5. The ceiling of %.2f is %.2f.\n", decimal_num5, result5);
    
    return 0;
}