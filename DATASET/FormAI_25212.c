//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

// bitwise not operation function
int bitwiseNot(int num) {
    return ~num;
}

// bitwise and operation function
int bitwiseAnd(int num1, int num2) {
    return num1 & num2;
}

// bitwise or operation function
int bitwiseOr(int num1, int num2) {
    return num1 | num2;
}

// bitwise xor operation function
int bitwiseXor(int num1, int num2) {
    return num1 ^ num2;
}

int main() {
    int num1 = 10;
    int num2 = 12;

    printf("Number 1 = %d\n", num1);
    printf("Number 2 = %d\n", num2);

    int notResult = bitwiseNot(num1);
    printf("Not of %d is: %d\n", num1, notResult);

    int andResult = bitwiseAnd(num1, num2);
    printf("And of %d and %d is: %d\n", num1, num2, andResult);

    int orResult = bitwiseOr(num1, num2);
    printf("Or of %d and %d is: %d\n", num1, num2, orResult);

    int xorResult = bitwiseXor(num1, num2);
    printf("Xor of %d and %d is: %d\n", num1, num2, xorResult);

    return 0;
}