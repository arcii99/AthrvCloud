//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

// Bitwise OR operation
int bitwise_or(int x, int y) {
    return x | y;
}

// Bitwise AND operation
int bitwise_and(int x, int y) {
    return x & y;
}

// Bitwise XOR operation
int bitwise_xor(int x, int y) {
    return x ^ y;
}

// Bitwise right shift operation
int bitwise_right_shift(int x, int y) {
    return x >> y;
}

// Bitwise left shift operation
int bitwise_left_shift(int x, int y) {
    return x << y;
}

// Helper function to print binary representation of an integer
void print_binary(int num) {
    if (num > 1) {
        print_binary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    int x = 10;  // 1010 in binary
    int y = 6;   // 0110 in binary
    int res;

    printf("x = %d, binary representation: ", x);
    print_binary(x);
    printf("\n");

    printf("y = %d, binary representation: ", y);
    print_binary(y);
    printf("\n");

    // Bitwise OR operation
    res = bitwise_or(x, y);  // 1110 in binary
    printf("bitwise OR of x and y = %d, binary representation: ", res);
    print_binary(res);
    printf("\n");

    // Bitwise AND operation
    res = bitwise_and(x, y);  // 0010 in binary
    printf("bitwise AND of x and y = %d, binary representation: ", res);
    print_binary(res);
    printf("\n");

    // Bitwise XOR operation
    res = bitwise_xor(x, y);  // 1100 in binary
    printf("bitwise XOR of x and y = %d, binary representation: ", res);
    print_binary(res);
    printf("\n");

    // Bitwise right shift operation
    res = bitwise_right_shift(x, 2);  // 0010 in binary
    printf("bitwise right shift of x by 2 bits = %d, binary representation: ", res);
    print_binary(res);
    printf("\n");

    // Bitwise left shift operation
    res = bitwise_left_shift(x, 2);  // 101000 in binary
    printf("bitwise left shift of x by 2 bits = %d, binary representation: ", res);
    print_binary(res);
    printf("\n");

    return 0;
}