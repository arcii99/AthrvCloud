//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include<stdio.h>
int main()
{
    printf("****************** Bitwise Operation **********************\n");
    printf("Are you ready to see some magic? Let's manipulate bits using bitwise operators\n");
    printf("Enter two numbers to perform bitwise operations on them\n");

    int num1, num2;
    scanf("%d %d", &num1, &num2);

    int result;
    printf("\nResult of Bitwise AND operation: %d & %d = %d\n", num1, num2, num1 & num2);
    printf("Result of Bitwise OR operation: %d | %d = %d\n", num1, num2, num1 | num2);
    printf("Result of Bitwise XOR operation: %d ^ %d = %d\n", num1, num2, num1 ^ num2);
    printf("Result of Left Shift operation: %d << 1 = %d\n", num1, num1 << 1);
    printf("Result of Right Shift operation: %d >> 1 = %d\n", num1, num1 >> 1);

    printf("\nNow let's swap the numbers using bitwise operators\n");

    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;

    printf("After swapping, num1 = %d and num2 = %d\n", num1, num2);

    printf("\nWasn't that amazing? We just manipulated bits using bitwise operators to perform some cool operations\n");
    printf("Stay tuned for more mind-boggling programming concepts! Bye for now!\n");

    return 0; 
}