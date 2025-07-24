//FormAI DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

/* Function to perform bitwise AND operation */
int bitwise_and(int x, int y){
    return x & y;
}

/* Function to perform bitwise OR operation */
int bitwise_or(int x, int y){
    return x | y;
}

/* Function to perform bitwise NOT operation */
int bitwise_not(int x){
    return ~x;
}

/* Function to perform bitwise XOR operation */
int bitwise_xor(int x, int y){
    return x ^ y;
}

/* Function to perform bitwise left shift operation */
int left_shift(int x, int shift){
    return x << shift;
}

/* Function to perform bitwise right shift operation */
int right_shift(int x, int shift){
    return x >> shift;
}

/* Function to perform three-bit swap */
int three_bit_swap(int x){
    return ((x & 0x7) << 3) | ((x & 0x38) >> 3) | (x & 0xC0);
}

int main(){
    int a = 15; // binary 1111
    int b = 47; // binary 101111
    int shift = 2;

    printf("Bitwise AND of %d and %d is %d\n", a, b, bitwise_and(a, b));
    printf("Bitwise OR of %d and %d is %d\n", a, b, bitwise_or(a, b));
    printf("Bitwise NOT of %d is %d\n", a, bitwise_not(a));
    printf("Bitwise XOR of %d and %d is %d\n", a, b, bitwise_xor(a, b));
    printf("Left shift of %d by %d bits is %d\n", a, shift, left_shift(a, shift));
    printf("Right shift of %d by %d bits is %d\n", b, shift, right_shift(b, shift));
    printf("Three-bit swap of %d is %d\n", a, three_bit_swap(a));

    return 0;
}