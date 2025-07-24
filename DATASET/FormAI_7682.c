//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
    // Bitwise AND Operation
    int a = 15, b = 7, result; 
    result = a & b;
    printf("%d & %d = %d\n", a, b, result);
  
    // Bitwise OR Operation
    int x = 20, y = 10, res; 
    res = x | y;
    printf("%d | %d = %d\n", x, y, res);

    // Bitwise XOR Operation
    int p = 5, q = 12, result_XOR; 
    result_XOR = p ^ q;
    printf("%d ^ %d = %d\n", p, q, result_XOR);

    // Bitwise NOT Operation
    int r = 25, result_NOT; 
    result_NOT = ~r;
    printf(" ~%d = %d\n", r, result_NOT);

    // Bitwise Left Shift Operation
    int num = 4, res_leftShift; 
    res_leftShift = num << 2;
    printf("%d << 2 = %d\n", num, res_leftShift);

    // Bitwise Right Shift Operation
    int m = 13, res_rightShift; 
    res_rightShift = m >> 1;
    printf("%d >> 1 = %d\n", m, res_rightShift);

    return 0;
}