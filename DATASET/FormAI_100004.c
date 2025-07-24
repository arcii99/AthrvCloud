//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

int main() {
    int x = 10;
    int y = 5;
    int z = 2;
    int result;

    // Addition
    result = x + y + z;
    printf("%d + %d + %d = %d\n", x, y, z, result);

    // Subtraction
    result = x - y - z;
    printf("%d - %d - %d = %d\n", x, y, z, result);

    // Multiplication
    result = x * y * z;
    printf("%d * %d * %d = %d\n", x, y, z, result);

    // Division
    result = x / y;
    printf("%d / %d = %d\n", x, y, result);

    // Modulus
    result = x % z;
    printf("%d %% %d = %d\n", x, z, result);

    // Increment
    result = ++x;
    printf("++%d = %d\n", x, result);

    // Decrement
    result = --y;
    printf("--%d = %d\n", y, result);

    // Bitwise AND
    result = x & y;
    printf("%d & %d = %d\n", x, y, result);

    // Bitwise OR
    result = x | y;
    printf("%d | %d = %d\n", x, y, result);

    // Bitwise XOR
    result = x ^ y;
    printf("%d ^ %d = %d\n", x, y, result);

    // Bitwise NOT
    result = ~x;
    printf("~%d = %d\n", x, result);

    // Left shift
    result = x << 1;
    printf("%d << 1 = %d\n", x, result);

    // Right shift
    result = y >> 1;
    printf("%d >> 1 = %d\n", y, result);

    // Logical AND
    result = (x > y) && (y > z);
    printf("(%d > %d) && (%d > %d) = %d\n", x, y, y, z, result);

    // Logical OR
    result = (x > y) || (y < z);
    printf("(%d > %d) || (%d < %d) = %d\n", x, y, y, z, result);

    // Conditional operator
    result = (x > y) ? x : y;
    printf("(%d > %d) ? %d : %d = %d\n", x, y, x, y, result);

    return 0;
}