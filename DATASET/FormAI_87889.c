//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal);

// Function to compare two binary numbers
int binaryCompare(int binary1, int binary2);

int main() {
    int a = 15; // 00001111 in binary
    int b = 6; // 00000110 in binary

    int bitwiseAnd = a & b; // 00000110 in binary
    int bitwiseOr = a | b; // 00001111 in binary
    int bitwiseXor = a ^ b; // 00001001 in binary
    int bitwiseLeftShift = a << 2; // 00111100 in binary
    int bitwiseRightShift = a >> 2; // 00000011 in binary
    int bitwiseNot = ~a; // 11110000 in binary

    printf("Bitwise AND: %d\n", bitwiseAnd);
    printf("Bitwise OR: %d\n", bitwiseOr);
    printf("Bitwise XOR: %d\n", bitwiseXor);
    printf("Bitwise Left Shift: %d\n", bitwiseLeftShift);
    printf("Bitwise Right Shift: %d\n", bitwiseRightShift);
    printf("Bitwise NOT: %d\n", bitwiseNot);

    printf("15 in binary is: ");
    decimalToBinary(15);

    printf("6 in binary is: ");
    decimalToBinary(6);

    int compareResult = binaryCompare(1011, 1100); // should return 0, 1011 < 1100
    printf("Comparing 1011 and 1100: %d\n", compareResult);

    compareResult = binaryCompare(1110, 1010); // should return 1, 1110 > 1010
    printf("Comparing 1110 and 1010: %d\n", compareResult);

    return 0;
}

void decimalToBinary(int decimal) {
    int binary[32];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\n");
}

int binaryCompare(int binary1, int binary2) {
    while (binary1 > 0 && binary2 > 0) {
        int bit1 = binary1 % 10;
        int bit2 = binary2 % 10;

        if (bit1 < bit2) {
            return 0;
        } else if (bit1 > bit2) {
            return 1;
        }

        binary1 /= 10;
        binary2 /= 10;
    }

    return -1; // Should never reach this point
}