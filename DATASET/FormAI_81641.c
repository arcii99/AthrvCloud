//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    int decimalNum, i=0;
    char binary[32]; // declare the binary string with maximum bits as 32

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    while(decimalNum > 0) { // continue until the decimalNum is greater than 0
        if(decimalNum % 2 == 0) {
            binary[i] = '0'; // store the remainder in binary as 0 if it is even
        }
        else {
            binary[i] = '1'; // store the remainder in binary as 1 if it is odd
        }
        decimalNum /= 2; // integer division by 2 to compute quotient
        i++; // move to the next bit in binary
    }

    printf("\nBinary equivalent is: ");
    for(int j=i-1; j>=0; j--) { // start from the last bit and print all bits in binary string
        printf("%c", binary[j]);
    }
    printf("\n"); // print a newline character after the binary conversion is complete

    return 0;
}