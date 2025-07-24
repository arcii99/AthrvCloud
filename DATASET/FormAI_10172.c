//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include<stdio.h>

int main(){

    unsigned int a = 1337; //10100111001 in binary
    unsigned int b = 420; //110100100 in binary

    unsigned int result = 0;
    
    // Bitwise AND
    result = a & b; // 100000000 in binary
    printf("Bitwise AND: %d\n", result);

    // Bitwise OR
    result = a | b; // 111101111 in binary
    printf("Bitwise OR: %d\n", result);

    // Bitwise XOR
    result = a ^ b; // 110101111 in binary
    printf("Bitwise XOR: %d\n", result);

    // Bitwise Complement
    result = ~a; // 11111111111111111111101110010 in binary
    printf("Bitwise Complement: %d\n", result);

    // Bitwise Left Shift
    result = a << 2; // 1010011100100 in binary
    printf("Bitwise Left Shift: %d\n", result);

    // Bitwise Right Shift
    result = b >> 1; // 11010010 in binary
    printf("Bitwise Right Shift: %d\n", result);

    return 0;
}