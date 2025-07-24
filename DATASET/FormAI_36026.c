//FormAI DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include<stdio.h>

int main()
{
    // bitwise AND
    int a = 12;
    int b = 25;
    int result = a & b;
    printf("a & b = %d\n", result);

    // bitwise OR
    int c = 15;
    int d = 30;
    result = c | d;
    printf("c | d = %d\n", result);

    // bitwise XOR
    int e = 21;
    int f = 16;
    result = e ^ f;
    printf("e ^ f = %d\n", result);

    // bitwise NOT
    int g = 7;
    result = ~g;
    printf("~g = %d\n", result);

    // bitwise left shift
    int h = 10;
    result = h << 2;
    printf("h << 2 = %d\n", result);

    // bitwise right shift
    int i = 40;
    result = i >> 3;
    printf("i >> 3 = %d\n", result);

    return 0;
}