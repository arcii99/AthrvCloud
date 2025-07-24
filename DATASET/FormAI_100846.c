//FormAI DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    // Determine the number of bits required to represent the decimal number
    int bits = 0;
    int temp = num;
    while (temp > 0) {
        bits++;
        temp /= 2;
    }
    
    char binary[bits+1];
    binary[bits] = '\0'; // Set the last character to null terminator
    
    // Convert the decimal number to binary
    int index = bits - 1;
    while (index >= 0) {
        binary[index] = (num % 2) + '0'; // Convert the remainder to character
        num /= 2;
        index--;
    }
    
    printf("Binary equivalent: %s\n", binary);
    
    return 0;
}