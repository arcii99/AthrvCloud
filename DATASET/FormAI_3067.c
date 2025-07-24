//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include<stdio.h>

int main() {
    printf("Hello friend, let's play with some bitwise operations!\n");
    
    int num1 = 10, num2 = 7, num3 = 0;
    
    printf("Let's begin by printing some numbers!\n");
    printf("Num1: %d\n", num1);
    printf("Num2: %d\n", num2);
    printf("Num3: %d\n", num3);

    printf("\nNow, let's see how the AND operator works!\n");
    num3 = num1 & num2;
    printf("Num1 & Num2 = %d\n", num3);

    printf("\nLet's try the OR operator this time!\n");
    num3 = num1 | num2;
    printf("Num1 | Num2 = %d\n", num3);

    printf("\nNow we are going to have fun with the XOR operator!\n");
    num3 = num1 ^ num2;
    printf("Num1 ^ Num2 = %d\n", num3);

    printf("\nNext up is the NOT operator, hold on tight!\n");
    num3 = ~num1; 
    printf("~ Num1 = %d\n", num3);
    num3 = ~num2;
    printf("~ Num2 = %d\n", num3);

    printf("\nNow let's see how the LEFT SHIFT operator works!\n");
    num3 = num1 << 1;
    printf("Num1 << 1 = %d\n", num3);
    num3 = num2 << 2;
    printf("Num2 << 2 = %d\n", num3);

    printf("\nAnd finally, let's try the RIGHT SHIFT operator!\n");
    num3 = num1 >> 1;
    printf("Num1 >> 1 = %d\n", num3);
    num3 = num2 >> 2;
    printf("Num2 >> 2 = %d\n", num3);

    printf("\nHooray! We just played with some awesome bitwise operations in C!\n");
    return 0;
}