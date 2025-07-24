//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>

int main() {
    int decimal, binary = 0, base = 1, rem;
    
    printf("Enter a decimal number to convert: ");
    scanf("%d", &decimal);
    
    while (decimal > 0) {
        rem = decimal % 2;
        binary += rem * base;
        base *= 10;
        decimal /= 2;
    }
    
    printf("Binary: %d", binary);
    
    return 0;
}