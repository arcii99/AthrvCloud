//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main() {
    int a = 331;
    int b = 42;
    int result;

    printf("Let's perform some funky bitwise operations!\n\n");

    result = a & b;
    printf("The result of %d & %d is %d\n", a, b, result);

    result = a | b;
    printf("The result of %d | %d is %d\n", a, b, result);

    result = a ^ b;
    printf("The result of %d ^ %d is %d\n", a, b, result);

    printf("Now let's shift some bits:\n\n");

    result = a << 3;
    printf("The result of %d << 3 is %d\n", a, result);

    result = b >> 2;
    printf("The result of %d >> 2 is %d\n", b, result);

    printf("But wait, there's more!\n\n");

    result = ~a;
    printf("The result of ~%d is %d\n", a, result);

    a |= b;
    printf("Now a is %d\n", a);

    b ^= a;
    printf("Now b is %d\n", b);

    printf("That's all folks! Stay bitwise!\n");

    return 0;
}