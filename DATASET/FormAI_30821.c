//FormAI DATASET v1.0 Category: Arithmetic ; Style: lively
#include <stdio.h>

int main() {
    int num1, num2, result;
    
    printf("Hey there! Welcome to the magical world of arithmetic!\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    printf("\nLet's perform some magic...\n");
    // Addition
    result = num1 + num2;
    printf("\n%d + %d = %d\n", num1, num2, result);
    
    // Subtraction
    result = num1 - num2;
    printf("%d - %d = %d\n", num1, num2, result);
    
    // Multiplication
    result = num1 * num2;
    printf("%d * %d = %d\n", num1, num2, result);
    
    // Division
    if(num2 != 0) {
        float fresult = (float) num1 / num2;
        printf("%d / %d = %f\n", num1, num2, fresult);
    } else {
        printf("Oops! Cannot divide by zero!\n");
    }
    
    // Modulus
    if(num2 != 0) {
        result = num1 % num2;
        printf("%d %% %d = %d\n", num1, num2, result);
    } else {
        printf("Oops! Cannot calculate modulus of zero!\n");
    }
    
    printf("\nThat was some magic, wasn't it? Come again!\n");
    return 0;
}