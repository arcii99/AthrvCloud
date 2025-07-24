//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int a, b;
    srand((unsigned) time(NULL));
    a = rand() % 100;
    b = rand() % 100;

    printf("The value of a is %d and b is %d.\n\n", a, b);

    printf("The bitwise AND operation between a and b is %d.\n", a & b);
    printf("The bitwise OR operation between a and b is %d.\n", a | b);
    printf("The bitwise XOR operation between a and b is %d.\n\n", a ^ b);

    a >>= 2;
    b <<= 2;

    printf("The value of a after right shifting 2 bits is %d.\n", a);
    printf("The value of b after left shifting 2 bits is %d.\n\n", b);

    if (a == (b >> 2))
    {
        printf("The right shifting and left shifting operations are working correctly as a and (b>>2) are equal.\n");
    }
    else
    {
        printf("The shifting operations are not working correctly as a and (b>>2) are not equal.\n");
    }

    return 0;
}