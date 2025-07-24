//FormAI DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

// bitwise AND operation
void bitwise_and(int a, int b) {
    int result = a & b;
    printf("Bitwise AND of %d and %d is %d\n", a, b, result);
}

// bitwise OR operation
void bitwise_or(int a, int b) {
    int result = a | b;
    printf("Bitwise OR of %d and %d is %d\n", a, b, result);
}

// bitwise XOR operation
void bitwise_xor(int a, int b) {
    int result = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n", a, b, result);
}

// bitwise NOT operation
void bitwise_not(int a) {
    int result = ~a;
    printf("Bitwise NOT of %d is %d\n", a, result);
}

// left shift operation
void left_shift(int a, int n) {
    int result = a << n;
    printf("Left shift of %d by %d bits is %d\n", a, n, result);
}

// right shift operation
void right_shift(int a, int n) {
    int result = a >> n;
    printf("Right shift of %d by %d bits is %d\n", a, n, result);
}

// check if a number is even or odd using bitwise AND operation
void even_or_odd(int a) {
    if (a & 1) {
        printf("%d is odd\n", a);
    } else {
        printf("%d is even\n", a);
    }
}

int main() {
    int a = 25;
    int b = 42;

    printf("Performing bitwise operations on %d and %d\n", a, b);

    bitwise_and(a, b);
    bitwise_or(a, b);
    bitwise_xor(a, b);
    bitwise_not(a);
    left_shift(a, 3);
    right_shift(b, 2);
    even_or_odd(a);

    return 0;
}