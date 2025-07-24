//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include<stdio.h>

int main(){
    int num1, num2, addition, subtraction, multiplication, division, remainder;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    addition = num1 + num2;
    subtraction = num1 - num2;
    multiplication = num1 * num2;
    division = num1 / num2;
    remainder = num1 % num2;
    
    printf("\n%d + %d = %d\n", num1, num2, addition);
    printf("%d - %d = %d\n", num1, num2, subtraction);
    printf("%d * %d = %d\n", num1, num2, multiplication);
    printf("%d / %d = %d\n", num1, num2, division);
    printf("%d %% %d = %d\n", num1, num2, remainder);
    
    return 0;
}