//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include<stdio.h>

int main(){
    int num1 = 10, num2 = 7;
    int andResult = num1 & num2;
    int orResult = num1 | num2;
    int xorResult = num1 ^ num2;
    int notResult1 = ~num1;
    int notResult2 = ~num2;
    int leftShiftResult = num1 << 2;
    int rightShiftResult = num2 >> 1;

    printf("Num1 = %d, Num2 = %d\n\n", num1, num2);
    printf("Num1 AND Num2: %d\n", andResult);
    printf("Num1 OR Num2: %d\n", orResult);
    printf("Num1 XOR Num2: %d\n", xorResult);
    printf("NOT Num1: %d\n", notResult1);
    printf("NOT Num2: %d\n", notResult2);
    printf("Num1 shifted left by 2: %d\n", leftShiftResult);
    printf("Num2 shifted right by 1: %d\n", rightShiftResult);

    return 0;
}