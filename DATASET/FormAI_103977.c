//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

//function to convert decimal to binary
void decimalToBinary(int num) {
    unsigned int mask = 0x80000000; //set the most significant bit as 1
    printf("%d in binary is: ", num);
    int i;
    for(i = 0; i < 32; i++) {
        if((num & mask) == mask)
            printf("1");
        else
            printf("0");
        mask >>= 1; //right shift the mask by 1
    }
    printf("\n");
}

int main() {
    //bitwise AND operator example
    printf("Bitwise AND Operator Example:\n");
    int a = 5, b = 3;
    int result = a & b;
    printf("%d & %d = %d\n\n", a, b, result);

    //bitwise OR operator example
    printf("Bitwise OR Operator Example:\n");
    a = 5, b = 3;
    result = a | b;
    printf("%d | %d = %d\n\n", a, b, result);

    //bitwise XOR operator example
    printf("Bitwise XOR Operator Example:\n");
    a = 5, b = 3;
    result = a ^ b;
    printf("%d ^ %d = %d\n\n", a, b, result);

    //bitwise NOT operator example
    printf("Bitwise NOT Operator Example:\n");
    a = 5;
    result = ~a;
    printf("~%d = %d\n\n", a, result);

    //bitwise left shift operator example
    printf("Bitwise Left Shift Operator Example:\n");
    a = 5;
    result = a << 2;
    printf("%d << 2 = %d\n", a, result);
    decimalToBinary(a);
    decimalToBinary(result);
    printf("\n");

    //bitwise right shift operator example
    printf("Bitwise Right Shift Operator Example:\n");
    a = 5;
    result = a >> 2;
    printf("%d >> 2 = %d\n", a, result);
    decimalToBinary(a);
    decimalToBinary(result);

    return 0;
}