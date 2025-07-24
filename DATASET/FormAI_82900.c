//FormAI DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include<stdio.h>

/*
This program demonstrates a unique example of bitwise operations in C.
The program reads two integers from the user and performs bitwise AND, OR, XOR and Left Shift operations between them.
*/

int main(){
    int num1, num2;

    printf("Enter two integer numbers:\n");
    scanf("%d %d", &num1, &num2);

    printf("\nBitwise AND between %d and %d is: %d\n", num1, num2, num1 & num2);

    printf("Bitwise OR between %d and %d is: %d\n", num1, num2, num1 | num2);

    printf("Bitwise XOR between %d and %d is: %d\n", num1, num2, num1 ^ num2);

    int left_shifted_num = num1 << num2;
    printf("Left shifted %d by %d bits is: %d\n", num1, num2, left_shifted_num);

    return 0;
}