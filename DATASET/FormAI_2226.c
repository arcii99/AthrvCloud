//FormAI DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>

int main() {
    int x = 47, y = 53, result;

    //Bitwise AND operation
    result = x & y;
    printf("x & y = %d\n", result);

    //Bitwise OR operation
    result = x | y;
    printf("x | y = %d\n", result);

    //Bitwise XOR operation
    result = x ^ y;
    printf("x ^ y = %d\n", result);

    //Bitwise NOT operation
    result = ~x;
    printf("~x = %d\n", result);

    //Left shift operation
    result = x << 2;
    printf("x << 2 = %d\n", result);

    //Right shift operation
    result = y >> 1;
    printf("y >> 1 = %d\n", result);

    return 0;
}