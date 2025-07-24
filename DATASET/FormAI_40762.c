//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

int add(int a, int b) {
    if (b == 0) return a;
    return add(a ^ b, (a & b) << 1);
}

int subtract(int a, int b) {
    if (b == 0) return a;
    return subtract(a ^ b, (~a & b) << 1);
}

int multiply(int a, int b) {
    if (b == 1) return a;
    if (b == 0) return 0;
    if (b & 1) return add(a, multiply(a << 1, b >> 1));
    return multiply(a << 1, b >> 1);
}

int divide(int a, int b) {
    if (a < b) return 0;
    int q = 1;
    int temp = b;
    while (temp < a) {
        temp <<= 1;
        q <<= 1;
    }
    if (temp > a) {
        temp >>= 1;
        q >>= 1;
        return add(q, divide(subtract(a, temp), b));
    }
    return q;
}

int main() {
    int a = 10, b = 5;
    printf("Addition of %d and %d is %d\n", a, b, add(a, b));
    printf("Subtraction of %d from %d is %d\n", b, a, subtract(a, b));
    printf("Multiplication of %d and %d is %d\n", a, b, multiply(a, b));
    printf("Division of %d by %d is %d\n", a, b, divide(a, b));
    return 0;
}