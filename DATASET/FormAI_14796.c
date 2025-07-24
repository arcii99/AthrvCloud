//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>

// Function to print binary representation of a number 
void printBinary(unsigned int num) { 
    int binary[32]; 
    int i = 0; 

    // Convert decimal to binary and store in array
    while (num > 0) { 
        binary[i] = num % 2; 
        num = num / 2; 
        i++;
    } 

    // Print binary representation
    for (int j = i - 1; j >= 0; j--) 
        printf("%d", binary[j]);
} 

int main() { 
    unsigned int num1 = 71; // 01000111 - decimal 71
    unsigned int num2 = 129; // 10000001 - decimal 129

    // Bitwise AND
    printf("Bitwise AND: ");
    printBinary(num1 & num2); // 00000001 - decimal 1
    printf("\n");

    // Bitwise OR
    printf("Bitwise OR: ");
    printBinary(num1 | num2); // 11000111 - decimal 199
    printf("\n");

    // Bitwise XOR
    printf("Bitwise XOR: ");
    printBinary(num1 ^ num2); // 11000110 - decimal 198
    printf("\n");

    // Bitwise NOT
    printf("Bitwise NOT 1: ");
    printBinary(~num1); // 10111000 - decimal 184
    printf("\n");
    printf("Bitwise NOT 2: ");
    printBinary(~num2); // 01111110 - decimal 126
    printf("\n");

    // Bitwise left shift
    printf("Bitwise left shift: ");
    printBinary(num1 << 3); // 00111000 - decimal 56
    printf("\n");

    // Bitwise right shift
    printf("Bitwise right shift: ");
    printBinary(num2 >> 4); // 00001000 - decimal 8
    printf("\n");

    return 0; 
}