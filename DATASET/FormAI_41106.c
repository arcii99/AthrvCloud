//FormAI DATASET v1.0 Category: Bitwise operations ; Style: medieval
#include <stdio.h>

int main() {
    printf("Hark, fellow programmers! Let us delve deep into the arcane arts of bitwise manipulation! \n");

    int num1 = 31; //Declare num1 and num2 as binary numbers
    int num2 = 12;

    printf("\nLo and behold, I present to thee the numbers: \n");
    printf("%d (decimal) which is %o in octal and %x in hexadecimal.\n", num1, num1, num1);
    printf("%d (decimal) which is %o in octal and %x in hexadecimal.\n", num2, num2, num2);

    //Perform bitwise operations on num1 and num2
    int bitwise_and = num1 & num2;
    int bitwise_or = num1 | num2;
    int bitwise_xor = num1 ^ num2;
    int bitwise_not = ~num1;
    int left_shift = num1 << 3;
    int right_shift = num2 >> 2;

    printf("\nBehold! The results of these mystic operations are as follows:\n");
    printf("Bitwise AND of %d and %d is %d\n", num1, num2, bitwise_and);
    printf("Bitwise OR of %d and %d is %d\n", num1, num2, bitwise_or);
    printf("Bitwise XOR of %d and %d is %d\n", num1, num2, bitwise_xor);
    printf("Bitwise NOT of %d is %d\n", num1, bitwise_not);
    printf("Left shift of %d by 3 places is %d\n", num1, left_shift);
    printf("Right shift of %d by 2 places is %d\n", num2, right_shift);

    printf("\nBy the power of bitwise magic, we have arrived at the end of our journey. Until we meet again, farewell, fellow programmers!\n");

    return 0;
}