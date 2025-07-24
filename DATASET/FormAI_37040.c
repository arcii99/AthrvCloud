//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

int add(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return add(num1 ^ num2, (num1 & num2) << 1);
    }
}

int subtract(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return subtract(num1 ^ num2, (~num1 & num2) << 1);
    }
}

int multiply(int num1, int num2) {
    if (num2 < 0) {
        return -multiply(num1, -num2);
    } else if (num2 == 0) {
        return 0;
    } else {
        return add(num1, multiply(num1, num2 - 1));
    }
}

int power(int base, int exponent) {
    if (exponent < 0) {
        return -1;
    } else if (exponent == 0) {
        return 1;
    } else {
        return multiply(base, power(base, exponent - 1));
    }
}

int main() {
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    printf("Addition: %d\n", add(num1, num2));
    printf("Subtraction: %d\n", subtract(num1, num2));
    printf("Multiplication: %d\n", multiply(num1, num2));
    printf("Power: %d\n", power(num1, num2));
    return 0;
}