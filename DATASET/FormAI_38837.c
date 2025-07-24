//FormAI DATASET v1.0 Category: Bitwise operations ; Style: light-weight
#include<stdio.h>
#include<stdint.h>

// Function to print unsigned integer in binary format
void printBinary(uint32_t number) {
    for(int i=31; i>=0; i--) {
        if(number & (1u << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    // example variables to perform bitwise operations on
    uint32_t a = 0b01010101, b = 0b10101010, c = 0xDEADBEEF, d = 0xCAFEBABE;

    printf("Initial values of a, b, c, d are: %u, %u, %u, %u\n", a, b, c, d);

    // performing bitwise operations
    uint32_t result1 = a | b;
    uint32_t result2 = c & d;
    uint32_t result3 = ~a;
    uint32_t result4 = b << 8;
    uint32_t result5 = d >> 4;

    printf("a | b = %u\n", result1);
    printf("c & d = %u\n", result2);
    printf("~a = %u\n", result3);
    printf("b << 8 = %u\n", result4);
    printf("d >> 4 = %u\n", result5);

    printf("In binary format, a | b = ");
    printBinary(result1);
    printf("In binary format, c & d = ");
    printBinary(result2);
    printf("In binary format, ~a = ");
    printBinary(result3);
    printf("In binary format, b << 8 = ");
    printBinary(result4);
    printf("In binary format, d >> 4 = ");
    printBinary(result5);

    return 0;
}