//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main()
{
    int num1, num2, sum, diff, prod, quo, mod;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    mod = num1 % num2;

    printf("SUM: %d\n", sum);
    printf("DIFFERENCE: %d\n", diff);
    printf("PRODUCT: %d\n", prod);
    printf("QUOTIENT: %d\n", quo);
    printf("REMAINDER: %d\n", mod);
    
    printf("\nBut wait, there's more!");
    printf("\nLet's do some crazy bitwise operations:");

    int num3 = ~num1;
    int num4 = num1 | num2;
    int num5 = num1 & num2;
    int num6 = num1 ^ num2;
    int num7 = num2 << 2;
    int num8 = num2 >> 1;

    printf("\nNOT %d: %d", num1, num3);
    printf("\n%d OR %d: %d", num1, num2, num4);
    printf("\n%d AND %d: %d", num1, num2, num5);
    printf("\n%d XOR %d: %d", num1, num2, num6);
    printf("\n%d LEFT SHIFTED BY 2: %d", num2, num7);
    printf("\n%d RIGHT SHIFTED BY 1: %d", num2, num8);
    
    printf("\n\nCan your brain handle all of that arithmetic? Mine can't!");
    
    return 0;
}