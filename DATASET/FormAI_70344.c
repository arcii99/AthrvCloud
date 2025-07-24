//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

// This program demonstrates the use of bitwise operations in C
int main() {
    printf("Hey there! Let's have some fun with bitwise operations!\n");

    int a = 14; // 00001110 in binary
    int b = 9; // 00001001 in binary

    // Binary AND Operator &
    int c = a & b; // 00001000
    printf("a & b = %d\n", c);

    // Binary OR Operator |
    int d = a | b; // 00001111
    printf("a | b = %d\n", d);

    // Binary XOR Operator ^
    int e = a ^ b; // 00000111
    printf("a ^ b = %d\n", e);

    // Binary NOT Operator ~
    int f = ~a; // 11110001
    printf("~a = %d\n", f);

    // Binary left shift << Operator
    int g = a << 2; // 00111000
    printf("a << 2 = %d\n", g);

    // Binary right shift >> Operator
    int h = a >> 2; // 00000011
    printf("a >> 2 = %d\n", h);

    printf("That was just the beginning! Let's try something else.\n");

    // Swapping two numbers using bitwise operators
    int x = 10;
    int y = 20;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("After swapping: x = %d, y = %d\n", x, y);

    printf("That was pretty cool, right? Let's do some more.\n");

    // Checking if a number is even or odd using bitwise operators
    int num1 = 7;
    if (num1 & 1) {
        printf("%d is odd\n", num1);
    }
    else {
        printf("%d is even\n", num1);
    }

    printf("I hope you had fun learning about bitwise operations.\n");
    printf("See you next time!\n");
    return 0;
}