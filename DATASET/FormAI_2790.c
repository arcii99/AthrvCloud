//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

void print_binary(unsigned int num);

int main() {
    unsigned int num1 = 12;     // Binary value: 1100
    unsigned int num2 = 7;      // Binary value: 0111
    
    printf("Bitwise AND operator: %u & %u = %u\n", num1, num2, num1 & num2);     // Bitwise AND operator: 12 & 7 = 4
    print_binary(num1 & num2);      // Binary value: 0100 (4 in decimal)
    
    printf("Bitwise OR operator: %u | %u = %u\n", num1, num2, num1 | num2);      // Bitwise OR operator: 12 | 7 = 15
    print_binary(num1 | num2);      // Binary value: 1111 (15 in decimal)
    
    printf("Bitwise XOR operator: %u ^ %u = %u\n", num1, num2, num1 ^ num2);     // Bitwise XOR operator: 12 ^ 7 = 11
    print_binary(num1 ^ num2);      // Binary value: 1011 (11 in decimal)
    
    printf("Bitwise NOT operator: ~%u = %u\n", num1, ~num1);      // Bitwise NOT operator: ~12 = 4294967283
    print_binary(~num1);        // Binary value: 1111111111111111111111111111011 (4294967283 in decimal)
    
    printf("Left shift operator: %u << 1 = %u\n", num1, num1 << 1);     // Left shift operator: 12 << 1 = 24
    print_binary(num1 << 1);        // Binary value: 11000 (24 in decimal)
    
    printf("Right shift operator: %u >> 1 = %u\n", num1, num1 >> 1);     // Right shift operator: 12 >> 1 = 6
    print_binary(num1 >> 1);        // Binary value: 110 (6 in decimal)
    
    return 0;
}

/*
    Function to print binary representation of unsigned integer
*/
void print_binary(unsigned int num) {
    char bit[32];
    for(int i=0; i<32; i++) {
        bit[i] = (num & (1 << (31-i))) ? '1' : '0';    // Get the bit value (1 or 0)
    }
    printf("Binary value: ");
    for(int i=0; i<32; i++) {
        printf("%c", bit[i]);   // Print the bits
    }
    printf("\n");
}