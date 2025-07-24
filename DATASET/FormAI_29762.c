//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>

int main() {
    unsigned char a = 0b11110000;
    unsigned char b = 0b00001111;
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    unsigned char result1 = ~a;
    unsigned char result2 = a & b;
    unsigned char result3 = a | b;
    unsigned char result4 = a ^ b;
    
    printf("~a = %d\n", result1);
    printf("a & b = %d\n", result2);
    printf("a | b = %d\n", result3);
    printf("a ^ b = %d\n", result4);

    unsigned char left_shift_result = a << 2;
    unsigned char right_shift_result = a >> 2;

    printf("a << 2 = %d\n", left_shift_result);
    printf("a >> 2 = %d\n", right_shift_result);

    return 0;
}