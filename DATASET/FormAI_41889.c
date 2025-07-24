//FormAI DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include<stdio.h>

int main()
{
    int x = 10, y = 5, z = 2;

    printf("Initial values of x, y and z: x=%d y=%d z=%d\n", x, y, z);

    // performing bitwise AND operation on x, y and z
    x = x & y & z;
    y = y & z;

    printf("After performing bitwise AND operation x, y and z have the following values:\n");
    printf("x=%d y=%d z=%d\n", x, y, z);

    // performing bitwise OR operation on x, y and z
    x = x | y | z;
    y = y | z;

    printf("After performing bitwise OR operation x, y and z have the following values:\n");
    printf("x=%d y=%d z=%d\n", x, y, z);

    // performing bitwise XOR operation on x, y and z
    x = x ^ y ^ z;
    y = y ^ z;

    printf("After performing bitwise XOR operation x, y and z have the following values:\n");
    printf("x=%d y=%d z=%d\n", x, y, z);

    // performing left shift operation on x, y and z
    x = x << 1;
    y = y << 2;
    z = z << 3;

    printf("After performing bitwise left shift operation x, y and z have the following values:\n");
    printf("x=%d y=%d z=%d\n", x, y, z);

    // performing right shift operation on x, y and z
    x = x >> 1;
    y = y >> 2;
    z = z >> 3;

    printf("After performing bitwise right shift operation x, y and z have the following values:\n");
    printf("x=%d y=%d z=%d\n", x, y, z);

    // performing bitwise complement operation on x, y and z
    x = ~x;
    y = ~y;
    z = ~z;

    printf("After performing bitwise complement operation x, y and z have the following values:\n");
    printf("x=%d y=%d z=%d\n", x, y, z);

    return 0;
}