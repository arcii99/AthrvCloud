//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

int bitwiseShiftRight(int number, int shiftValue) {
    return number >> shiftValue;
}

int bitwiseShiftLeft(int number, int shiftValue) {
    return number << shiftValue;
}

int bitwiseAND(int number1, int number2) {
    return number1 & number2;
}

int bitwiseOR(int number1, int number2) {
    return number1 | number2;
}

int bitwiseNOT(int number) {
    return ~number;
}

int bitwiseXOR(int number1, int number2) {
    return number1 ^ number2;
}

int main() {

    int n1 = 60;
    int n2 = 55;
    int n3 = 23;
    int shiftValue = 2;

    printf("Bitwise Shift Right of %d >> %d = %d\n", n1, shiftValue, bitwiseShiftRight(n1, shiftValue));
    printf("Bitwise Shift Left of %d << %d = %d\n", n2, shiftValue, bitwiseShiftLeft(n2, shiftValue));
    printf("Bitwise AND of %d & %d = %d\n", n1, n2, bitwiseAND(n1, n2));
    printf("Bitwise OR of %d | %d = %d\n", n1, n3, bitwiseOR(n1, n3));
    printf("Bitwise NOT of %d = %d\n", n2, bitwiseNOT(n2));
    printf("Bitwise XOR of %d ^ %d = %d\n", n3, n2, bitwiseXOR(n3, n2));

    return 0;
}